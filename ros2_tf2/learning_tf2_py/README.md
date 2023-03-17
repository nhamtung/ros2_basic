# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Static-Broadcaster-Py.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Broadcaster-Py.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Listener-Py.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Adding-A-Frame-Py.html

# Build
- $colcon build --packages-select learning_tf2_py

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Test move
- Run: $ros2 run turtlesim turtle_teleop_key

# View frame
- Run: $ros2 run tf2_tools view_frames

# Writing a static broadcaster
## Set static broadcaster
- Run: $ros2 run learning_tf2_py static_turtle_tf2_broadcaster mystaticturtle 0 0 1 0 0 0
- Launch: $ros2 launch learning_tf2_py learning_tf2.launch.py
## Check static broadcaster
- $ros2 topic echo /tf_static

# Writing a broadcaster
- Test broadcaster: $ros2 launch learning_tf2_py turtle_tf2_demo.launch.py
- Check broadcaster: $ros2 run tf2_ros tf2_echo world turtle1

# Writing a listener
- Launch: $ros2 launch learning_tf2_py turtle_tf2_listener.launch.py

# Adding a frame
- Launch: $ros2 launch learning_tf2_py turtle_tf2_fixed_frame_demo.launch.py
- Add frame: $ros2 launch learning_tf2_py turtle_tf2_fixed_frame_demo.launch.py target_frame:=carrot1
- Write the dynamic frame broadcaster: $ros2 launch learning_tf2_py turtle_tf2_dynamic_frame_demo.launch.py
