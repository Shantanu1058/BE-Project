#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


 

bool one_move(move_base_msgs::MoveBaseGoal goal) {
  goal.target_pose.header.frame_id = "base_link";
  goal.target_pose.header.stamp = ros::Time::now();
  MoveBaseClient ac("move_base", true);

      ac.sendGoal(goal);
      ac.waitForResult();
      if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
           return true;
      else
           return false;
        }



int main(int argc, char** argv){
  ros::init(argc, argv, "multiple_goals");

  MoveBaseClient ac("move_base", true);

  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal[3];


  goal[0].target_pose.pose.position.x = 6.214354;
  goal[0].target_pose.pose.position.y = -32.831995;
  goal[0].target_pose.pose.position.z = 0.0;

  goal[0].target_pose.pose.orientation.x = 0.0;
  goal[0].target_pose.pose.orientation.y = 0.0;
  goal[0].target_pose.pose.orientation.z = 0.0;
  goal[0].target_pose.pose.orientation.w = 1.0;

  goal[1].target_pose.pose.position.x = 11.563402;
  goal[1].target_pose.pose.position.y = -33.017296;
  goal[1].target_pose.pose.position.z =0.0;

  goal[1].target_pose.pose.orientation.x = 0.0;
  goal[1].target_pose.pose.orientation.y = 0.0;
  goal[1].target_pose.pose.orientation.z = 0.0;
  goal[1].target_pose.pose.orientation.w = 1.0;

  goal[2].target_pose.pose.position.x = 11.634063;
  goal[2].target_pose.pose.position.y = -21.088925;
  goal[2].target_pose.pose.position.z = 0.016090;

  goal[2].target_pose.pose.orientation.x = 0.0;
  goal[2].target_pose.pose.orientation.y = 0.0;
  goal[2].target_pose.pose.orientation.z = 0.0;
  goal[2].target_pose.pose.orientation.w = 1.0;

  //we'll send a goal to the robot to move 1 meter forward


 ROS_INFO("Sending goal1");
for(int i=0; i<3; i++)
 {
    if(one_move(goal[i])) ROS_INFO("Hooray, the %f goal reached",i);
    else  ROS_INFO("The the %f goal doesn't reached for some reason",i);    
  }
   return 0;
}