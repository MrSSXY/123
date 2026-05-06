#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/search/kdtree.h>
#include <pcl/search/impl/kdtree.hpp>

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/PoseStamped.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/String.h>
#include <Eigen/Eigen>
#include <math.h>
#include <random>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace Eigen;

enum ObstacleType { BOX, CYLINDER, SPHERE };

struct StaticObstacle {
  Vector3d position;
  Vector3d size;
  ObstacleType type;
  int id;
};

struct DynamicObstacle {
  Vector3d position;
  Vector3d velocity;
  Vector3d size;
  ObstacleType type;
  double phase;
  double frequency;
  Vector3d amplitude;
  Vector3d center;
  int id;
  
  // 圆形轨迹相关变量
  Vector3d circle_center;  // 圆形轨迹的中心点
  double circle_radius;  // 圆形轨迹的半径
  double current_angle;  // 当前角度
  double angular_speed;  // 角速度
  double speed;  // 线速度
};

ros::Publisher _all_map_pub;
ros::Publisher _all_ground_pub;
ros::Publisher _obstacle_poses_pub;
ros::Publisher _obstacle_markers_pub;
ros::Publisher _static_obstacle_markers_pub;
ros::Subscriber _odom_sub;

int _obs_num, _cir_num;
double _x_size, _y_size, _z_size, _init_x, _init_y, _resolution, _sense_rate;
double _x_l, _x_h, _y_l, _y_h, _w_l, _w_h, _h_l, _h_h, _w_c_l, _w_c_h;
std::string map_frame_name;

bool _has_odom = false;
bool _ground_map_swt = false;
bool _dynamic_obstacles_enabled = false;
double _dynamic_update_rate = 2.0;
int _dynamic_obstacles_num = 1;

vector<StaticObstacle> static_obstacles;
vector<DynamicObstacle> dynamic_obstacles;
double current_time = 0.0;

sensor_msgs::PointCloud2 globalMap_pcd;
sensor_msgs::PointCloud2 globalGround_pcd;
pcl::PointCloud<pcl::PointXYZ> cloudMap;
pcl::PointCloud<pcl::PointXYZ> staticCloudMap;

pcl::search::KdTree<pcl::PointXYZ> kdtreeMap;
vector<int> pointIdxSearch;
vector<float> pointSquaredDistance;

void generateBoxObstacle(const Vector3d& center, const Vector3d& size, pcl::PointCloud<pcl::PointXYZ>& cloud)
{
  double resolution = _resolution * 0.5;  // 使用更密集的分辨率
  int x_num = ceil(size[0] / resolution);
  int y_num = ceil(size[1] / resolution);
  int z_num = ceil(size[2] / resolution);
  
  pcl::PointXYZ pt;
  for (int i = -x_num/2; i < x_num/2; i++) {
    for (int j = -y_num/2; j < y_num/2; j++) {
      for (int k = 0; k < z_num; k++) {
        pt.x = center[0] + i * resolution + 0.001;
        pt.y = center[1] + j * resolution + 0.001;
        pt.z = k * resolution * 0.5 + 0.001;  // 从地面开始，高度与Marker匹配
        cloud.points.push_back(pt);
      }
    }
  }
}

void generateCylinderObstacle(const Vector3d& center, double radius, double height, pcl::PointCloud<pcl::PointXYZ>& cloud)
{
  double resolution = _resolution * 0.5;  // 使用更密集的分辨率
  int r_num = ceil(radius / resolution);
  int z_num = 2 * ceil(height / resolution);  // 2倍，使点云高度与Marker匹配
  
  pcl::PointXYZ pt;
  for (int i = -r_num; i <= r_num; i++) {
    for (int j = -r_num; j <= r_num; j++) {
      double dist = sqrt(i*i + j*j) * resolution;
      if (dist <= radius) {
        for (int k = 0; k < z_num; k++) {
          pt.x = center[0] + i * resolution + 0.001;
          pt.y = center[1] + j * resolution + 0.001;
          pt.z = k * resolution + 0.001;  // 从地面开始，高度与3D模型匹配
          cloud.points.push_back(pt);
        }
      }
    }
  }
}

