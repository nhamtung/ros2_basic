# Reference link: 
- https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Py-Service-And-Client.html

# Create Service package
- Directory to ros2_basic folder
- Create: $ros2 pkg create --build-type ament_python service_py_pkg --dependencies rclpy example_interfaces

# Check for missing dependencies before building
- $rosdep install -i --from-path src --rosdistro humble -y

# Build
- $colcon build --packages-select service_py_pkg

# Run service server
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run service_py_pkg service_server

# Run service client
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run service_py_pkg service_client 2 3