void setup() {
  Serial.begin(115200); //통신속도115200으로 시리얼 통신을 초기화한다
}

void loop() {
  Serial.println("HelloWorld"); //HelloWorld를 전송한다
  delay(1000); //1초동안 기다린다
}
