#pragma once
#ifndef ACTION_TUTORIALS_FIBONACCI_SERVER_H_
#define ACTION_TUTORIALS_FIBONACCI_SERVER_H_

#include <action_msgs/FibonacciAction.h>
#include <actionlib/server/simple_action_server.h>
#include <ros/ros.h>

namespace action_tutorials {
class FibonacciServer {
 public:
  FibonacciServer(const ros::NodeHandle& nh, const ros::NodeHandle& nh_private);

  std::string _action_name_;
  action_msgs::FibonacciFeedback _feedback_;
  action_msgs::FibonacciResult _result_;

  ros::NodeHandle nh_, nh_private_;
  actionlib::SimpleActionServer<action_msgs::FibonacciAction> as_;

  void executeCB(const action_msgs::FibonacciGoalConstPtr& goal);
};
}  // namespace action_tutorials

#endif
