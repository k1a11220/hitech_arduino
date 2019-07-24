/*
 * 블루투스 자동차 연결
 * 블루투스 모듈제거 후 업로드
 * 업로드 완료 후 블루투스 모듈 연결
 */

int E1 = 10;      // 1번(A) 모터 PWM
int M1 = 12;      // 1번(A) 모터 정/역
int E2 = 11;      // 2번(B) 모터 PWM
int M2 = 13;      // 2번(B) 모터 정/역


void setup() {
  Serial.begin (9600);
  pinMode(M1, OUTPUT);      // 출력핀 설정
  pinMode(M2, OUTPUT);
}
 
void loop()
{
  if(Serial.available() > 0)
  {
      char val = Serial.read();
      if(val == 'F') //정방향
      {
          forward_motor(200);
      }
      else if(val == 'B') //역방향
      {
          backward_motor(200);
      }
      else if(val == 'R') //오른쪽
      {
          right_motor(100);
      }
      else if(val == 'L') //왼쪽
      {
          left_motor(100);
      }
      else if(val == 'S') //모터 스탑
      {
          stop_motor();
      }
      
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
  digitalWrite(M1, LOW); //모터 정방향 회전
  digitalWrite(M2, HIGH); //모터 정방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed);
}

void left_motor(int motorspeed)
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, HIGH); //모터 정방향 회전
  digitalWrite(M2, LOW); //모터 정방향 회전
  analogWrite(E1, motorspeed);
  analogWrite(E2, motorspeed);
}

void stop_motor(void)
{
  digitalWrite(M1, HIGH); //모터 정방향 회전
  digitalWrite(M2, HIGH); //모터 정방향 회전
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

