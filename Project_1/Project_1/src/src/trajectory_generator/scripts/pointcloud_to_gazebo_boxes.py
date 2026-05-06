#!/usr/bin/env python3
import rospy
import numpy as np
from sensor_msgs.msg import PointCloud2
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Pose
from gazebo_msgs.srv import SpawnModel, DeleteModel, SetModelState
from gazebo_msgs.msg import ModelState
import sensor_msgs.point_cloud2 as pc2
from sklearn.cluster import DBSCAN
import uuid
import random
import time
import os

class PointCloudToGazeboBoxes:
    def __init__(self):
        rospy.wait_for_service('/gazebo/spawn_sdf_model')
        rospy.wait_for_service('/gazebo/delete_model')
        rospy.wait_for_service('/gazebo/set_model_state')
        self.spawn_model = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
        self.delete_model = rospy.ServiceProxy('/gazebo/delete_model', DeleteModel)
        self.set_model_state = rospy.ServiceProxy('/gazebo/set_model_state', SetModelState)
        
        # 静态障碍物：只生成一次
        self.static_sub = rospy.Subscriber('/random_complex/static_obstacle_markers', MarkerArray, self.static_callback)
        self.static_generated = False
        self.static_models = []
        
        # 动态障碍物：只生成一次，然后更新位置
        self.dynamic_sub = rospy.Subscriber('/random_complex/obstacle_markers', MarkerArray, self.dynamic_callback)
        self.dynamic_generated = False
        self.dynamic_models = {}  # {id: name}
        
        # 模型类型参数：cube（长方体）或pine_tree（松树）
        self.model_type = rospy.get_param("~model_type", "cube")
        
        # Gazebo模型库路径
        self.gazebo_model_path = rospy.get_param("~gazebo_model_path", "~/.gazebo/models")
        
        self.voxel_size = rospy.get_param("~voxel_size", 0.2)
        self.eps = rospy.get_param("~eps", 0.3)
        self.min_samples = rospy.get_param("~min_samples", 5)
        self.box_padding = rospy.get_param("~box_padding", 0.05)
        
        random.seed()
        rospy.loginfo(f"PointCloud to Gazebo Boxes Node Started (model_type: {self.model_type})")

    def static_callback(self, msg):
        # 静态障碍物：只生成一次
        if self.static_generated:
            return
        
        rospy.loginfo(f"Generating {len(msg.markers)} static obstacles...")
        
        for marker in msg.markers:
            # 从Marker中获取障碍物信息
            if marker.type == Marker.CUBE:
                # 生成Gazebo模型
                name = f"static_obstacle_{uuid.uuid4().hex[:8]}"
                
                if self.model_type == "pine_tree":
                    # 使用松树模型
                    model_path = os.path.join(os.path.expanduser(self.gazebo_model_path), "pine_tree", "model.sdf")
                    if os.path.exists(model_path):
                        with open(model_path, 'r') as f:
                            sdf = f.read()
                            try:
                                # 调整Z坐标，使树的底部在地面
                                adjusted_pose = marker.pose
                                adjusted_pose.position.z = marker.pose.position.z - marker.scale.z / 2.0
                                self.spawn_model(name, sdf, "", adjusted_pose, "world")
                                self.static_models.append(name)
                            except Exception as e:
                                rospy.logwarn(f"Failed to spawn {name}: {e}")
                    else:
                            rospy.logwarn(f"Pine tree model not found at {model_path}")
                else:
                    # 使用长方体模型
                    size = [marker.scale.x, marker.scale.y, marker.scale.z]
                    center = [marker.pose.position.x, marker.pose.position.y, marker.pose.position.z]
                    color = (marker.color.r, marker.color.g, marker.color.b)
                    sdf = self.generate_cube_sdf(name, size, color)
                    try:
                        self.spawn_model(name, sdf, "", marker.pose, "world")
                        self.static_models.append(name)
                    except Exception as e:
                        rospy.logwarn(f"Failed to spawn {name}: {e}")
        
        rospy.loginfo(f"Generated {len(self.static_models)} static obstacles")
        self.static_generated = True

    def dynamic_callback(self, msg):
        # 动态障碍物：只生成一次，然后更新位置
        
        if not self.dynamic_generated:
            # 第一次：生成动态障碍物
            rospy.loginfo(f"Generating {len(msg.markers)} dynamic obstacles...")
            
            for marker in msg.markers:
                # 从Marker中获取障碍物信息
                if marker.type == Marker.CUBE:
                    # 生成Gazebo模型
                    name = f"dynamic_obstacle_{marker.id}"
                    
                    if self.model_type == "pine_tree":
                        # 使用松树模型
                        model_path = os.path.join(os.path.expanduser(self.gazebo_model_path), "pine_tree", "model.sdf")
                        if os.path.exists(model_path):
                            with open(model_path, 'r') as f:
                                sdf = f.read()
                                try:
                                    # 调整Z坐标，使树的底部在地面
                                    adjusted_pose = marker.pose
                                    adjusted_pose.position.z = marker.pose.position.z - marker.scale.z / 2.0
                                    self.spawn_model(name, sdf, "", adjusted_pose, "world")
                                    self.dynamic_models[marker.id] = name
                                except Exception as e:
                                    rospy.logwarn(f"Failed to spawn {name}: {e}")
                        else:
                            rospy.logwarn(f"Pine tree model not found at {model_path}")
                    else:
                        # 使用长方体模型
                        size = [marker.scale.x, marker.scale.y, marker.scale.z]
                        color = (marker.color.r, marker.color.g, marker.color.b)
                        sdf = self.generate_cube_sdf(name, size, color)
                        try:
                            self.spawn_model(name, sdf, "", marker.pose, "world")
                            self.dynamic_models[marker.id] = name
                        except Exception as e:
                            rospy.logwarn(f"Failed to spawn {name}: {e}")
            
            rospy.loginfo(f"Generated {len(self.dynamic_models)} dynamic obstacles")
            self.dynamic_generated = True
        else:
            # 后续：只更新位置
            for marker in msg.markers:
                if marker.id in self.dynamic_models:
                    name = self.dynamic_models[marker.id]
                    
                    # 创建ModelState
                    model_state = ModelState()
                    model_state.model_name = name
                    
                    # 调整Z坐标，使树的底部在地面
                    model_state.pose = marker.pose
                    if self.model_type == "pine_tree":
                        model_state.pose.position.z = marker.pose.position.z - marker.scale.z / 2.0
                    
                    model_state.reference_frame = "world"
                    
                    try:
                        self.set_model_state(model_state)
                    except Exception as e:
                        rospy.logwarn(f"Failed to update {name}: {e}")

    def generate_cube_sdf(self, name, size, color):
        r, g, b = color
        sdf = f'''<?xml version="1.0" ?>
<sdf version="1.6">
  <model name="{name}">
    <static>true</static>
    <link name="link">
      <collision name="collision">
        <geometry>
          <box>
            <size>{size[0]:.3f} {size[1]:.3f} {size[2]:.3f}</size>
          </box>
        </geometry>
      </collision>
      <visual name="visual">
        <geometry>
          <box>
            <size>{size[0]:.3f} {size[1]:.3f} {size[2]:.3f}</size>
          </box>
        </geometry>
        <material>
          <ambient>{r:.2f} {g:.2f} {b:.2f} 1</ambient>
          <diffuse>{r:.2f} {g:.2f} {b:.2f} 1</diffuse>
        </material>
      </visual>
    </link>
    <pose>0 0 0 0 0 0</pose>
  </model>
</sdf>'''
        return sdf

    def update_gazebo_models(self, new_boxes_params, is_dynamic=False):
        # 生成新的障碍物模型
        for p in new_boxes_params:
            pose = Pose()
            pose.position.x = p['center'][0]
            pose.position.y = p['center'][1]
            pose.position.z = p['center'][2]
            pose.orientation.w = 1.0
            sdf = self.generate_cube_sdf(p['name'], p['size'], p['color'])
            try:
                self.spawn_model(p['name'], sdf, "", pose, "world")
                if is_dynamic:
                    self.dynamic_models.append(p['name'])
            except Exception as e:
                rospy.logwarn(f"Failed to spawn {p['name']}: {e}")
        
        if is_dynamic:
            rospy.loginfo(f"Updated {len(new_boxes_params)} dynamic obstacles")

if __name__ == '__main__':
    rospy.init_node('pointcloud_to_gazebo_boxes', anonymous=True)
    node = PointCloudToGazeboBoxes()
    rospy.spin()