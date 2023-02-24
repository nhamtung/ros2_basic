# Reference
- https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html
- https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html

# Build
- $colcon build --packages-select topic_cpp_pkg

# Publish the topic
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run topic_cpp_pkg talker

# Subscriber the topic
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run topic_cpp_pkg listener

# Publish test msg
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run topic_cpp_pkg test_pub_msg

# Subscriber test msg
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run topic_cpp_pkg test_sub_msg