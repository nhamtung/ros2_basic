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