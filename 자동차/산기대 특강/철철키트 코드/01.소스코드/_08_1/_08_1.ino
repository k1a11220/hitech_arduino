int Fnd_A = 2;
int Fnd_B = 3;
int Fnd_C = 4;
int Fnd_D = 5;
int Fnd_E = 6;
int Fnd_F = 7;
int Fnd_G = 8;

void setup() {
  Serial.begin(9600); //통신속도9600으로 시리얼 통신을 초기화한다

  pinMode(Fnd_A,OUTPUT);
  pinMode(Fnd_B,OUTPUT);
  pinMode(Fnd_C,OUTPUT);
  pinMode(Fnd_D,OUTPUT);
  pinMode(Fnd_E,OUTPUT);
  pinMode(Fnd_F,OUTPUT);
  pinMode(Fnd_G,OUTPUT);
}

void loop() {
  if(Serial.available()) //시리얼 데이터가 들어왔다면
  {
      int val; //val변수를 만든다
      val = Serial.read(); //시리얼 데이터를 val변수에 넣는다
      if(val == '1') //만약 1데이터가 들어왔다면
      {
          //숫자 1 출력 B,C만 켠다
          digitalWrite(Fnd_A,LOW);
          digitalWrite(Fnd_B,HIGH);
          digitalWrite(Fnd_C,HIGH);
          digitalWrite(Fnd_D,LOW);
          digitalWrite(Fnd_E,LOW);
          digitalWrite(Fnd_F,LOW);
          digitalWrite(Fnd_G,LOW);
      }
      if(val == '2') //만약 2데이터가 들어왔다면
      {
          //숫자 2 출력 A,B,G,E,D 만 켠다
          digitalWrite(Fnd_A,HIGH);
          digitalWrite(Fnd_B,HIGH);
          digitalWrite(Fnd_C,LOW);
          digitalWrite(Fnd_D,HIGH);
          digitalWrite(Fnd_E,HIGH);
          digitalWrite(Fnd_F,LOW);
          digitalWrite(Fnd_G,HIGH);
      }
  }
}