void generateSphereObstacle(const Vector3d& center, double radius, pcl::PointCloud<pcl::PointXYZ>& cloud)
{
  double resolution = _resolution * 0.5;  // 使用更密集的分辨率
  int r_num = ceil(radius / (resolution * 0.5));  // 使点云高度与Marker匹配
  
  pcl::PointXYZ pt;
  for (int i = -r_num; i <= r_num; i++) {
    for (int j = -r_num; j <= r_num; j++) {
      for (int k = -r_num; k <= r_num; k++) {
        double dist = sqrt(i*i + j*j + k*k) * resolution;
        if (dist <= radius) {
          pt.x = center[0] + i * resolution + 0.001;
          pt.y = center[1] + j * resolution + 0.001;
          pt.z = k * resolution + 0.001;  // 从地面开始，高度与3D模型匹配
          if (pt.z >= 0.0) {
            cloud.points.push_back(pt);
          }
        }
      }
    }
  }
}

void updateDynamicObstacles()
{
  for (auto& obs : dynamic_obstacles) {
    // 沿着圆形轨迹移动
    obs.current_angle += obs.angular_speed / _dynamic_update_rate;  // 更新角度，使用正确的步长
    
    // 计算新的位置（3D模型底部在地面）
    obs.position[0] = obs.circle_center[0] + obs.circle_radius * cos(obs.current_angle);
    obs.position[1] = obs.circle_center[1] + obs.circle_radius * sin(obs.current_angle);
    obs.position[2] = obs.size[2] / 2.0;  // 3D模型中心点，底部在地面
  }
}

void generateDynamicObstacles(pcl::PointCloud<pcl::PointXYZ>& cloud)
{
  for (const auto& obs : dynamic_obstacles) {
    if (obs.type == BOX) {
      generateBoxObstacle(obs.position, obs.size, cloud);
    } else if (obs.type == CYLINDER) {
      generateCylinderObstacle(obs.position, obs.size[0], obs.size[1], cloud);
    } else if (obs.type == SPHERE) {
      generateSphereObstacle(obs.position, obs.size[0], cloud);
    }
  }
}

void initializeDynamicObstacles()
{
  dynamic_obstacles.clear();
  
  random_device rd;
  default_random_engine eng(rd());
  uniform_real_distribution<double> rand_x(_x_l, _x_h);
  uniform_real_distribution<double> rand_y(_y_l, _y_h);
  uniform_real_distribution<double> rand_z(1.0, _z_size / 2.0);
  uniform_real_distribution<double> rand_size(_w_l, _w_h);
  uniform_real_distribution<double> rand_height(_h_l, _h_h);
  uniform_real_distribution<double> rand_speed(1.0, 2.0);
  uniform_real_distribution<double> rand_radius(3.0, 5.0);
  uniform_int_distribution<int> rand_type(0, 2);
  
  // 定义几个固定的圆形轨迹的中心点（经过规划，避开静态障碍物）
  std::vector<Vector3d> circle_centers;
  
  // 圆形1：左下角，避开静态障碍物
  circle_centers.push_back(Vector3d(-10.0, -10.0, 0.0));  // 圆形轨迹在地面
  
  // 圆形2：右下角，避开静态障碍物
  circle_centers.push_back(Vector3d(10.0, -10.0, 0.0));  // 圆形轨迹在地面
  
  // 圆形3：右上角，避开静态障碍物
  circle_centers.push_back(Vector3d(10.0, 10.0, 0.0));  // 圆形轨迹在地面
  
  int num_dynamic = _dynamic_obstacles_num;
  for (int i = 0; i < num_dynamic; i++) {
    DynamicObstacle obs;
    obs.id = i;
    obs.type = BOX;
    
    // 为每个动态障碍物分配一个圆形轨迹
    int center_index = i % circle_centers.size();
    obs.circle_center = circle_centers[center_index];
    obs.circle_radius = rand_radius(eng);
    obs.current_angle = 0.0;  // 初始角度
    obs.angular_speed = rand_speed(eng) / obs.circle_radius;  // 角速度 = 线速度 / 半径
    
    // 设置初始位置
    obs.position[0] = obs.circle_center[0] + obs.circle_radius * cos(obs.current_angle);
    obs.position[1] = obs.circle_center[1] + obs.circle_radius * sin(obs.current_angle);
    obs.position[2] = obs.circle_center[2];
    obs.center = obs.position;
    
    if (obs.type == BOX) {
      obs.size = Vector3d(rand_size(eng), rand_size(eng), rand_height(eng));
    } else if (obs.type == CYLINDER) {
      obs.size = Vector3d(rand_size(eng), rand_height(eng), 0.0);
    } else {
      obs.size = Vector3d(rand_size(eng), 0.0, 0.0);
    }
    
    obs.speed = rand_speed(eng);
    obs.frequency = 0.0;  // 不使用频率
    obs.phase = 0.0;  // 不使用相位
    obs.amplitude = Vector3d(0.0, 0.0, 0.0);  // 不使用幅度
    
    dynamic_obstacles.push_back(obs);
  }
}

