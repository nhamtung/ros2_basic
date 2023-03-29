# Reference
- Intra-process: https://docs.ros.org/en/humble/Tutorials/Demos/Intra-Process-Communication.html
- Example code: https://github.com/ros2/demos/tree/humble/intra_process_demo/src

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Create package
- Direct to the folder: $./src/ros2_basic/ros2_demos
- Create cpp pkg: $ros2 pkg create --build-type ament_cmake intra_process

# Build
- $colcon build --packages-select intra_process

# Executable
- One node: $ros2 run intra_process two_node_pipeline
- Two node: $ros2 run intra_process cyclic_pipeline
