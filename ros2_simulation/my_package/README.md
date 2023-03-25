# Reference:
- https://docs.ros.org/en/humble/Tutorials/Advanced/Simulators/Webots.html

# Build
- $colcon build --packages-select my_package

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Test
- Simulation: $ros2 launch my_package robot_launch.py
- Test: $ros2 topic pub /cmd_vel geometry_msgs/Twist  "linear: { x: 0.1 }"