cmake_minimum_required(VERSION 3.8)
project(call_library)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(my_library REQUIRED)

# define the binary to be built and identify the source files with with which to build it
add_executable(call_lib src/call_lib.cpp)
# tell CMake that the executable "call_lib" depends on the library "my_library"
ament_target_dependencies(call_lib my_library rclcpp std_msgs)

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

# install the executable in the lib folder to make it detectable through setup.bash
install(TARGETS
  call_lib
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
