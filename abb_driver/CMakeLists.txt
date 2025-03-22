cmake_minimum_required(VERSION 3.14)
project(abb_driver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
# find_package(industrial_robot_client REQUIRED)
find_package(simple_message REQUIRED)

add_executable(robot_state
  src/abb_robot_state_node.cpp
  src/abb_utils.cpp)
ament_target_dependencies(robot_state
  industrial_robot_client
  simple_message)

add_executable(motion_download_interface
  src/abb_joint_downloader_node.cpp
  src/abb_utils.cpp)
ament_target_dependencies(motion_download_interface
  industrial_robot_client
  simple_message)

install(TARGETS
  robot_state
  motion_download_interface
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch rapid
  DESTINATION share/${PROJECT_NAME})

ament_package()
