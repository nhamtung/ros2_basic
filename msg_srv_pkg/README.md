# Build
- $colcon build --packages-select msg_srv_pkg
- Source: $. install/setup.bash

# Show msg
- Run: $ros2 msg show msg_srv_pkg/msg/Num

# Show srv
- Run: $ros2 srv show msg_srv_pkg/srv/SumSrv