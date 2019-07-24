void setup() {
  Serial.begin(9600); //시리얼 통신을 9600으로 초기화
  pinMode(3,OUTPUT); //LED핀 출력으로 설정
}

void loop() {
  int val; //val변수를 만든다
  val = analogRead(A0); //아날로그 A0핀에서 값을 읽어 val변수에 저장
  Serial.println(val); //val 값을 시리얼로 전송한다
  
  if(val < 500) //값이 500보다 작으면 참
  {
      digitalWrite(3,HIGH); //3번에 연결된 LED를 켠다
  }
  else
  {
      digitalWrite(3,LOW); //3번에 연결된 LED를 끈다
  }
  
  delay(500); //0.5초 기다린다
}
