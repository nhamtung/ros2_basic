# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Static-Broadcaster-Py.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Broadcaster-Py.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Listener-Py.html

# Build
- $colcon build --packages-select learning_tf2_py

# --- Writing a static broadcaster ---
# Set static broadcaster
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run learning_tf2_py static_turtle_tf2_broadcaster mystaticturtle 0 0 1 0 0 0
- Launch: $ros2 launch learning_tf2_py learning_tf2.launch.py

# Check static broadcaster
- Directory to workspace
- Source: $. install/setup.bash
- $ros2 topic echo /tf_static

# --- Writing a broadcaster ---
# Test broadcaster
- Directory to workspace
- Source: $. install/setup.bash
- Launch: $ros2 launch learning_tf2_py turtle_tf2_demo.launch.py

# Test move
- Directory to workspace
- Source: $. install/setup.bash
- Launch: $ros2 run turtlesim turtle_teleop_key

# Check broadcaster
- Directory to workspace
- Source: $. install/setup.bash
- $ros2 run tf2_ros tf2_echo world turtle1

# --- Writing a listener ---
# Test listener
- Directory to workspace
- Source: $. install/setup.bash
- Launch: $ros2 launch learning_tf2_py turtle_tf2_demo.launch.py

# Test move
- Directory to workspace
- Source: $. install/setup.bash
- Launch: $ros2 run turtlesim turtle_teleop_key