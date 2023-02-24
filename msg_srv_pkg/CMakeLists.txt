cmake_minimum_required(VERSION 3.5)
project(msg_srv_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files 
  "msg/AddressBook.msg"
)
#set(srv_files
#  "srv/Service1.srv"
#)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "srv/SumSrv.srv"
  ${msg_files}
  #${srv_files}
  #DEPENDENCIES geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime)

add_executable(publish_address_book src/publish_address_book.cpp)
ament_target_dependencies(publish_address_book rclcpp)
rosidl_target_interfaces(publish_address_book ${PROJECT_NAME} "rosidl_typesupport_cpp")

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(publish_address_book "${cpp_typesupport_target}")

install(TARGETS 
  publish_address_book
  DESTINATION lib/${PROJECT_NAME})

ament_package()
