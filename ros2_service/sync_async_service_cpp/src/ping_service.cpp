#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/trigger.hpp"

/**
 * Service action: responds with success=true and prints the request on the console
 */
void ping(const std::shared_ptr<example_interfaces::srv::Trigger::Request> request,
        std::shared_ptr<example_interfaces::srv::Trigger::Response> response)
{
    // The request data is unused
    (void) request;

    // Build the response
    response->success = true;

    // Log to the console
    RCLCPP_INFO(rclcpp::get_logger("ping_server"), "Incoming request");
    RCLCPP_INFO(rclcpp::get_logger("ping_server"), "Sending back response");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Create the node and the service
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("ping_server");
    rclcpp::Service<example_interfaces::srv::Trigger>::SharedPtr service =
        node->create_service<example_interfaces::srv::Trigger>("ping", &ping);

    // Log that the service is ready
    RCLCPP_INFO(rclcpp::get_logger("ping_server"), "Ready to serve.");

    // run the node
    rclcpp::spin(node);
    rclcpp::shutdown();
}