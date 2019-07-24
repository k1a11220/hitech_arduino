void setup() {
  pinMode(11,OUTPUT); //빨간색 LED핀 출력으로 설정
  pinMode(10,OUTPUT); //녹색 LED핀 출력으로 설정
  pinMode(9,OUTPUT); //파란색 LED핀 출력으로 설정
}

void loop() {
  analogWrite(11,255); //빨간색 LED를 50만큼 켠다
  analogWrite(10,128); //녹색 LED를 50만큼 켠다
  analogWrite(9,0); //파란색 LED를 50만큼 켠다
  delay(1000);
}
