void setup() {
  Serial.begin(9600); //시리얼 통신을 9600으로 초기화
  pinMode(3,OUTPUT); //D2에 연결된 LED를 출력으로 사용
}

void loop() {
  int val; //val변수를 만든다
  val = analogRead(A0); //아날로그 A0핀에서 값을 읽어 val변수에 저장
  val = map(val,0,1023,0,255); //map함수를 이용하여 0~1024값을 255로 변환
  analogWrite(3,val); //D2의 연결된 LED의 밝기를 조절
  delay(10);
}
