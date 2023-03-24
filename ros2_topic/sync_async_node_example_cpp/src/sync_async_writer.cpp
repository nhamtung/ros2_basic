#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class SyncAsyncPublisher : public rclcpp::Node
{
public:
    SyncAsyncPublisher(): Node("sync_async_publisher"), count_(0)
    {
        // Create the synchronous publisher on topic 'sync_topic'
        sync_publisher_ = this->create_publisher<std_msgs::msg::String>("sync_topic", 10);

        // Create the asynchronous publisher on topic 'async_topic'
        async_publisher_ = this->create_publisher<std_msgs::msg::String>("async_topic", 10);

        // This timer will trigger the publication of new data every half a second
        timer_ = this->create_wall_timer(500ms, std::bind(&SyncAsyncPublisher::timer_callback, this));
    }

private:
    /**
     * Actions to run every time the timer expires
     */
    void timer_callback(){
        // Create a new message to be sent
        auto sync_message = std_msgs::msg::String();
        sync_message.data = "SYNC: Hello, world! " + std::to_string(count_);

        // Log the message to the console to show progress
        RCLCPP_INFO(this->get_logger(), "Synchronously publishing: '%s'", sync_message.data.c_str());

        // Publish the message using the synchronous publisher
        sync_publisher_->publish(sync_message);

        // Create a new message to be sent
        auto async_message = std_msgs::msg::String();
        async_message.data = "ASYNC: Hello, world! " + std::to_string(count_);

        // Log the message to the console to show progress
        RCLCPP_INFO(this->get_logger(), "Asynchronously publishing: '%s'", async_message.data.c_str());

        // Publish the message using the asynchronous publisher
        async_publisher_->publish(async_message);

        // Prepare the count for the next message
        count_++;
    }

    // This timer will trigger the publication of new data every half a second
    rclcpp::TimerBase::SharedPtr timer_;

    // A publisher that publishes asynchronously
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr async_publisher_;

    // A publisher that publishes synchronously
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr sync_publisher_;

    // Number of messages sent so far
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SyncAsyncPublisher>());
    rclcpp::shutdown();
    return 0;
}