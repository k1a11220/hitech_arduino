void setup() {
  Serial.begin(9600); //통신속도9600으로 시리얼 통신을 초기화한다
}

void loop() {
  if(Serial.available()) //시리얼 데이터가 들어왔다면
  {
      int val; //val변수를 만든다
      val = Serial.read(); //시리얼 데이터를 val변수에 넣는다
      if(val == 'a') //만약 a데이터가 들어왔다면
      {
          Serial.println("HelloWorld"); //HelloWorld를 전송한다
      }
      if(val == 'b') //만약 b데이터가 들어왔다면
      {
          Serial.println("Arduino chul chul kit"); //Arduino chul chul kit를 전송한다
      }
  }
}