void publishDynamicObstaclePoses()
{
  std_msgs::String msg;
  std::stringstream ss;
  
  for (const auto& obs : dynamic_obstacles) {
    ss << obs.id << ",";
    if (obs.type == BOX) ss << "BOX";
    else if (obs.type == CYLINDER) ss << "CYLINDER";
    else ss << "SPHERE";
    ss << "," << std::fixed << std::setprecision(3) << obs.position[0];
    ss << "," << obs.position[1];
    ss << "," << obs.position[2];
    ss << "," << obs.size[0];
    ss << "," << obs.size[1];
    ss << "," << obs.size[2] << "\n";
  }
  
  msg.data = ss.str();
  _obstacle_poses_pub.publish(msg);
}

void publishObstacleMarkers()
{
  visualization_msgs::MarkerArray marker_array;
  
  for (const auto& obs : dynamic_obstacles) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = map_frame_name;
    marker.header.stamp = ros::Time::now();
    marker.ns = "dynamic_obstacles";
    marker.id = obs.id;
    marker.type = (obs.type == BOX) ? visualization_msgs::Marker::CUBE :
                (obs.type == CYLINDER) ? visualization_msgs::Marker::CYLINDER :
                visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    
    marker.pose.position.x = obs.position[0];
    marker.pose.position.y = obs.position[1];
    marker.pose.position.z = obs.position[2];
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    
    if (obs.type == BOX) {
      marker.scale.x = obs.size[0];
      marker.scale.y = obs.size[1];
      marker.scale.z = obs.size[2];
    } else if (obs.type == CYLINDER) {
      marker.scale.x = obs.size[0] * 2;
      marker.scale.y = obs.size[0] * 2;
      marker.scale.z = obs.size[1];
    } else {
      marker.scale.x = obs.size[0] * 2;
      marker.scale.y = obs.size[0] * 2;
      marker.scale.z = obs.size[0] * 2;
    }
    
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;
    marker.color.a = 0.8;
    
    marker.lifetime = ros::Duration(0);
    marker_array.markers.push_back(marker);
  }
  
  _obstacle_markers_pub.publish(marker_array);
}

void publishStaticObstacleMarkers()
{
  visualization_msgs::MarkerArray marker_array;
  
  for (const auto& obs : static_obstacles) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = map_frame_name;
    marker.header.stamp = ros::Time::now();
    marker.ns = "static_obstacles";
    marker.id = obs.id;
    marker.type = (obs.type == BOX) ? visualization_msgs::Marker::CUBE :
                (obs.type == CYLINDER) ? visualization_msgs::Marker::CYLINDER :
                visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    
    marker.pose.position.x = obs.position[0];
    marker.pose.position.y = obs.position[1];
    marker.pose.position.z = obs.position[2];
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    
    if (obs.type == BOX) {
      marker.scale.x = obs.size[0];
      marker.scale.y = obs.size[1];
      marker.scale.z = obs.size[2];
    } else if (obs.type == CYLINDER) {
      marker.scale.x = obs.size[0] * 2;
      marker.scale.y = obs.size[0] * 2;
      marker.scale.z = obs.size[1];
    } else {
      marker.scale.x = obs.size[0] * 2;
      marker.scale.y = obs.size[0] * 2;
      marker.scale.z = obs.size[0] * 2;
    }
    
    marker.color.r = 0.0;
    marker.color.g = 0.8;
    marker.color.b = 1.0;
    marker.color.a = 0.6;
    
    marker.lifetime = ros::Duration(0);
    marker_array.markers.push_back(marker);
  }
  
  _static_obstacle_markers_pub.publish(marker_array);
}

