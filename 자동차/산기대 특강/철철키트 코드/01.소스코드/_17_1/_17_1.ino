int trig = 13;    // 변수 trig를 생성하고 13를 대입한다
int echo = 12;    // 변수 echo를 생성하고 12을 대입한다

int redled = 11;   //변수 redled를 생성하고 11을 대입
int greenled = 10; //변수 greenled를 생성하고 11을 대입
int blueled = 9;   //변수 blueled를 생성하고 11을 대입


void setup() {
  //초음파 센서 핀 초기화
  pinMode(trig, OUTPUT);   // trig(13)핀을 출력모드로 설정한다
  pinMode(echo, INPUT);    // echo(12)핀을 입력모드로 설정한다

  //3색 RGB LED 모듈 핀 초기화
  pinMode(redled, OUTPUT);   // redled(11)핀을 출력모드로 설정한다
  pinMode(greenled, OUTPUT);    // greenled(10)핀을 출력모드로 설정한다
  pinMode(blueled, OUTPUT);    // blueled(9)핀을 출력모드로 설정한다

  //시리얼 통신 초기화
  Serial.begin(9600);      // 통신속도를 9600으로 설정
}

void loop() {
  //초음파센서로 거리 측정 시작
  digitalWrite(trig, HIGH);   // trig(13)핀에 HIGH신호를 보낸다
  delayMicroseconds(10);   // 10마이크로초(1/100,000초) 동안
  digitalWrite(trig, LOW);   // trig(13)핀에 LOW신호를 보낸다
  int distance = pulseIn(echo, HIGH) * 17 / 1000;   //거리 계산
  Serial.print(distance);    // 변수 distance를 출력한다
  Serial.println("cm");    // 문자열 cm을 출력하고 줄바꿈
  //초음파센서로 거리 측정 끝

  if( distance > 0 && distance < 10 ) //0cm보다 크고 10cm보다 작으면
  {
      digitalWrite(redled, HIGH); 
      digitalWrite(greenled, LOW); 
      digitalWrite(blueled, LOW);
  }
  else if( distance > 11 && distance < 20 ) //11cm보다 크고 20cm보다 작으면
  {
      digitalWrite(redled, LOW);  
      digitalWrite(greenled, HIGH);
      digitalWrite(blueled, LOW);
  }
  else if( distance > 21 && distance < 30 ) //21cm보다 크고 30cm보다 작으면
  {
      digitalWrite(redled, LOW);  
      digitalWrite(greenled, LOW);
      digitalWrite(blueled, HIGH); 
  }
  else //어느 조건에도 충족하지 않다면
  {
      digitalWrite(redled, LOW);
      digitalWrite(greenled, LOW);
      digitalWrite(blueled, LOW); 
  }
  
  delay(100);                                         // 0.1초 기다린다
}
