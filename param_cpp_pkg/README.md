# Reference link: 
- https://docs.ros.org/en/foxy/Tutorials/Using-Parameters-In-A-Class-CPP.html

# Build
- $colcon build --packages-select param_cpp_pkg

# Run test param
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run param_cpp_pkg test_param

# Change via console
- $ros2 param list
- $ros2 param set /parameter_node test_parameter earth