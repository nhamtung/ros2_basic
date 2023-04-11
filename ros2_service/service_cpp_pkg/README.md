# Reference link: 
- https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Service-And-Client.html
- Class: https://get-help.robotigniteacademy.com/t/ros2-service-client-in-c-with-classes-with-node-inheritance/19647

# Create Service package
- Directory to ros2_basic folder
- Create: $ros2 pkg create --build-type ament_cmake service_cpp_pkg --dependencies rclcpp example_interfaces

# Check for missing dependencies before building
- $rosdep install -i --from-path src --rosdistro humble -y

# Build
- $colcon build --packages-select service_cpp_pkg

# Run service server
- Directory to workspace
- Source: $. install/setup.bash
- Run: 
    + $ros2 run service_cpp_pkg service_server
    + Or: $ros2 run service_cpp_pkg service_server_class

# Run service client
- Directory to workspace
- Source: $. install/setup.bash
- Run: 
    + $ros2 run service_cpp_pkg service_client 2 3
    + Or: $ros2 run service_cpp_pkg service_client_class

# Test srv server
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run service_cpp_pkg test_srv_server

# Test srv client
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run service_cpp_pkg test_srv_client 2 3 1