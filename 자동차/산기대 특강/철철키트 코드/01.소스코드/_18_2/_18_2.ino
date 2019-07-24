#include<Servo.h> 

Servo myservo; 
int servoPin = 12; //servoPin 변수를 만들고 12값을 대입

void setup() 
{ 
  myservo.attach(servoPin); //서보모터에 연결된 핀을 초기화
} 
 
void loop() 
{ 
  int val;
  val = analogRead(A0); //A0핀에서 값일 읽는다
  val = map(val,0,1024,0,180); //val값 0~1024사이 값을 0~180으로 맵핑한다
  myservo.write(val);   //맵핑된 각도를 서보모터에 입력
  delay(10);
}
