#include "ros/ros.h"
#include "std_msgs/String.h"
#include "MyROSPkg/mySpecialMsg.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<MyROSPkg::mySpecialMsg>("spMsg", 1000);
  ros::Rate loop_rate(1);

  int count = 0;
  while (ros::ok())
  {

    MyROSPkg::mySpecialMsg msg;
   
    msg.A = 100;
    msg.B = 120;

    chatter_pub.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
