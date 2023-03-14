# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/Launch/Creating-Launch-Files.html

# Run directly
- Directory to launch folder
- Run: 
    + $ros2 launch turtlesim_mimic_launch.py
    + $ros2 launch turtlesim_mimic_launch.xml
    + $ros2 launch turtlesim_mimic_launch.yaml

# Run with package
- Add command to package.xml file: <exec_depend>ros2launch</exec_depend>
- Directory to workspace
- Source: $. install/setup.bash
- ros2 launch <package_name> <launch_file_name>