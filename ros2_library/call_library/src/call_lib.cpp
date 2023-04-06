#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
 
#include "my_library/library_header.h"
 
class ConverterNode : public rclcpp::Node {
    public:
        explicit ConverterNode() : Node("converter_node") {
            double new_value = map_value(10, 0, 1023, -1.0, 1.0);
            RCLCPP_INFO(this->get_logger(), "new_value: %lf", new_value);
        }
};
 
int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ConverterNode>();
    RCLCPP_INFO(node->get_logger(), "Finished");
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
