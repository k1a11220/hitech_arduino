/*
 * 모터 테스트
 * 배터리를 연결된 상태에서 진행해야 함
 */

int E1 = 10;      // 1번(A) 모터 PWM
int M1 = 12;      // 1번(A) 모터 정/역
int E2 = 11;      // 2번(B) 모터 PWM
int M2 = 13;      // 2번(B) 모터 정/역
 
void setup() {
  pinMode(M1, OUTPUT);      // 출력핀 설정
  pinMode(M2, OUTPUT);
}
 
void loop() 
{
  //모터를 정방향으로 돌린다
  digitalWrite(M1, HIGH); //모터 정방향 회전
  digitalWrite(M2, HIGH); //모터 정방향 회전
  analogWrite(E1, 200);
  analogWrite(E2, 200);
  delay(2000);   // 2초 기다린다

  
  //모터를 역방향으로 돌린다
  digitalWrite(M1, LOW); //모터 역방향 회전
  digitalWrite(M2, LOW); //모터 역방향 회전
  analogWrite(E1, 200);
  analogWrite(E2, 200);
  delay(2000);   // 2초 기다린다
}
