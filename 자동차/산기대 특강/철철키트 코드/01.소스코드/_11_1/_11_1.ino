void setup() {
  pinMode(11,OUTPUT); //빨간색 LED핀 출력으로 설정
  pinMode(10,OUTPUT); //녹색 LED핀 출력으로 설정
  pinMode(9,OUTPUT); //파란색 LED핀 출력으로 설정
}

void loop() {
  digitalWrite(11,HIGH); //빨간색 LED를 켠다
  digitalWrite(10,LOW); //LED를 끈다
  digitalWrite(9,LOW); //LED를 끈다
  delay(1000);
  digitalWrite(11,LOW);    //LED를 끈다
  digitalWrite(10,HIGH);  //녹색 LED를 켠다
  digitalWrite(9,LOW);   //LED를 끈다
  delay(1000); 
  digitalWrite(11,LOW);   //LED를 끈다
  digitalWrite(10,LOW);  //LED를 끈다
  digitalWrite(9,HIGH); //파란색 LED를 켠다
  delay(1000);
}
