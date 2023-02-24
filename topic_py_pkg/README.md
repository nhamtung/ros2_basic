# Reference
- https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Py-Publisher-And-Subscriber.html

# Build
- $colcon build

# Publish the topic
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run topic_py_pkg talker

# Subscriber the topic
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run topic_py_pkg listener