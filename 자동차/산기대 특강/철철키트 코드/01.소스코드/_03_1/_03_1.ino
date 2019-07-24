void setup() {
  pinMode(2,OUTPUT); //2번핀을 출력으로 사용한다
}

void loop() {
  digitalWrite(2,HIGH); //2번핀 출력을 “HIGH“로 한다
  delay(1000);         //1초동안 기다린다
  digitalWrite(2,LOW); //2번핀 출력을 “LOW“로 한다
  delay(1000);         //1초동안 기다린다
}
