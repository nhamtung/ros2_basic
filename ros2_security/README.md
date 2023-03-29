# Reference link: 
- Security: https://docs.ros.org/en/humble/Tutorials/Advanced/Security/Introducing-ros2-security.html
- Keystore: https://docs.ros.org/en/humble/Tutorials/Advanced/Security/The-Keystore.html
- Security-on-Two: https://docs.ros.org/en/humble/Tutorials/Advanced/Security/Security-on-Two.html
- Traffic: https://docs.ros.org/en/humble/Tutorials/Advanced/Security/Examine-Traffic.html#id5
- Access: https://docs.ros.org/en/humble/Tutorials/Advanced/Security/Access-Controls.html
- Deployment: https://docs.ros.org/en/humble/Tutorials/Advanced/Security/Deployment-Guidelines.html

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

# Setting access controls
- Sign the policy file: $openssl smime -sign -text -in ./sros2/demo_keystore/enclaves/talker_listener/talker/permissions.xml -out ./sros2/demo_keystore/enclaves/talker_listener/talker/permissions.p7s --signer ./sros2/demo_keystore/enclaves/talker_listener/talker/permissions_ca.cert.pem -inkey ./sros2/demo_keystore/private/permissions_ca.key.pem
- Test: 
    + Talker: $ros2 run demo_nodes_cpp talker --ros-args --enclave /talker_listener/talker
    + And   : $ros2 run demo_nodes_cpp talker --ros-args --enclave /talker_listener/talker --remap chatter:=not_chatter

- Clone sros2 package: $git clone https://github.com/ros2/sros2.git /tmp/sros2
- Create permission with sros2 package:
    + $ros2 security create_permission ./sros2/demo_keystore /talker_listener/talker /tmp/sros2/sros2/test/policies/sample.policy.xml
    + $ros2 security create_permission ./sros2/demo_keystore /talker_listener/listener /tmp/sros2/sros2/test/policies/sample.policy.xml
- Test:
    + ros2 run demo_nodes_cpp talker --ros-args -e /talker_listener/talker
    + $ros2 run demo_nodes_py listener --ros-args -e /talker_listener/listener
- Check access: $ros2 run demo_nodes_py listener --ros-args --enclave /talker_listener/listener --remap chatter:=not_chatter

# Deployment
- Directory: $cd ./src/ros2_basic/ros2_security
- Generating the Docker Image: $sudo docker build -t ros2_security/deployment_tutorial --build-arg ROS_DISTRO=humble .
- Run: $sudo docker compose -f compose.deployment.yaml up
- Check:
    + $sudo docker exec -it tutorial-listener-1 bash
    + $cd keystore
    + $tree