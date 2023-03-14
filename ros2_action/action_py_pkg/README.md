# Reference link
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html

# Build
- $colcon build

# Test Server
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run action_py_pkg fibonacci_action_server

# Test Client
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 run action_py_pkg fibonacci_action_client

# Test Interface
- Directory to workspace
- Source: $. install/setup.bash
- Run: $ros2 action send_goal --feedback fibonacci action_tutorials_interfaces/action/Fibonacci "{order: 5}"