#include "action_tutorials/fibonacci_server.hpp"

int main(int argc, char** argv) {
  ros::init(argc, argv, "fibonacci_server");

  ros::NodeHandle nh("");
  ros::NodeHandle nh_private("~");

  action_tutorials::FibonacciServer node(nh, nh_private);
  ROS_INFO("Initialized Fibonacci Server node.");

  ros::spin();
  return 0;
}