#include<Servo.h> 

Servo myservo; 
int servoPin = 12; //servoPin 변수를 만들고 12값을 대입

void setup() 
{ 
  myservo.attach(servoPin); //서보모터에 연결된 핀을 초기화
} 
 
void loop() 
{ 
  myservo.write(0);   //서보모터의 각도를 0도로 설정
  delay(2000);
  myservo.write(90);  //서보모터의 각도를 90도로 설정
  delay(2000);
  myservo.write(180); //서보모터의 각도를 180도로 설정
  delay(2000);
}
