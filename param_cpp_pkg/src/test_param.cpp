// https://docs.ros.org/en/foxy/Tutorials/Using-Parameters-In-A-Class-CPP.html

#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <string>
#include <functional>

using namespace std::chrono_literals;

class ParametersClass: public rclcpp::Node
{
  public:
    ParametersClass() : Node("parameter_node"){
      this->declare_parameter<std::string>("test_parameter", "Robotics");
      timer_ = this->create_wall_timer(
      1000ms, std::bind(&ParametersClass::respond, this));
    }
    void respond(){
      this->get_parameter("test_parameter", parameter_string_);
      RCLCPP_INFO(this->get_logger(), "test_param.cpp - Hello %s", parameter_string_.c_str());
    }
  private:
    std::string parameter_string_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParametersClass>());
  rclcpp::shutdown();
  return 0;
}