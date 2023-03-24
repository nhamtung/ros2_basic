#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/trigger.hpp"

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Create the node and the client
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("ping_client");
    rclcpp::Client<example_interfaces::srv::Trigger>::SharedPtr client =
        node->create_client<example_interfaces::srv::Trigger>("ping");

    // Create a request
    auto request = std::make_shared<example_interfaces::srv::Trigger::Request>();

    // Wait for the service to be available
    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("ping_client"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("ping_client"), "Service not available, waiting again...");
    }

    // Now that the service is available, send the request
    RCLCPP_INFO(rclcpp::get_logger("ping_client"), "Sending request");
    auto result = client->async_send_request(request);

    // Wait for the result and log it to the console
    if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(rclcpp::get_logger("ping_client"), "Response received");
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("ping_client"), "Failed to call service ping");
    }

    rclcpp::shutdown();
    return 0;
}