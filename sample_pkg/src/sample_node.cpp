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
    ~SampleNode() {}

    void init(){
      initDiagnostic();
      loadParam();

      loop_timer_ = this->create_wall_timer(std::chrono::duration<double>(0.5), std::bind(&SampleNode::loopFunction, this));
      diagnostic_->addAndPubDiagnostic(sample_node, OperatorLevel::OPERATOR_OK, 0, "manage_loggers node has been started.");
    }

  private:
    // Thread
    rclcpp::TimerBase::SharedPtr loop_timer_;

    // Diagnostic
    std::shared_ptr<Diagnostic> diagnostic_;
    std::shared_ptr<diagnostic_msgs::msg::DiagnosticStatus> sample_node;

    // Subscription
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr chatter_sub_;

    // Parameters
    double max_speed{0.5};
    int32_t available_disk_threshold = 10000; // MB

  private:
    void loadParam(){
      // max_speed
      this->declare_parameter("max_speed", max_speed);
      this->get_parameter("max_speed", max_speed);
      this->addParameterCallback("max_speed", [this](const rclcpp::Parameter & p) {
        max_speed = p.as_double();
        std::string message = "Updated " + p.get_name() + " = " + std::to_string(max_speed) + " (" + p.get_type_name() + ")";
        diagnostic_->addAndPubDiagnostic(sample_node, OperatorLevel::OPERATOR_OK, 0, message);
      });
      // available_disk_threshold
      this->get_parameter("available_disk_threshold", available_disk_threshold);
      this->addRemoteParameterCallback("manage_informations", "available_disk_threshold", [this](const rclcpp::Parameter & p) {
        available_disk_threshold = p.as_int();
        std::string message = "Updated " + p.get_name() + " = " + std::to_string(available_disk_threshold) + " (" + p.get_type_name() + ")";
        diagnostic_->addAndPubDiagnostic(sample_node, OperatorLevel::OPERATOR_OK, 0, message);
      });
    }
    void initDiagnostic()
    {
        diagnostic_ = std::make_shared<Diagnostic>(this, "sample_node");

        sample_node = std::make_shared<diagnostic_msgs::msg::DiagnosticStatus>();
        sample_node->name = "sample_node";
        sample_node->hardware_id = "None";
        sample_node->level = diagnostic_msgs::msg::DiagnosticStatus::STALE;
        sample_node->message = "Starting up";

        diagnostic_->addStatusElement(sample_node);
        diagnostic_->pubDiagnostic();
    }
    void loopFunction()
    {
      // Do something
    }
    void chatterCallback(const std_msgs::msg::String::SharedPtr msg) {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      diagnostic_->addAndPubDiagnostic(sample_node, OperatorLevel::OPERATOR_OK, 3.0, "chatter data: " + msg->data);
    }

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