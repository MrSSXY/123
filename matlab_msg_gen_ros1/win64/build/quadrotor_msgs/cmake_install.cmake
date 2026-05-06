# Install script for directory: D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/bag/matlab_msg_gen_ros1/win64/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_msgs/msg" TYPE FILE FILES
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/AuxCommand.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Corrections.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Gains.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/LQRTrajectory.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Odometry.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/OutputData.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PPROutputData.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PolynomialTrajectory.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/PositionCommand.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/SO3Command.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/Serial.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/StatusData.msg"
    "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/msg/TRPYCommand.msg"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_msgs/cmake" TYPE FILE FILES "D:/bag/matlab_msg_gen_ros1/win64/build/quadrotor_msgs/catkin_generated/installspace/quadrotor_msgs-msg-paths.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "D:/bag/matlab_msg_gen_ros1/win64/devel/include/quadrotor_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "C:/Users/86186/AppData/Roaming/MathWorks/MATLAB/R2024b/ros1/win64/venv/Scripts/python.exe" -m compileall "D:/bag/matlab_msg_gen_ros1/win64/devel/lib/site-packages/quadrotor_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/site-packages" TYPE DIRECTORY FILES "D:/bag/matlab_msg_gen_ros1/win64/devel/lib/site-packages/quadrotor_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/bag/matlab_msg_gen_ros1/win64/build/quadrotor_msgs/catkin_generated/installspace/quadrotor_msgs.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_msgs/cmake" TYPE FILE FILES "D:/bag/matlab_msg_gen_ros1/win64/build/quadrotor_msgs/catkin_generated/installspace/quadrotor_msgs-msg-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_msgs/cmake" TYPE FILE FILES
    "D:/bag/matlab_msg_gen_ros1/win64/build/quadrotor_msgs/catkin_generated/installspace/quadrotor_msgsConfig.cmake"
    "D:/bag/matlab_msg_gen_ros1/win64/build/quadrotor_msgs/catkin_generated/installspace/quadrotor_msgsConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quadrotor_msgs" TYPE FILE FILES "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/bag/matlab_msg_gen_ros1/win64/devel/lib/quadrotor_msgs_matlab.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/bag/matlab_msg_gen_ros1/win64/devel/bin/quadrotor_msgs_matlab.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/m/" TYPE DIRECTORY FILES "D:/bag/matlab_msg_gen_ros1/win64/src/quadrotor_msgs/m/" FILES_MATCHING REGEX "/[^/]*\\.m$")
endif()

