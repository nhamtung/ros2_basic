#include <memory>
#include <thread>
#include <atomic>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "robot_startup/dynparam.hpp"
#include "robot_startup/diagnostic.hpp"

using std::placeholders::_1;

class SampleNode : public rclcpp::Node, public ParamHandler
{
  public:
    SampleNode() : Node("sample_node"), ParamHandler(this){
      chatter_sub_ = this->create_subscription<std_msgs::msg::String>("chatter", 10, std::bind(&SampleNode::chatterCallback, this, _1));
    }
    ~SampleNode() {
      stop_thread_ = true;
      if(loop_thread_.joinable()){
        loop_thread_.join();
      }
    }
    void init(){
      initDiagnostic();
      loadParam();

      stop_thread_ = false;
      loop_thread_ = std::thread(&SampleNode::loopFunction, this);
      
      diagnostic_->addAndPubDiagnostic(sample_node_, OperatorLevel::OPERATOR_OK, 0, "manage_loggers node has been started.");
    }

  private:
    void loadParam(){
      // max_speed
      this->declare_parameter("max_speed", max_speed_);
      max_speed_handle_ = this->addRemoteParameterCallback("control_navigation", "max_speed", [this](const rclcpp::Parameter & p) {
        RCLCPP_INFO(this->get_logger(), "Received an update parameter from other node \"%s\" of type: %s: \"%.02lf\"", p.get_name().c_str(),p.get_type_name().c_str(),p.as_double());
        max_speed_ = p.as_double();
        diagnostic_->addAndPubDiagnostic(sample_node_, OperatorLevel::OPERATOR_OK, 0, "Received an update parameter max_speed from control_navigation: " + std::to_string(max_speed_));
      });
    }
    void initDiagnostic()
    {
        diagnostic_ = std::make_shared<Diagnostic>(this, "sample_node");

        sample_node_ = std::make_shared<diagnostic_msgs::msg::DiagnosticStatus>();
        sample_node_->name = "sample_node";
        sample_node_->hardware_id = "None";
        sample_node_->level = diagnostic_msgs::msg::DiagnosticStatus::STALE;
        sample_node_->message = "Starting up";

        diagnostic_->addStatusElement(sample_node_);
        diagnostic_->pubDiagnostic();
    }
    void loopFunction()
    {
      rclcpp::Rate rate(1); // 1 Hz
      while(!stop_thread_){
        // Do something
        rate.sleep();
      }
    }
    void chatterCallback(const std_msgs::msg::String::SharedPtr msg) {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      diagnostic_->addAndPubDiagnostic(sample_node_, OperatorLevel::OPERATOR_OK, 3, "I heard: " + msg->data);
    }

  private:
    // Subscription
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr chatter_sub_;

    // Thread
    std::thread loop_thread_;
    std::atomic<bool> stop_thread_{false};

    // Diagnostic
    std::shared_ptr<Diagnostic> diagnostic_;
    std::shared_ptr<diagnostic_msgs::msg::DiagnosticStatus> sample_node_;

    // Parameters
    double max_speed_{0.5};
    std::shared_ptr<rclcpp::ParameterCallbackHandle> max_speed_handle_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SampleNode>();
  node->init();
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}