void RandomMapGenerate(bool ground_map_swt, bool include_dynamic = true)
{
   if (ground_map_swt)
   {
      cloudMap.clear();

      random_device rd;
      default_random_engine eng(rd());

      uniform_real_distribution<double> rand_x = uniform_real_distribution<double>(_x_l, _x_h);
      uniform_real_distribution<double> rand_y = uniform_real_distribution<double>(_y_l, _y_h);
      uniform_real_distribution<double> rand_w = uniform_real_distribution<double>(_w_l, _w_h);
      uniform_real_distribution<double> rand_h = uniform_real_distribution<double>(_h_l, _h_h);

      uniform_real_distribution<double> rand_x_circle = uniform_real_distribution<double>(_x_l + 1.0, _x_h - 1.0);
      uniform_real_distribution<double> rand_y_circle = uniform_real_distribution<double>(_y_l + 1.0, _y_h - 1.0);
      uniform_real_distribution<double> rand_r_circle = uniform_real_distribution<double>(_w_c_l, _w_c_h);

      uniform_real_distribution<double> rand_roll = uniform_real_distribution<double>(-M_PI, +M_PI);
      uniform_real_distribution<double> rand_pitch = uniform_real_distribution<double>(+M_PI / 4.0, +M_PI / 2.0);
      uniform_real_distribution<double> rand_yaw = uniform_real_distribution<double>(+M_PI / 4.0, +M_PI / 2.0);
      uniform_real_distribution<double> rand_ellipse_c = uniform_real_distribution<double>(0.5, 2.0);
      uniform_real_distribution<double> rand_num = uniform_real_distribution<double>(0.0, 1.0);

      pcl::PointXYZ pt_random;

      // firstly, we put some circles
      for (int i = 0; i < _cir_num; i++)
      {
         double x0, y0, z0, R;
         std::vector<Vector3d> circle_set;

         x0 = rand_x_circle(eng);
         y0 = rand_y_circle(eng);
         z0 = rand_h(eng) / 2.0;
         R = rand_r_circle(eng);

         if (sqrt(pow(x0 - _init_x, 2) + pow(y0 - _init_y, 2)) < 2.0)
            continue;

         double a, b;
         a = rand_ellipse_c(eng);
         b = rand_ellipse_c(eng);

         double x, y, z;
         Vector3d pt3, pt3_rot;
         for (double theta = -M_PI; theta < M_PI; theta += 0.025)
         {
            x = a * cos(theta) * R;
            y = b * sin(theta) * R;
            z = 0;
            pt3 << x, y, z;
            circle_set.push_back(pt3);
         }
         // Define a random 3d rotation matrix
         Matrix3d Rot;
         double roll, pitch, yaw;
         double alpha, beta, gama;
         roll = rand_roll(eng);   // alpha
         pitch = rand_pitch(eng); // beta
         yaw = rand_yaw(eng);     // gama

         alpha = roll;
         beta = pitch;
         gama = yaw;

         double p = rand_num(eng);
         if (p < 0.5)
         {
            beta = M_PI / 2.0;
            gama = M_PI / 2.0;
         }

         Rot << cos(alpha) * cos(gama) - cos(beta) * sin(alpha) * sin(gama), -cos(beta) * cos(gama) * sin(alpha) - cos(alpha) * sin(gama), sin(alpha) * sin(beta),
             cos(gama) * sin(alpha) + cos(alpha) * cos(beta) * sin(gama), cos(alpha) * cos(beta) * cos(gama) - sin(alpha) * sin(gama), -cos(alpha) * sin(beta),
             sin(beta) * sin(gama), cos(gama) * sin(beta), cos(beta);

         for (auto pt : circle_set)
         {
            pt3_rot = Rot * pt;
            pt_random.x = pt3_rot(0) + x0 + 0.001;
            pt_random.y = pt3_rot(1) + y0 + 0.001;
            pt_random.z = pt3_rot(2) + z0 + 0.001;

            if (pt_random.z >= 0.0)
               cloudMap.points.push_back(pt_random);
         }
      }

      bool is_kdtree_empty = false;
      if (cloudMap.points.size() > 0)
         kdtreeMap.setInputCloud(cloudMap.makeShared());
      else
         is_kdtree_empty = true;

      // then, we put some pilar
      static_obstacles.clear();
      for (int i = 0; i < _obs_num + 1; i++)
      {
         double x, y, w, h;
         x = rand_x(eng);
         y = rand_y(eng);
         w = rand_w(eng);
         h = rand_h(eng);

         if (sqrt(pow(x - _init_x, 2) + pow(y - _init_y, 2)) < 1.0)
            continue;

         pcl::PointXYZ searchPoint(x, y, (_h_l + _h_h) / 2.0);
         pointIdxSearch.clear();
         pointSquaredDistance.clear();

         if (is_kdtree_empty == false)
         {
            if (kdtreeMap.nearestKSearch(searchPoint, 1, pointIdxSearch, pointSquaredDistance) > 0)
            {
               if (sqrt(pointSquaredDistance[0]) < 1.0)
                  continue;
            }
         }

         x = floor(x / _resolution) * _resolution + _resolution / 2.0;
         y = floor(y / _resolution) * _resolution + _resolution / 2.0;
         
         h = rand_h(eng);
         
         StaticObstacle static_obs;
         static_obs.id = static_obstacles.size();
         static_obs.type = BOX;
         double marker_height = 4.5 * h / 2.0;
         static_obs.position = Vector3d(x, y, marker_height / 2.0);  // 3D模型中心点，底部在地面
         static_obs.size = Vector3d(w, w, marker_height);
         static_obstacles.push_back(static_obs);
         ROS_INFO("Added static obstacle %d at (%.2f, %.2f, %.2f)", static_obs.id, x, y, h/2.0);

         int widNum = ceil(w / _resolution);
         for (int r = -widNum / 2.0; r < widNum / 2.0; r++)
         {
            for (int s = -widNum / 2.0; s < widNum / 2.0; s++)
            {
               int heiNum = 4.5 * ceil(h / _resolution);
               for (int t = 0; t < heiNum; t++)
               {
                  pt_random.x = x + (r + 0.0) * _resolution + 0.001;
                  pt_random.y = y + (s + 0.0) * _resolution + 0.001;
                  pt_random.z = (t + 0.0) * _resolution * 0.5 + 0.001;
                  cloudMap.points.push_back(pt_random);
               }
            }
         }
      }
      // 生成动态障碍物
      if (_dynamic_obstacles_enabled) {
        generateDynamicObstacles(cloudMap);
      }

      cloudMap.width = cloudMap.points.size();
      cloudMap.height = 1;
      cloudMap.is_dense = true;

      pcl::toROSMsg(cloudMap, globalMap_pcd);
      globalMap_pcd.header.frame_id = map_frame_name;
   }
   else
   {
      cloudMap.clear();

      pcl::PointXYZ pt_ground;
      for (double xi = 2*_x_l; xi < 2*_x_h; xi += _resolution)
      {
         for (double yi = 2*_y_l; yi < 2*_y_h; yi += _resolution)
         {
            pt_ground.x = xi;
            pt_ground.y = yi;
            pt_ground.z = -0.2;
            cloudMap.points.push_back(pt_ground);
         }
      }
      cloudMap.width = cloudMap.points.size();
      cloudMap.height = 1;
      cloudMap.is_dense = true;

      pcl::toROSMsg(cloudMap, globalGround_pcd);
      globalGround_pcd.header.frame_id = map_frame_name;
   }
}

