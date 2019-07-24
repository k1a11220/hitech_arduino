/*
 * 부저가 1초간격으로 삐~삐~ 울린다
 */

void setup() {
  pinMode(A3,OUTPUT); //4번핀을 출력으로 사용, 부저가 연결된 핀
}

void loop() {
  digitalWrite(A3,HIGH); //4번핀에 부저를 켠다
  delay(1000); //1초 기다린다
  digitalWrite(A3,LOW); //4번핀에 부저를 끈다
  delay(1000); //1초 기다린다
}
