# Reference link:
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Using-Substitutions.html

# Build
- $colcon build --packages-select launch_tutorial

# Run main node
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 launch launch_tutorial example_main.launch.py

# Run substitutions node
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 launch launch_tutorial example_substitutions.launch.py turtlesim_ns:='turtlesim3' use_provided_red:='True' new_background_r:=200

# Show the arguments
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 launch launch_tutorial example_substitutions.launch.py --show-args
