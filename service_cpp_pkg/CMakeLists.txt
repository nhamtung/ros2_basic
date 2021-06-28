cmake_minimum_required(VERSION 3.5)
project(service_cpp_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(msg_srv_pkg REQUIRED)

add_executable(service_server src/service_server.cpp)
ament_target_dependencies(service_server rclcpp example_interfaces)
add_executable(service_client src/service_client.cpp)
ament_target_dependencies(service_client rclcpp example_interfaces)

add_executable(test_srv_server src/test_srv_server.cpp)
ament_target_dependencies(test_srv_server rclcpp msg_srv_pkg)
add_executable(test_srv_client src/test_srv_client.cpp)
ament_target_dependencies(test_srv_client rclcpp msg_srv_pkg)

install(TARGETS
  service_server
  service_client
  test_srv_server
  test_srv_client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
