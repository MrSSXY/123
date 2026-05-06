#!/usr/bin/env python3
import rospy
from nav_msgs.msg import Odometry
from gazebo_msgs.msg import ModelState
from gazebo_msgs.srv import SetModelState, GetModelState

class OdomToGazebo:
    def __init__(self):
        # 将模型名称改为 iris
        self.model_name = "iris"
        rospy.wait_for_service('/gazebo/set_model_state')
        self.set_state = rospy.ServiceProxy('/gazebo/set_model_state', SetModelState)
        
        # 等待iris模型生成
        rospy.loginfo("Waiting for iris model to spawn...")
        rospy.wait_for_service('/gazebo/get_model_state')
        get_model_state = rospy.ServiceProxy('/gazebo/get_model_state', GetModelState)
        
        # 持续检查iris模型是否存在
        while not rospy.is_shutdown():
            try:
                response = get_model_state(self.model_name, "world")
                if response.success:
                    rospy.loginfo("Iris model found, starting odom sync")
                    break
            except rospy.ServiceException:
                pass
            rospy.sleep(0.5)
        
        self.sub = rospy.Subscriber('/visual_slam/odom', Odometry, self.callback)
        rospy.loginfo("Odom to Gazebo bridge started (syncing to iris)")

    def callback(self, msg):
        state = ModelState()
        state.model_name = self.model_name
        state.pose = msg.pose.pose
        state.twist = msg.twist.twist
        state.reference_frame = "world"
        try:
            self.set_state(state)
        except rospy.ServiceException as e:
            rospy.logwarn_throttle(5, "SetModelState failed: %s", e)

if __name__ == '__main__':
    rospy.init_node('odom_to_gazebo', anonymous=True)
    node = OdomToGazebo()
    rospy.spin()