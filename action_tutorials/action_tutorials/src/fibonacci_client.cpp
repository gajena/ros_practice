#include "action_tutorials/fibonacci_client.hpp"

namespace action_tutorials {
FibonacciClient::FibonacciClient(const ros::NodeHandle &nh,
                                 const ros::NodeHandle &nh_private)
    : nh_(nh), nh_private_(nh_private), ac_("fibonacci", true) {
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  ac_.waitForServer();  // will wait for infinite time

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  _goal_.order = 20;
  ac_.sendGoal(_goal_);

  // wait for the action to return
  bool finished_before_timeout = ac_.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout) {
    actionlib::SimpleClientGoalState state = ac_.getState();
    ROS_INFO("Action finished: %s", state.toString().c_str());
  } else
    ROS_INFO("Action did not finish before the time out.");
}
}  // namespace action_tutorials