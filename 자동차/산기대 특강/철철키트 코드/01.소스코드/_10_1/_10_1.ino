#define NOTE_C4  262 //도
#define NOTE_D4  294 //레
#define NOTE_E4  330 //미
#define NOTE_F4  349 //파
#define NOTE_G4  392 //솔

int BuzzerPin = 9; //부저핀

int sw_do = 6;  //스위치 도 핀
int sw_le = 5;  //스위치 레 핀 
int sw_mi = 4;  //스위치 미 핀
int sw_pa = 3;  //스위치 파 핀
int sw_sol = 2; //스위치 솔 핀

void setup() {
  pinMode(sw_do,INPUT_PULLUP); //스위치핀을 풀업 입력으로 설정
  pinMode(sw_le,INPUT_PULLUP); //스위치핀을 풀업 입력으로 설정
  pinMode(sw_mi,INPUT_PULLUP); //스위치핀을 풀업 입력으로 설정
  pinMode(sw_pa,INPUT_PULLUP); //스위치핀을 풀업 입력으로 설정
  pinMode(sw_sol,INPUT_PULLUP); //스위치핀을 풀업 입력으로 설정

  pinMode(BuzzerPin, OUTPUT); //부저핀을 출력으로 설정
}

void loop() {
  int sw_do_state = digitalRead(sw_do); //스위치 상태에 현재 스위치 값을 저장
  int sw_le_state = digitalRead(sw_le); //스위치 상태에 현재 스위치 값을 저장
  int sw_mi_state = digitalRead(sw_mi); //스위치 상태에 현재 스위치 값을 저장
  int sw_pa_state = digitalRead(sw_pa); //스위치 상태에 현재 스위치 값을 저장
  int sw_sol_state = digitalRead(sw_sol); //스위치 상태에 현재 스위치 값을 저장
  

  if(sw_do_state == 0) //스위치가 눌렀다면
  {
      tone(BuzzerPin,NOTE_C4); //도
      delay(300);
  }
  else if(sw_do_state == 1) //스위치가 눌리지 않았다면
  {
      noTone(BuzzerPin);   //핀의 출력을 끈다
  }

  if(sw_le_state == 0) //스위치가 눌렀다면
  {
      tone(BuzzerPin,NOTE_D4); //레
      delay(300);
  }
  else if(sw_le_state == 1) //스위치가 눌리지 않았다면
  {
      noTone(BuzzerPin);   //핀의 출력을 끈다
  }

  if(sw_mi_state == 0) //스위치가 눌렀다면
  {
      tone(BuzzerPin,NOTE_E4); //미
      delay(300);
  }
  else if(sw_mi_state == 1) //스위치가 눌리지 않았다면
  {
      noTone(BuzzerPin);   //핀의 출력을 끈다
  }

  if(sw_pa_state == 0) //스위치가 눌렀다면
  {
      tone(BuzzerPin,NOTE_F4); //파
      delay(300);
  }
  else if(sw_pa_state == 1) //스위치가 눌리지 않았다면
  {
      noTone(BuzzerPin);   //핀의 출력을 끈다
  }

  if(sw_sol_state == 0) //스위치가 눌렀다면
  {
      tone(BuzzerPin,NOTE_G4); //솔
      delay(300);
  }
  else if(sw_sol_state == 1) //스위치가 눌리지 않았다면
  {
      noTone(BuzzerPin);   //핀의 출력을 끈다
  }

}
