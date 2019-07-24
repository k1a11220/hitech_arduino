/*
 * 초음파 센서 장애물 회피 자동차
 * 서보모터 사용 안함
 * 서보모터의 각도를 조정하여 초음파가 앞을 바라보게 한다
 */

#include <Servo.h> 
 
int servoPin = 9;

Servo servo; 

int Trig = A3;    //Trig핀
int Echo = A2;    //Echo핀
float Distance;

int E1 = 10;      // 1번(A) 모터 PWM
int M1 = 12;      // 1번(A) 모터 정/역
int E2 = 11;      // 2번(B) 모터 PWM
int M2 = 13;      // 2번(B) 모터 정/역

void setup()
{
  Serial.begin(9600);    
  servo.attach(servoPin); 
  servo.write(80); //서보 각도를 90도로 한다

  pinMode(M1, OUTPUT);      // 출력핀 설정
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);      // 출력핀 설정
  pinMode(E2, OUTPUT);

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}


void loop()
{
    Distance_cm();
    if(Distance > 30)
    {
        //모터를 정방향으로 돌린다
        digitalWrite(M1, HIGH); //모터 정방향 회전
        digitalWrite(M2, HIGH); //모터 정방향 회전
        digitalWrite(E1, HIGH);
        digitalWrite(E2, HIGH);
    }
    else
    {
        //300mS 동안 후진한다
        digitalWrite(M1, LOW); //모터 역방향 회전
        digitalWrite(M2, LOW); //모터 정방향 회전
        digitalWrite(E1, HIGH);
        digitalWrite(E2, HIGH);
        delay(300);
        digitalWrite(M1, LOW); //모터 역방향 회전
        digitalWrite(M2, HIGH); //모터 정방향 회전
        digitalWrite(E1, HIGH);
        digitalWrite(E2, HIGH);
        delay(100);
    }
}

void Distance_cm()   
{
  digitalWrite(Trig, LOW);  
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;       

  Serial.print("Distance:");      
  Serial.println(Fdistance);       
  Distance = Fdistance;
}  

void forward_motor(int motorspeed)
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, HIGH); //모터 정방향 회전
  digitalWrite(M2, HIGH); //모터 정방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed);
}

void backward_motor(int motorspeed)
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, LOW); //모터 정방향 회전
  digitalWrite(M2, LOW); //모터 정방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed);
}

void right_motor(int motorspeed)
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, LOW); //모터 역방향 회전
  digitalWrite(M2, HIGH); //모터 정방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed);
}

void left_motor(int motorspeed)
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, HIGH); //모터 정방향 회전
  digitalWrite(M2, LOW); //모터 역방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed);
}

