# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "quadrotor_msgs: 13 messages, 0 services")

set(MSG_I_FLAGS "-Iquadrotor_msgs:D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg;-Istd_msgs:E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg;-Igeometry_msgs:E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg;-Inav_msgs:E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/nav_msgs/cmake/../msg;-Istd_msgs:E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg;-Iactionlib_msgs:E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(quadrotor_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg" ""
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg" ""
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg" ""
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg" "std_msgs/Header"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg" "geometry_msgs/TwistWithCovariance:nav_msgs/Odometry:geometry_msgs/Vector3:geometry_msgs/PoseWithCovariance:geometry_msgs/Twist:std_msgs/Header:geometry_msgs/Pose:geometry_msgs/Point:geometry_msgs/Quaternion"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg" "std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Vector3"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg" "std_msgs/Header"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg" "std_msgs/Header"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg" "geometry_msgs/Point:std_msgs/Header:geometry_msgs/Vector3"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg" "geometry_msgs/Quaternion:quadrotor_msgs/AuxCommand:std_msgs/Header:geometry_msgs/Vector3"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg" "std_msgs/Header"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg" "std_msgs/Header"
)

get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg" NAME_WE)
add_custom_target(_quadrotor_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "quadrotor_msgs" "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg" "std_msgs/Header:quadrotor_msgs/AuxCommand"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/nav_msgs/cmake/../msg/Odometry.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Twist.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Pose.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_cpp(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(quadrotor_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(quadrotor_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(quadrotor_msgs_generate_messages quadrotor_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_cpp _quadrotor_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_msgs_gencpp)
add_dependencies(quadrotor_msgs_gencpp quadrotor_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_msgs_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/nav_msgs/cmake/../msg/Odometry.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Twist.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Pose.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Point.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Quaternion.msg;D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)
_generate_msg_py(quadrotor_msgs
  "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg"
  "${MSG_I_FLAGS}"
  "E:/MATLAB/R2024b/sys/ros1/win64/ros1/share/std_msgs/cmake/../msg/Header.msg;D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(quadrotor_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(quadrotor_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(quadrotor_msgs_generate_messages quadrotor_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg" NAME_WE)
add_dependencies(quadrotor_msgs_generate_messages_py _quadrotor_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(quadrotor_msgs_genpy)
add_dependencies(quadrotor_msgs_genpy quadrotor_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS quadrotor_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/quadrotor_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(quadrotor_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(quadrotor_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(quadrotor_msgs_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(quadrotor_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs)
  install(CODE "execute_process(COMMAND \"C:/Users/86186/AppData/Roaming/MathWorks/MATLAB/R2024b/ros1/win64/venv/Scripts/python.exe\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/quadrotor_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(quadrotor_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(quadrotor_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(quadrotor_msgs_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(quadrotor_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
