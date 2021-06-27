cmake_minimum_required(VERSION 3.5)
project(service_cpp_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(service_server src/service_server.cpp)
ament_target_dependencies(service_server rclcpp example_interfaces)
add_executable(service_client src/service_client.cpp)
ament_target_dependencies(service_client rclcpp example_interfaces)

install(TARGETS
  service_server
  service_client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
