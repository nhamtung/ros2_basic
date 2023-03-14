# Reference link:
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Launch-system.html

# Build
- $colcon build --packages-select cpp_launch_example

# Publish the topic
- Directory to workspace
- Source: $. install/setup.bash
- Run: 
    + $ros2 launch cpp_launch_example launch.py
    + $ros2 launch cpp_launch_example launch.xml
    + $ros2 launch cpp_launch_example launch.yaml
