# Reference link: 
- https://docs.ros.org/en/foxy/Tutorials/Using-Parameters-In-A-Class-Python.html

# Build
- $colcon build --packages-select param_py_pkg

# Run test param
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run param_py_pkg test_param

# Change via console
- $ros2 param list
- $ros2 param set /parameter_node test_parameter TungNV

# Change via launch file
- $ros2 launch param_py_pkg param_launch.py