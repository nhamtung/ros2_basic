// https://docs.ros.org/en/foxy/Tutorials/Custom-ROS2-Interfaces.html

#include "rclcpp/rclcpp.hpp"
#include "msg_srv_pkg/srv/sum_srv.hpp"        // CHANGE
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 4) { // CHANGE
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "test_srv_client.cpp - usage: add_three_ints_client X Y Z");      // CHANGE
      return 1;
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_client"); // CHANGE
  rclcpp::Client<msg_srv_pkg::srv::SumSrv>::SharedPtr client =                        // CHANGE
    node->create_client<msg_srv_pkg::srv::SumSrv>("add_three_ints");                  // CHANGE

  auto request = std::make_shared<msg_srv_pkg::srv::SumSrv::Request>();               // CHANGE
  request->a = atoll(argv[1]);
  request->b = atoll(argv[2]);
  request->c = atoll(argv[3]);               // CHANGE

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "test_srv_client.cpp - Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "test_srv_client.cpp - service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS){
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "test_srv_client.cpp - Sum: %ld", result.get()->sum);
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "test_srv_client.cpp - Failed to call service add_three_ints");    // CHANGE
  }

  rclcpp::shutdown();
  return 0;
}