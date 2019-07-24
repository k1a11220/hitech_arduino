/*
 * 아래 있는 적외선 라인센서 테스트
 * 센서 앞을 가려서 확인
 * 시리얼 모니터로 값 확인
 * 블루투스 통신모듈을 제거한 후 업로드
 */

int IR_L = A4;
int IR_R = A5;



void setup() {
  Serial.begin (9600);
  pinMode(IR_L, INPUT);      // 입력핀으로 설정
  pinMode(IR_R, INPUT);
}
 
void loop()
{
  Serial.print("L=");
  Serial.print(digitalRead(IR_L));
  Serial.print(",");
  Serial.print("R=");
  Serial.println(digitalRead(IR_R));
  delay(200);
}


