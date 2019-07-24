/*
 * 서보모터 테스트
 * 서보모터가 90도 각도를 유지한다
 * 항상 정면을 보게끔 초음파 센서의 가드를 조정한다
 * 드라이버를 이용하여 초음파 가드가 정면을 바라보게 조정
 * 기어비 때문에 약간 틀어질 수 있음
 * 최대한 정면을 바라보게 수정
 */

#include <Servo.h> 
 
int servoPin = 9;

Servo servo; 

int angle = 0; // servo position in degrees 

void setup() 
{ 
    servo.attach(servoPin); 
    servo.write(90); 
} 


void loop() 
{ 
    
} 
