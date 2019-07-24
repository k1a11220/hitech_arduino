void setup() {
  pinMode(11,OUTPUT); //빨간색 LED핀 출력으로 설정
  pinMode(10,OUTPUT); //녹색 LED핀 출력으로 설정
  pinMode(9,OUTPUT); //파란색 LED핀 출력으로 설정
}

void loop() {
  analogWrite(11,50); //빨간색 LED를 50만큼 켠다
  delay(1000);
  analogWrite(11,150); //빨간색 LED를 150만큼 켠다
  delay(1000);
  analogWrite(11,255); //빨간색 LED를 255만큼 켠다
  delay(1000);
  analogWrite(11,0); //빨간색 LED를 끈다
  delay(1000);
  analogWrite(10,50); //녹색 LED를 50만큼 켠다
  delay(1000);
  analogWrite(10,150); //녹색 LED를 150만큼 켠다
  delay(1000);
  analogWrite(10,255); //녹색 LED를 255만큼 켠다
  delay(1000);
  analogWrite(10,0); //녹색 LED를 끈다
  delay(1000);
  analogWrite(9,50); //파란색 LED를 50만큼 켠다
  delay(1000);
  analogWrite(9,150); //파란색 LED를 150만큼 켠다
  delay(1000);
  analogWrite(9,255); //파란색 LED를 255만큼 켠다
  delay(1000);
  analogWrite(9,0); //파란색 LED를 끈다
  delay(1000);
}
