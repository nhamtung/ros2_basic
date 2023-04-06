# Reference
- https://www.theconstructsim.com/how-to-create-a-ros2-c-library/

# Create a package
- Library package: $ros2 pkg create my_library --build-type ament_cmake
- Using package: $ros2 pkg create call_library --build-type ament_cmake --dependencies rclcpp std_msgs my_library

# Build
- $colcon build --packages-select my_library

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Test
- From others pkg: $ros2 run call_library call_lib