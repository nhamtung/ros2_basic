# Reference:
- https://docs.ros.org/en/humble/Tutorials/Advanced/FastDDS-Configuration.html

# Build
- $colcon build --packages-select sync_async_node_example_cpp

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash
- Export:
    + $export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
    + $export RMW_FASTRTPS_USE_QOS_FROM_XML=1
    + $export FASTRTPS_DEFAULT_PROFILES_FILE=./src/ros2_basic/ros2_topic/sync_async_node_example_cpp/SyncAsync.xml

# Test
- Writer: $ros2 run sync_async_node_example_cpp SyncAsyncWriter
- Reader: $ros2 run sync_async_node_example_cpp SyncAsyncReader