#include "ros/ros.h"
#include "std_msgs/String.h"

/*studies from ros tutorial*/

void chatterCallback(const std_msgs::String::ConstPtr& msg)  //callback function
{
  //void 함수이름(const 타입::ConstPtr& 변수)
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  //msg->data는 std_msgs::String 메시지의 data 필드를 나타내며, 
  //c_str() 함수를 사용하여 C 스타일 문자열로 변환합니다.
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener"); //listener 라는 노드 생성
  
  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback); // 객체 sub를 정의
  //ros::Subscriber 이름 = n.subscribe("토픽",큐의 크기,사용할콜백함수)
  
  ros::spin();
  //ros를 유지함과 동시에 콜백함수를 활용하기 위한 명령어

  return 0;
}


