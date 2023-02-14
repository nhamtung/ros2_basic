// https://docs.ros.org/en/foxy/Tutorials/Single-Package-Define-And-Use-Interface.html

#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "msg_srv_pkg/msg/address_book.hpp"

using namespace std::chrono_literals;

class AddressBookPublisher : public rclcpp::Node
{
  public:
    AddressBookPublisher() : Node("address_book_publisher"){
      address_book_publisher_ = this->create_publisher<msg_srv_pkg::msg::AddressBook>("address_book", 10);

      auto publish_msg = [this]() -> void {
          auto message = msg_srv_pkg::msg::AddressBook();

          message.first_name = "John";
          message.last_name = "Doe";
          message.age = 30;
          message.gender = message.MALE;
          message.address = "unknown";

          std::cout << "publish_address_book.cpp - Publishing Contact - First:" << message.first_name << "  Last:" << message.last_name << std::endl;

          this->address_book_publisher_->publish(message);
        };
      timer_ = this->create_wall_timer(1s, publish_msg);
    }

  private:
    rclcpp::Publisher<msg_srv_pkg::msg::AddressBook>::SharedPtr address_book_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddressBookPublisher>());
  rclcpp::shutdown();

  return 0;
}