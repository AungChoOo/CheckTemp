#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "temppub");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    ifstream myfile("/sys/class/thermal/thermal_zone0/temp");
    string temp_str;
    getline (myfile, temp_str);
    int temp_int = (stoi(temp_str))/1000;

    std_msgs::Int32 msg;
    msg.data = temp_int;
    // std::stringstream ss;
    // ss << "hello world " << count;
    // msg.data = ss.str();

    // ROS_INFO(" ");

    if(temp_int >= 50){
            system("shutdown -P now");
    }

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}