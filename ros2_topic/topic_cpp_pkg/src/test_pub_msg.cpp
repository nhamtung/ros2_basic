#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "msg_pkg/msg/num.hpp"     // CHANGE

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher() : Node("msg_publisher"), count_(0){
      publisher_ = this->create_publisher<msg_pkg::msg::Num>("topic", 10);    // CHANGE
      timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback(){
      auto message = msg_pkg::msg::Num();                               // CHANGE
      message.num = this->count_++;                                        // CHANGE
      RCLCPP_INFO(this->get_logger(), "Publishing: %ld", message.num);    // CHANGE
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<msg_pkg::msg::Num>::SharedPtr publisher_;         // CHANGE
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}