void rcvOdometryCallbck(const nav_msgs::Odometry odom)
{
   _has_odom = true;
}

void pubSensedPoints(bool ground_map_swt)
{
   if (ground_map_swt)
   {
      _all_ground_pub.publish(globalGround_pcd);
   }
   else
   {
      _all_map_pub.publish(globalMap_pcd);
   }
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "random_complex_scene");
   ros::NodeHandle n("~");

   _all_map_pub = n.advertise<sensor_msgs::PointCloud2>("global_map", 1);
   _all_ground_pub = n.advertise<sensor_msgs::PointCloud2>("global_ground", 1);
   _obstacle_poses_pub = n.advertise<std_msgs::String>("obstacle_poses", 1);
   _obstacle_markers_pub = n.advertise<visualization_msgs::MarkerArray>("obstacle_markers", 10);
   _static_obstacle_markers_pub = n.advertise<visualization_msgs::MarkerArray>("static_obstacle_markers", 10);
   _odom_sub = n.subscribe("odometry", 50, rcvOdometryCallbck);

   n.param("init_state_x", _init_x, 0.0);
   n.param("init_state_y", _init_y, 0.0);

   n.param("map/x_size", _x_size, 20.0);
   n.param("map/y_size", _y_size, 20.0);
   n.param("map/z_size", _z_size, 5.0);
   n.param("map_frame_name", map_frame_name, std::string("map"));

   n.param("map/obs_num", _obs_num, 30);
   n.param("map/circle_num", _cir_num, 0);
   n.param("map/resolution", _resolution, 0.2);

   n.param("ObstacleShape/lower_rad", _w_l, 0.3);
   n.param("ObstacleShape/upper_rad", _w_h, 0.8);
   n.param("ObstacleShape/lower_hei", _h_l, 3.0);
   n.param("ObstacleShape/upper_hei", _h_h, 7.0);

   n.param("CircleShape/lower_circle_rad", _w_c_l, 0.3);
   n.param("CircleShape/upper_circle_rad", _w_c_h, 0.8);

   n.param("sensing/rate", _sense_rate, 100.0);
   n.param("dynamic_obstacles", _dynamic_obstacles_enabled, true);
   n.param("dynamic_update_rate", _dynamic_update_rate, 60.0);
   n.param("dynamic_obstacles_num", _dynamic_obstacles_num, 1);

   _x_l = -_x_size / 2.0;
   _x_h = +_x_size / 2.0;

   _y_l = -_y_size / 2.0;
   _y_h = +_y_size / 2.0;

   if (_dynamic_obstacles_enabled) {
     initializeDynamicObstacles();
   }
   
   RandomMapGenerate(false);
   RandomMapGenerate(true, false);
   staticCloudMap = cloudMap;
   publishStaticObstacleMarkers();
   
   ros::Rate loop_rate(_sense_rate);
   ros::Rate dynamic_rate(_dynamic_update_rate);
   
   bool ground_map_swt = true;
   double dynamic_timer = 0.0;
   double static_timer = 0.0;
   
   while (ros::ok())
   {
      if (_dynamic_obstacles_enabled) {
        dynamic_timer += 1.0 / _sense_rate;
        if (dynamic_timer >= 1.0 / _dynamic_update_rate) {
          current_time += dynamic_timer;
          updateDynamicObstacles();
          publishDynamicObstaclePoses();
          publishObstacleMarkers();
          
          cloudMap = staticCloudMap;
          generateDynamicObstacles(cloudMap);
          cloudMap.width = cloudMap.points.size();
          cloudMap.height = 1;
          cloudMap.is_dense = true;
          pcl::toROSMsg(cloudMap, globalMap_pcd);
          globalMap_pcd.header.frame_id = map_frame_name;
          
          dynamic_timer = 0.0;
        }
      }
      
      static_timer += 1.0 / _sense_rate;
      if (static_timer >= 1.0) {
        publishStaticObstacleMarkers();
        static_timer = 0.0;
      }
      
      pubSensedPoints(ground_map_swt);
      ground_map_swt = !ground_map_swt;
      ros::spinOnce();
      loop_rate.sleep();
   }
}