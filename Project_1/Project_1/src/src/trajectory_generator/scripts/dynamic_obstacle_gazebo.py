#!/usr/bin/env python3
import rospy
import numpy as np
from geometry_msgs.msg import Pose, Point, Quaternion
from gazebo_msgs.srv import SpawnModel, DeleteModel, SetModelState
from gazebo_msgs.msg import ModelState
from std_msgs.msg import String
import uuid
import random

class DynamicObstacleGazebo:
    def __init__(self):
        rospy.wait_for_service('/gazebo/spawn_sdf_model')
        rospy.wait_for_service('/gazebo/delete_model')
        rospy.wait_for_service('/gazebo/set_model_state')
        
        self.spawn_model = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
        self.delete_model = rospy.ServiceProxy('/gazebo/delete_model', DeleteModel)
        self.set_model_state = rospy.ServiceProxy('/gazebo/set_model_state', SetModelState)
        
        self.obstacle_poses_sub = rospy.Subscriber('/dynamic_obstacles/poses', String, self.obstacle_poses_callback)
        self.current_models = {}
        
        rospy.loginfo("Dynamic Obstacle Gazebo Node Started")

    def generate_box_sdf(self, name, size, color):
        r, g, b = color
        sdf = f'''<?xml version="1.0" ?>
<sdf version="1.6">
  <model name="{name}">
    <static>false</static>
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
  </model>
</sdf>'''
        return sdf

    def generate_cylinder_sdf(self, name, radius, height, color):
        r, g, b = color
        sdf = f'''<?xml version="1.0" ?>
<sdf version="1.6">
  <model name="{name}">
    <static>false</static>
    <link name="link">
      <collision name="collision">
        <geometry>
          <cylinder>
            <radius>{radius:.3f}</radius>
            <length>{height:.3f}</length>
          </cylinder>
        </geometry>
      </collision>
      <visual name="visual">
        <geometry>
          <cylinder>
            <radius>{radius:.3f}</radius>
            <length>{height:.3f}</length>
          </cylinder>
        </geometry>
        <material>
          <ambient>{r:.2f} {g:.2f} {b:.2f} 1</ambient>
          <diffuse>{r:.2f} {g:.2f} {b:.2f} 1</diffuse>
        </material>
      </visual>
    </link>
  </model>
</sdf>'''
        return sdf

    def generate_sphere_sdf(self, name, radius, color):
        r, g, b = color
        sdf = f'''<?xml version="1.0" ?>
<sdf version="1.6">
  <model name="{name}">
    <static>false</static>
    <link name="link">
      <collision name="collision">
        <geometry>
          <sphere>
            <radius>{radius:.3f}</radius>
          </sphere>
        </geometry>
      </collision>
      <visual name="visual">
        <geometry>
          <sphere>
            <radius>{radius:.3f}</radius>
          </sphere>
        </geometry>
        <material>
          <ambient>{r:.2f} {g:.2f} {b:.2f} 1</ambient>
          <diffuse>{r:.2f} {g:.2f} {b:.2f} 1</diffuse>
        </material>
      </visual>
    </link>
  </model>
</sdf>'''
        return sdf

    def obstacle_poses_callback(self, msg):
        try:
            obstacles_data = msg.data.split('\n')
            for line in obstacles_data:
                if not line.strip():
                    continue
                
                parts = line.split(',')
                if len(parts) < 7:
                    continue
                
                obs_id = parts[0]
                obs_type = parts[1]
                x, y, z = float(parts[2]), float(parts[3]), float(parts[4])
                size_params = [float(p) for p in parts[5:]]
                
                if obs_id not in self.current_models:
                    self.spawn_obstacle(obs_id, obs_type, x, y, z, size_params)
                else:
                    self.update_obstacle_position(obs_id, x, y, z)
                    
        except Exception as e:
            rospy.logwarn(f"Error processing obstacle poses: {e}")

    def spawn_obstacle(self, obs_id, obs_type, x, y, z, size_params):
        name = f"dynamic_obstacle_{obs_id}"
        color = (random.random(), random.random(), random.random())
        
        if obs_type == "BOX":
            sdf = self.generate_box_sdf(name, size_params, color)
        elif obs_type == "CYLINDER":
            sdf = self.generate_cylinder_sdf(name, size_params[0], size_params[1], color)
        elif obs_type == "SPHERE":
            sdf = self.generate_sphere_sdf(name, size_params[0], color)
        else:
            rospy.logwarn(f"Unknown obstacle type: {obs_type}")
            return
        
        pose = Pose()
        pose.position.x = x
        pose.position.y = y
        pose.position.z = z
        pose.orientation.w = 1.0
        
        try:
            self.spawn_model(name, sdf, "", pose, "world")
            self.current_models[obs_id] = {'name': name, 'type': obs_type}
            rospy.loginfo(f"Spawned dynamic obstacle {name} at ({x:.2f}, {y:.2f}, {z:.2f})")
        except Exception as e:
            rospy.logwarn(f"Failed to spawn {name}: {e}")

    def update_obstacle_position(self, obs_id, x, y, z):
        if obs_id not in self.current_models:
            return
        
        model_name = self.current_models[obs_id]['name']
        
        model_state = ModelState()
        model_state.model_name = model_name
        model_state.pose.position.x = x
        model_state.pose.position.y = y
        model_state.pose.position.z = z
        model_state.pose.orientation.w = 1.0
        model_state.reference_frame = "world"
        
        try:
            self.set_model_state(model_state)
        except Exception as e:
            rospy.logwarn(f"Failed to update {model_name}: {e}")

if __name__ == '__main__':
    rospy.init_node('dynamic_obstacle_gazebo', anonymous=True)
    node = DynamicObstacleGazebo()
    rospy.spin()