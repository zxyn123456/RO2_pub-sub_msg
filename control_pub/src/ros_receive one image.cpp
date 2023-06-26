#include "sensor_msgs/msg/image.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "ipm.h"
//#include <opencv2/opencv.hpp>
//#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.hpp>


class IPM : public rclcpp::Node
{
public:
  IPM()
  : Node("ipm_compose")
  {
    subscription_front = this->create_subscription<sensor_msgs::msg::Image>(
      "/carla/ego_vehicle/rgb_front/image", 10, std::bind(&IPM::topic_callback, this, std::placeholders::_1));
/*
    subscription_left = this->create_subscription<sensor_msgs::msg::Image>(
      "/carla/ego_vehicle/rgb_left/image", 10, std::bind(&IPM::topic_callback, this, std::placeholders::_1,"left"));

    subscription_rear = this->create_subscription<sensor_msgs::msg::Image>(
      "/carla/ego_vehicle/rgb_rear/image", 10, std::bind(&IPM::topic_callback, this, std::placeholders::_1,"rear"));

    subscription_right = this->create_subscription<sensor_msgs::msg::Image>(
      "/carla/ego_vehicle/rgb_right/image", 10, std::bind(&IPM::topic_callback, this, std::placeholders::_1,"right"));

    front_image = cv::Mat();
    left_image = cv::Mat();
    rear_image = cv::Mat();
    right_image = cv::Mat();   */
  }

private:
 // void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg, const std::string& camera)
  void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
        RCLCPP_INFO(get_logger(), "Received image message");
  }

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_front;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_left;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_rear;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_right;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<IPM>());
  rclcpp::shutdown();
  return 0;
}
