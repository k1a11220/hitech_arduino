int Fnd_A = 2;
int Fnd_B = 3;
int Fnd_C = 4;
int Fnd_D = 5;
int Fnd_E = 6;
int Fnd_F = 7;
int Fnd_G = 8;

void setup() {
  pinMode(Fnd_A,OUTPUT);
  pinMode(Fnd_B,OUTPUT);
  pinMode(Fnd_C,OUTPUT);
  pinMode(Fnd_D,OUTPUT);
  pinMode(Fnd_E,OUTPUT);
  pinMode(Fnd_F,OUTPUT);
  pinMode(Fnd_G,OUTPUT);
}

void loop() {
  //숫자 1 출력 B,C만 켠다
  digitalWrite(Fnd_A,LOW);
  digitalWrite(Fnd_B,HIGH);
  digitalWrite(Fnd_C,HIGH);
  digitalWrite(Fnd_D,LOW);
  digitalWrite(Fnd_E,LOW);
  digitalWrite(Fnd_F,LOW);
  digitalWrite(Fnd_G,LOW);
  delay(1000);
  //숫자 2 출력 A,B,G,E,D 만 켠다
  digitalWrite(Fnd_A,HIGH);
  digitalWrite(Fnd_B,HIGH);
  digitalWrite(Fnd_C,LOW);
  digitalWrite(Fnd_D,HIGH);
  digitalWrite(Fnd_E,HIGH);
  digitalWrite(Fnd_F,LOW);
  digitalWrite(Fnd_G,HIGH);
  delay(1000);
}
