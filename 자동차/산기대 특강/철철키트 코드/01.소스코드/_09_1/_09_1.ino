int BuzzerPin = 9;

void setup() {
  pinMode(BuzzerPin, OUTPUT); //부저핀을 출력으로 설정
}

void loop() {
    tone(BuzzerPin,262); //도
    delay(1000); //1초동안 기다린다
    tone(BuzzerPin,294); //레
    delay(1000); //1초동안 기다린다
    tone(BuzzerPin,330); //미
    delay(1000); //1초동안 기다린다
    noTone(BuzzerPin);   //핀의 출력을 끈다
    delay(1000); //1초동안 기다린다
}
