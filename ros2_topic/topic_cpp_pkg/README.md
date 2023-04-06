# Reference
- Package: https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html
- Msg: https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html
- Topic Statistics: https://docs.ros.org/en/humble/Tutorials/Advanced/Topic-Statistics-Tutorial/Topic-Statistics-Tutorial.html
- Discovery Server: https://docs.ros.org/en/humble/Tutorials/Advanced/Discovery-Server/Discovery-Server.html

# Create a package
- $ros2 pkg create --build-type ament_cmake topic_cpp_pkg

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

# Using Fast DDS Discovery Server
- Setup Discovery Server: $fastdds discovery --server-id 0 --ip-address 127.0.0.1 --port 11811
- Listener: 
    + Set the environment variable: $export ROS_DISCOVERY_SERVER=127.0.0.1:11811
    + Run: $ros2 run topic_cpp_pkg test_sub_msg --ros-args --remap __node:=listener_discovery_server
- Talker 1: 
    + Set the environment variable: $export ROS_DISCOVERY_SERVER=127.0.0.1:11811
    + Run: $ros2 run topic_cpp_pkg test_pub_msg --ros-args --remap __node:=talker_discovery_server
- Talker 2: 
    + Set the environment variable: $export ROS_DISCOVERY_SERVER=127.0.0.1:11811
    + Run: $ros2 run topic_cpp_pkg test_pub_msg --ros-args --remap __node:=talker_discovery_server
- Echo: $ros2 topic list