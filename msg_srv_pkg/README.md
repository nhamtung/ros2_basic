# Reference link:
- https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html

# Create package
- Directory to ros2_basic folder
- Create: $ros2 pkg create --build-type ament_cmake msg_srv_pkg

# Check for missing dependencies before building
- $rosdep install -i --from-path src --rosdistro humble -y

# Build
- $colcon build --packages-select msg_srv_pkg
- Source: $. install/setup.bash

# Show msg
- Run: $ros2 interface show msg_srv_pkg/msg/Num

# Show srv
- Run: $ros2 interface show msg_srv_pkg/srv/SumSrv