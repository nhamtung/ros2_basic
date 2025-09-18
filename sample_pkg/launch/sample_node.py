from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sample_pkg',
            executable='sample_node',
            name='sample_node',
            output='screen',
            parameters=[{'max_speed': 0.3}]
        )
    ])