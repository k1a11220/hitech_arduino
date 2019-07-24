#define NOTE_C4  262 //도
#define NOTE_D4  294 //레
#define NOTE_E4  330 //미
#define NOTE_F4  349 //파
#define NOTE_G4  392 //솔
#define NOTE_A4  440 //라
#define NOTE_B4  494 //시
#define NOTE_C5  523 //도~

int BuzzerPin = 9;

void setup() {
  pinMode(BuzzerPin, OUTPUT); //부저핀을 출력으로 설정
}

void loop() {
    tone(BuzzerPin,NOTE_C4); //도
    delay(1000); //1초동안 기다린다
    tone(BuzzerPin,NOTE_D4); //레
    delay(1000); //1초동안 기다린다
    tone(BuzzerPin,NOTE_E4); //미
    delay(1000); //1초동안 기다린다
    noTone(BuzzerPin);   //핀의 출력을 끈다
    delay(1000); //1초동안 기다린다
}
