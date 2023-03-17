# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Static-Broadcaster-Py.html

# Build
- $colcon build --packages-select learning_tf2_py

# Run demo
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run learning_tf2_py static_turtle_tf2_broadcaster mystaticturtle 0 0 1 0 0 0
- Launch: $ros2 launch learning_tf2_py learning_tf2.launch.py

# Check
- Directory to workspace
- Source: $. install/setup.bash
- $ros2 topic echo /tf_static