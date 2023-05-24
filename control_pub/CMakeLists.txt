cmake_minimum_required(VERSION 3.8)
project(control_pub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(carla_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs carla_msgs)
add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs nav_msgs)
include_directories(/opt/ros/humble/include)
include_directories(/opt/ros/humble/share)
# include_directories(/usr/include)
# include_directories(/carla-ros-bridge/install/carla_msgs/include)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})
  
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


ament_package()
