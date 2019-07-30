#include "action_tutorials/fibonacci_client.hpp"

int main(int argc, char** argv) {
  ros::init(argc, argv, "fibonacci_client");

  ros::NodeHandle nh("");
  ros::NodeHandle nh_private("~");

  action_tutorials::FibonacciClient node(nh, nh_private);
  ROS_INFO("Initialized Fibonacci Client node.");

  ros::spin();
  return 0;
}