#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "msg_pkg/msg/num.hpp"     // CHANGE
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber() : Node("msg_subscriber"){
      subscription_ = this->create_subscription<msg_pkg::msg::Num>("topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const msg_pkg::msg::Num::SharedPtr msg) const {
      RCLCPP_INFO(this->get_logger(), "I heard: '%ld'", msg->num);              // CHANGE
    }
    rclcpp::Subscription<msg_pkg::msg::Num>::SharedPtr subscription_;       // CHANGE
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}