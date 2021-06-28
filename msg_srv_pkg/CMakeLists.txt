cmake_minimum_required(VERSION 3.5)
project(msg_srv_pkg)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "srv/SumSrv.srv"
)

ament_package()
