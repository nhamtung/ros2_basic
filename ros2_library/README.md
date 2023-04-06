# Reference
- https://www.theconstructsim.com/how-to-create-a-ros2-c-library/

# Create a library package
- $ros2 pkg create my_library --build-type ament_cmake

# Build
- $colcon build --packages-select my_library

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Test
- From others pkg: $ros2 run call_library call_lib