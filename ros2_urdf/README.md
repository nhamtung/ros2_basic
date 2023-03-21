# Reference
- https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Building-a-Visual-Robot-Model-with-URDF-from-Scratch.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Building-a-Movable-Robot-Model-with-URDF.html
- https://docs.ros.org/en/humble/Tutorials/Intermediate/URDF/Adding-Physical-and-Collision-Properties-to-a-URDF-Model.html

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