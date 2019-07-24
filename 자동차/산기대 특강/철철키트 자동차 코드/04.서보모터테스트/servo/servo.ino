/*
 * 서보모터 테스트
 */

#include <Servo.h> 
 
int servoPin = 9;

Servo servo; 

int angle = 0; // servo position in degrees 

void setup() 
{ 
    servo.attach(servoPin); 
} 


void loop() 
{ 
  servo.write(0); //서보 각도를 0도로 한다
  delay(1000); 
  servo.write(90); //서보 각도를 90도로 한다
  delay(1000); 
  servo.write(180); //서보 각도를 180도로 한다
  delay(1000); 
} 
