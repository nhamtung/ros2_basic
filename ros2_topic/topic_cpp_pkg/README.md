# Reference
- Msg: https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html
- Example: https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html
- Topic Statistics: https://docs.ros.org/en/humble/Tutorials/Advanced/Topic-Statistics-Tutorial/Topic-Statistics-Tutorial.html

# Build
- $colcon build --packages-select topic_cpp_pkg

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Publish the topic
- Run: $ros2 run topic_cpp_pkg talker

# Subscriber the topic
- Run: $ros2 run topic_cpp_pkg listener

# Publish test msg
- Run: $ros2 run topic_cpp_pkg test_pub_msg

# Subscriber test msg
- Run: $ros2 run topic_cpp_pkg test_sub_msg

# Enabling topic statistics
- Run: $ros2 run topic_cpp_pkg listener_with_topic_statistics
- Run: $ros2 run topic_cpp_pkg talker