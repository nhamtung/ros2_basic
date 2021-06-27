# Reference link: 
- https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Service-And-Client.html

# Build
- $colcon build --packages-select service_cpp_pkg

# Run service server
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run service_cpp_pkg service_server

# Run service client
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run service_cpp_pkg service_client 2 3