void setup() {
  pinMode(9,INPUT); //스위치가 연결된 포트 입력으로 설정
  pinMode(10,OUTPUT); //LED가 연결된 포트 출력으로 설정
}

void loop() {
  int val; //val변수를 만든다
  val = digitalRead(9); //9번에 연결된 스위치 값을 val변수에 저장한다.
  digitalWrite(10,val); //10번에 연결된 LED는 스위치에 따라 값을 결정
}
