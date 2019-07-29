#include "action_tutorials/fibonacci_server.hpp"

namespace action_tutorials {
FibonacciServer::FibonacciServer(const ros::NodeHandle &nh,
                                 const ros::NodeHandle &nh_private)
    : nh_(nh),
      nh_private_(nh_private),
      _action_name_("fibonacci"),
      as_(nh_, "fibonacci", boost::bind(&FibonacciServer::executeCB, this, _1),
          false) {
  as_.start();
}

void FibonacciServer::executeCB(
    const action_msgs::FibonacciGoalConstPtr &goal) {
  // helper variables
  ros::Rate r(1);
  bool success = true;

  // push_back the seeds for the fibonacci sequence
  _feedback_.sequence.clear();
  _feedback_.sequence.push_back(0);
  _feedback_.sequence.push_back(1);

  // publish info to the console for the user
  ROS_INFO(
      "%s: Executing, creating fibonacci sequence of order %i with seeds %i, "
      "%i",
      _action_name_.c_str(), goal->order, _feedback_.sequence[0],
      _feedback_.sequence[1]);

  // start executing the action
  for (int i = 1; i <= goal->order; i++) {
    // check that preempt has not been requested by the client
    if (as_.isPreemptRequested() || !ros::ok()) {
      ROS_INFO("%s: Preempted", _action_name_.c_str());
      // set the action state to preempted
      as_.setPreempted();
      success = false;
      break;
    }
    _feedback_.sequence.push_back(_feedback_.sequence[i] +
                                  _feedback_.sequence[i - 1]);
    // publish the feedback
    as_.publishFeedback(_feedback_);
    // this sleep is not necessary, the sequence is computed at 1 Hz for
    // demonstration purposes
    r.sleep();
  }

  if (success) {
    _result_.sequence = _feedback_.sequence;
    ROS_INFO("%s: Succeeded", _action_name_.c_str());
    // set the action state to succeeded
    as_.setSucceeded(_result_);
  }
}

}  // namespace action_tutorials