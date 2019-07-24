int trig = 13;    // 변수 trig를 생성하고 13를 대입한다
int echo = 12;    // 변수 echo를 생성하고 12을 대입한다

void setup() {
  pinMode(trig, OUTPUT);   // trig(13)핀을 출력모드로 설정한다
  pinMode(echo, INPUT);    // echo(12)핀을 입력모드로 설정한다
  Serial.begin(9600);      // 통신속도를 9600으로 설정
}

void loop() {
  digitalWrite(trig, HIGH);   // trig(13)핀에 HIGH신호를 보낸다
  delayMicroseconds(10);   // 10마이크로초(1/100,000초) 동안
  digitalWrite(trig, LOW);   // trig(13)핀에 LOW신호를 보낸다
  int distance = pulseIn(echo, HIGH) * 17 / 1000;   //거리 계산
  Serial.print(distance);    // 변수 distance를 출력한다
  Serial.println("cm");    // 문자열 cm을 출력하고 줄바꿈
  delay(100);             // 0.1초 기다린다
}
