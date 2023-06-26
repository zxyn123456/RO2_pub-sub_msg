#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

class MyNode : public rclcpp::Node {
public:
  MyNode() : Node("my_node") {
    subscription_ = create_subscription<sensor_msgs::msg::Image>(
        "image_topic", 
        10, 
        std::bind(&MyNode::image_callback, this, std::placeholders::_1));
  }

private:
  void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
    RCLCPP_INFO(get_logger(), "Received image message");
  }

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MyNode>());
  rclcpp::shutdown();
  return 0;
}


// cmakelists和xml中需要添加sensor_msgs的依赖