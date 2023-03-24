#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class SyncAsyncSubscriber : public rclcpp::Node
{
    public:

        SyncAsyncSubscriber(): Node("sync_async_subscriber")
        {
            // Create the synchronous subscriber on topic 'sync_topic'
            // and tie it to the topic_callback
            sync_subscription_ = this->create_subscription<std_msgs::msg::String>("sync_topic", 10, std::bind(&SyncAsyncSubscriber::topic_callback, this, _1));

            // Create the asynchronous subscriber on topic 'async_topic'
            // and tie it to the topic_callback
            async_subscription_ = this->create_subscription<std_msgs::msg::String>("async_topic", 10, std::bind(&SyncAsyncSubscriber::topic_callback, this, _1));
        }

    private:

        /**
        * Actions to run every time a new message is received
        */
        void topic_callback(const std_msgs::msg::String & msg) const{
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
        }

        // A subscriber that listens to topic 'sync_topic'
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sync_subscription_;

        // A subscriber that listens to topic 'async_topic'
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr async_subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SyncAsyncSubscriber>());
    rclcpp::shutdown();
    return 0;
}