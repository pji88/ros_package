#include <sstream>
#include " / " //패키지이름 / 메세지파일.h 

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker"); //노드명 talker 초기화
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  //std_msgs::String 타입의 메시지를 발행하는 chatter_pub이라는 ros::Publisher 객체를 생성
  //"chatter"는 발행할 토픽의 이름을 나타내며, 1000은 발행할 수 있는 최대 메시지 큐의 크기
  //이렇게 생성된 ros::Publisher 객체는 publish() 메서드를 통해 메시지를 발행할 수 있음
  //advertise() 함수는 ros::NodeHandle 클래스의 멤버 함수이며, 노드 핸들러 n을 통해 chatter_pub을 초기화
  //ros::Publisher (이노드에서사용하고싶은발행객체지정) = n.advertise<타입>("노드명", 최대메시지큐의크기)
  
  ros::Rate loop_rate(10); //루프주기 2Hz

  int count = 0; // check 
  
  while (ros::ok()) // basic publisher
  {
    
    std_msgs::String msg; // std_msgs/String 이라는 타입으로 msg라는 메시지를 선언 (해당 타입은 ROS에서 기본적으로 제공하는
    std::stringstream ss; // std/stringstream 이라는 타입으로 ss 라는 변수를 선언 (문자열을 다루기 위한 C++ 표준 라이브러리 클래스로, 문자열을 입력하고 출력할 수 있슴)
    msg.data = ss.str(); //msg.data에 ss의 str()(문자열)을 저장 (str()는 저장된 문자열을 반환하는 메소드임)
    ROS_INFO("%s", msg.data.c_str()); //print
    
    
    chatter_pub.publish(msg);
    //chatter_pub 변수가 가리키는 ros::Publisher 객체를 사용하여 msg 메시지를 "chatter" 토픽에 발행
    //publish() 메서드는 인자로 전달받은 메시지를 발행하며, 이 메시지는 chatter라는 이름의 토픽으로 전달
    //이 메시지를 구독하고 있는 다른 노드들은 이 메시지를 수신하여 처리할 수 있음
    
    ros::spinOnce(); //콜백함수를 실행시킴
    loop_rate.sleep(); //루프주기 정한대로 움직이도록 함

    ++count;
  }

  return 0;
}


//모두 작성된 후에는 한글을 지울것, 한글때문에 오류발생할 수 있음
