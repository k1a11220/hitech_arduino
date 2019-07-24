/*
 * 블루투스 통신모듈을 제거한 후 업로드
 */

int IR_L = A4; //적외선 센서 왼쪽
int IR_R = A5; //적외선 센서 오른쪽

int E1 = 10;      // 1번(A) 모터 PWM
int M1 = 12;      // 1번(A) 모터 정/역
int E2 = 11;      // 2번(B) 모터 PWM
int M2 = 13;      // 2번(B) 모터 정/역


void setup() {
  Serial.begin (9600);
  pinMode(M1, OUTPUT);      // 출력핀 설정
  pinMode(M2, OUTPUT);
  pinMode(IR_L, INPUT);      // 입력핀으로 설정
  pinMode(IR_R, INPUT);
}
 
void loop()
{
  int leftSensor = digitalRead(IR_L);
  int rigthSensor = digitalRead(IR_R);
  
  if(leftSensor == 0 && rigthSensor == 0) //둘다 감지되지 않았을때 
  {
      forward_motor(200); //모터를 둘다 앞으로 돌린다
  }
  else if(leftSensor == 1 && rigthSensor == 0) //왼쪽 센서가 감지되었을때
  {
      right_motor(150); //모터를 오른쪽으로 돌린다
  }
  else if(leftSensor == 0 && rigthSensor == 1) //오른쪽 센서가 감지되었을때
  {
      left_motor(150); //모터를 왼쪽으로 돌린다
  }
  else //둘다 감지되었을때, 특수한 경우임
  {
      right_motor(150); //모터를 왼쪽으로 돌린다
      delay(200);
      forward_motor(200);
      delay(200);
  }
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
  analogWrite(E1, motorspeed/2);
  analogWrite(E2, motorspeed);
}

void left_motor(int motorspeed)
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, HIGH); //모터 정방향 회전
  digitalWrite(M2, LOW); //모터 역방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed/2);
}


