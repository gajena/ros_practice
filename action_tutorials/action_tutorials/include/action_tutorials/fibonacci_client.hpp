#pragma once
#ifndef ACTION_TUTORIALS_FIBONACCI_CLIENT_H_
#define ACTION_TUTORIALS_FIBONACCI_CLIENT_H_

#include <action_msgs/FibonacciAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <ros/ros.h>

namespace action_tutorials {
class FibonacciClient {
 public:
  FibonacciClient(const ros::NodeHandle& nh, const ros::NodeHandle& nh_private);

  action_msgs::FibonacciGoal _goal_;

  ros::NodeHandle nh_, nh_private_;
  actionlib::SimpleActionClient<action_msgs::FibonacciAction> ac_;
};
}  // namespace action_tutorials

#endif
