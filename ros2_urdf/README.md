# Reference
- Static: https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Building-a-Visual-Robot-Model-with-URDF-from-Scratch.html
- Movable: https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Building-a-Movable-Robot-Model-with-URDF.html
- Collision & Inertia: https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Adding-Physical-and-Collision-Properties-to-a-URDF-Model.html
- Xacro: https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Using-Xacro-to-Clean-Up-a-URDF-File.html
- robot_state_publisher: https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Using-URDF-with-Robot-State-Publisher.html

# Requirement
- Install urdf_tutorial package: $sudo apt install ros-humble-urdf-tutorial

# Source when open new terminal
- Directory to workspace
- Source: $. install/setup.bash

# Building a visual robot model from scratch
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/01-myfirst.urdf
    Or: $ros2 launch urdf_tutorial display.launch.py model:=`ros2 pkg prefix --share urdf_tutorial`/urdf/01-myfirst.urdf
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/02-multipleshapes.urdf
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/03-origins.urdf
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/04-materials.urdf
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/05-visual.urdf

# Building a movable robot model
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/06-flexible.urdf

# Adding physical and collision properties
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/07-physics.urdf

# Using Xacro to clean up your code
- Launch: $ros2 launch urdf_tutorial display.launch.py model:=./src/ros2_basic/ros2_urdf/urdf/08-macroed.urdf.xacro

# Using URDF with robot_state_publisher
- Launch: $ros2 launch urdf_tutorial_r2d2 demo.launch.py
- Rviz: $rviz2 -d ./src/ros2_basic/ros2_urdf/urdf_tutorial_r2d2/urdf/r2d2.rviz