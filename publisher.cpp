#include <sstream>
#include " / " //패키지이름 / 메세지파일.h 

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker"); //노드명 초기화
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  
  
  ros::Rate loop_rate(10); //루프주기 2Hz

  int count = 0; // check 
  
  while (ros::ok()) // basic publisher
  {
    
    std_msgs::String msg; //String 이라는 타입으로 msg라는 메시지를 선언?
    std::stringstream ss; //ss 라는 애를 저 형식으로 선언 (대입)
    msg.data = ss.str(); 
    ROS_INFO("%s", msg.data.c_str()); //print
    
    
    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();

    ++count;
  }

  return 0;
}


//모두 작성된 후에는 한글을 지울것, 한글때문에 오류발생할 수 있음
