# Reference link:
- https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html
- https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Single-Package-Define-And-Use-Interface.html

# Create package
- Directory to folder
- Create: $ros2 pkg create msg_pkg --build-type ament_cmake --dependencies rclcpp

# Check for missing dependencies before building
- $rosdep install -i --from-path src --rosdistro humble -y

# Build
- $colcon build --packages-select msg_pkg
- Source: $. install/setup.bash

# Show msg
- Run: $ros2 interface show msg_pkg/msg/Num

# Test Msg
- Run: $ros2 run msg_pkg publish_address_book