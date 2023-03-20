# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Static-Broadcaster-Cpp.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Broadcaster-Cpp.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Writing-A-Tf2-Listener-Cpp.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Adding-A-Frame-Cpp.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Tf2/Using-Stamped-Datatypes-With-Tf2-Ros-MessageFilter.html

# Build
- $colcon build --packages-select learning_tf2_cpp

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Test move
- Run: $ros2 run turtlesim turtle_teleop_key

# View frame
- Run: $ros2 run tf2_tools view_frames

# Writing a static broadcaster
## Set static broadcaster
- Run: $ros2 run learning_tf2_cpp static_turtle_tf2_broadcaster mystaticturtle 0 0 1 0 0 0
- Launch: $ros2 launch learning_tf2_cpp learning_tf2.launch.py
## Check static broadcaster
- $ros2 topic echo /tf_static

# Writing a broadcaster
- Test broadcaster: $ros2 launch learning_tf2_cpp turtle_tf2_demo.launch.py
- Check broadcaster: $ros2 run tf2_ros tf2_echo world turtle1

# Writing a listener
- Launch: $ros2 launch learning_tf2_cpp turtle_tf2_listener.launch.py

# Adding a frame
- Launch: $ros2 launch learning_tf2_cpp turtle_tf2_fixed_frame_demo.launch.py
- Add frame: $ros2 launch learning_tf2_cpp turtle_tf2_fixed_frame_demo.launch.py target_frame:=carrot1
- Write the dynamic frame broadcaster: $ros2 launch learning_tf2_cpp turtle_tf2_dynamic_frame_demo.launch.py

# Using stamped datatypes with tf2_ros::MessageFilter
- Launch: $ros2 launch learning_tf2_py turtle_tf2_sensor_message.launch.py
- Echo: $ros2 topic echo /turtle3/turtle_point_stamped
- Run: $ros2 run learning_tf2_cpp turtle_tf2_message_filter