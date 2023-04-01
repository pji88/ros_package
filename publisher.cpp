#include <sstream>

/**
 * studied from ros tutorials
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);

  int count = 0; // check 
  
  while (ros::ok()) // basic publisher
  {
    std_msgs::String msg; //String msg
    std::stringstream ss; //ss 
    msg.data = ss.str(); 
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();

    ++count;
  }

  return 0;
}
