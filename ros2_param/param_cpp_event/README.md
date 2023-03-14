# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Monitoring-For-Parameter-Changes-CPP.html

# Build
- $colcon build --packages-select param_cpp_event

# Run
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run param_cpp_event parameter_event_handler

# Set param
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 param set node_with_parameters an_int_param 43