cmake_minimum_required(VERSION 3.8)
project(sample_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(robot_startup REQUIRED)

# include_directories(
#   include
# )
# add_library(sample_lib src/sample_lib.cpp)
# ament_target_dependencies(sample_lib rclcpp std_msgs robot_startup)

add_executable(sample_node src/sample_node.cpp)
target_include_directories(sample_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(sample_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(sample_node rclcpp std_msgs robot_startup)


## Install library
# install(TARGETS loggers
#   EXPORT export_loggers
#   ARCHIVE DESTINATION lib
#   LIBRARY DESTINATION lib
#   INCLUDES DESTINATION include
# )
## Install headers
# install(DIRECTORY include/
#   DESTINATION include
# )
# Install executable
install(TARGETS sample_node
  DESTINATION lib/${PROJECT_NAME}
)
# Install launch files
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
