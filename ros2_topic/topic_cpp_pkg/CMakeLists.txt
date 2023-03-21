cmake_minimum_required(VERSION 3.5)
project(topic_cpp_pkg)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(msg_pkg REQUIRED)   

add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(test_pub_msg src/test_pub_msg.cpp)
ament_target_dependencies(test_pub_msg rclcpp msg_pkg)
add_executable(test_sub_msg src/test_sub_msg.cpp)
ament_target_dependencies(test_sub_msg rclcpp msg_pkg)

add_executable(listener_with_topic_statistics src/member_function_with_topic_statistics.cpp)
ament_target_dependencies(listener_with_topic_statistics rclcpp std_msgs)

install(TARGETS
  talker
  listener
  test_pub_msg
  test_sub_msg
  listener_with_topic_statistics
  DESTINATION lib/${PROJECT_NAME})

ament_package()
