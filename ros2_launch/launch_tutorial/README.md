# Reference link:
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Using-Substitutions.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Using-Event-Handlers.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Using-ROS2-Launch-For-Large-Projects.html

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

# Test event handlers
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 launch launch_tutorial example_event_handlers.launch.py turtlesim_ns:='turtlesim3' use_provided_red:='True' new_background_r:=200

# Managing large projects
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 launch launch_tutorial launch_turtlesim.launch.py
- Control: $ros2 run turtlesim turtle_teleop_key