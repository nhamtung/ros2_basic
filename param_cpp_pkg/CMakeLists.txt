cmake_minimum_required(VERSION 3.5)
project(param_cpp_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(test_param src/test_param.cpp)
ament_target_dependencies(test_param rclcpp)

install(TARGETS
  test_param
  DESTINATION lib/${PROJECT_NAME}
)
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
