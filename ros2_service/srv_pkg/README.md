# Reference link:
- https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html
- https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Single-Package-Define-And-Use-Interface.html

# Create package
- Directory to ros2_basic folder
- Create: $ros2 pkg create srv_pkg --build-type ament_cmake --dependencies rclcpp

# Check for missing dependencies before building
- $rosdep install -i --from-path src --rosdistro humble -y

# Build
- $colcon build --packages-select srv_pkg
- Source: $. install/setup.bash

# Show srv
- Run: $ros2 interface show srv_pkg/srv/SumSrv
