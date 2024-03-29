#include "rclcpp/rclcpp.hpp"
#include "srv_pkg/srv/sum_srv.hpp"     // CHANGE
#include <memory>

void add(const std::shared_ptr<srv_pkg::srv::SumSrv::Request> request, std::shared_ptr<srv_pkg::srv::SumSrv::Response> response)  // CHANGE
{
  response->sum = request->a + request->b + request->c;                                       // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld" " c: %ld", request->a, request->b, request->c);                                          // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_server");  // CHANGE

  rclcpp::Service<srv_pkg::srv::SumSrv>::SharedPtr service = node->create_service<srv_pkg::srv::SumSrv>("add_three_ints",  &add);     // CHANGE

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add three ints.");      // CHANGE

  rclcpp::spin(node);
  rclcpp::shutdown();
}