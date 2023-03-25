# Reference link: 
- https://docs.ros.org/en/humble/Tutorials/Advanced/Security/Introducing-ros2-security.html

# Requirement:
- Install libssl-dev: $sudo apt install libssl-dev

# Build
- $colcon build --symlink-install --cmake-args -DSECURITY=ON

# Create security file
- Directory to workspace
- Create folder: $mkdir sros2 && cd sros2
- Generate a keystore: $ros2 security create_keystore demo_keystore
- Generate keys and certificates for topic:
    + $ros2 security create_enclave demo_keystore /talker_listener/talker
    + $ros2 security create_enclave demo_keystore /talker_listener/listener

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash
- Configure environment variables:
    + $export ROS_SECURITY_KEYSTORE=./sros2/demo_keystore && export ROS_SECURITY_ENABLE=true && export ROS_SECURITY_STRATEGY=Enforce

# Test
- Talker: $ros2 run demo_nodes_cpp talker --ros-args --enclave /talker_listener/talker
- Listener: $ros2 run demo_nodes_py listener --ros-args --enclave /talker_listener/listener
- Test: $ros2 topic echo /chatter