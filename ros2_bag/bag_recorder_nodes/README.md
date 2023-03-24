# Reference:
- https://docs.ros.org/en/humble/Tutorials/Advanced/Recording-A-Bag-From-Your-Own-Node-CPP.html

# Build
- $colcon build --packages-select bag_recorder_nodes

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Test record bag file
- Record: $ros2 run bag_recorder_nodes simple_bag_recorder
- Talker: $ros2 run demo_nodes_cpp talker
- Listener: $ros2 run demo_nodes_cpp listener
- Play: $ros2 bag play my_bag

# Record synthetic data from a node
- Record: $ros2 run bag_recorder_nodes data_generator_node
- Play: $ros2 bag play timed_synthetic_bag
- Check: $ros2 topic echo /synthetic