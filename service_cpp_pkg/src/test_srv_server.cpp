// https://docs.ros.org/en/foxy/Tutorials/Custom-ROS2-Interfaces.html

#include "rclcpp/rclcpp.hpp"
#include "msg_srv_pkg/srv/sum_srv.hpp"     // CHANGE
#include <memory>

void add(const std::shared_ptr<msg_srv_pkg::srv::SumSrv::Request> request, std::shared_ptr<msg_srv_pkg::srv::SumSrv::Response> response)  // CHANGE
{
  response->sum = request->a + request->b + request->c;                                       // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "test_srv_server.cpp - Incoming request\na: %ld" " b: %ld" " c: %ld", request->a, request->b, request->c);                                          // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "test_srv_server.cpp - sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_server");  // CHANGE

  rclcpp::Service<msg_srv_pkg::srv::SumSrv>::SharedPtr service = node->create_service<msg_srv_pkg::srv::SumSrv>("add_three_ints",  &add);     // CHANGE

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "test_srv_server.cpp - Ready to add three ints.");      // CHANGE

  rclcpp::spin(node);
  rclcpp::shutdown();
}