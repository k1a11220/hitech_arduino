int RedLed = 7;     //RedLed 변수에 7을 넣는다
int YellowLed = 6;  //YellowLed 변수에 6을 넣는다
int GreenLed = 5;   //GreenLed 변수에 5을 넣는다

void setup() {
  pinMode(RedLed,OUTPUT);     //7번핀을 출력으로 사용한다
  pinMode(YellowLed,OUTPUT);  //6번핀을 출력으로 사용한다
  pinMode(GreenLed,OUTPUT);   //5번핀을 출력으로 사용한다
}

void loop() {
  digitalWrite(RedLed,HIGH);     //빨간색 LED를 HIGH(켠다)로 한다.
  digitalWrite(YellowLed,LOW);   //노란색 LED를 LOW(끈다)로 한다.
  digitalWrite(GreenLed,LOW);   //녹색 LED를 LOW(끈다)로 한다.
  delay(3000); //3초동안 기다린다.
  digitalWrite(RedLed,LOW);     //빨간색 LED를 LOW(끈다)로 한다.
  digitalWrite(YellowLed,HIGH);  //노란색 LED를 HIGH(켠다)로 한다.
  digitalWrite(GreenLed,LOW);   //녹색 LED를 LOW(끈다)로 한다.
  delay(500); //0.5초동안 기다린다.
  digitalWrite(RedLed,LOW);     //빨간색 LED를 LOW(끈다)로 한다.
  digitalWrite(YellowLed,LOW);  //노란색 LED를 LOW(끈다)로 한다.
  digitalWrite(GreenLed,HIGH);  //녹색 LED를 HIGH(켠다)로 한다.
  delay(5000); //5초동안 기다린다.
}
