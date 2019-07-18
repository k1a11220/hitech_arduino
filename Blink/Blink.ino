//변수
//char blueLedPin = 9;
#define one 3
#define two 5
#define three 6
#define four 10
#define five 11

unsigned char ledCnt = 10;
unsigned char ledOff = 0;
unsigned char ledState = 0;
char ledAmount = 5;

void setup() {
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(five, OUTPUT);
}

void loop() {
  analogWrite(one, ledState);
  ledState = ledState + ledAmount;

  if(ledState <= 0 || ledState >= 255) {
    ledAmount = -ledAmount;
  }
  delay(30);
}

/*
  digitalWrite(one, 1);
  delay(1000);
  digitalWrite(two, 1);
  delay(1000);
  digitalWrite(three, 1);
  delay(1000);
  digitalWrite(four, 1);
  delay(1000);
  digitalWrite(five, 1);
  delay(1000);
  digitalWrite(one, 0);
  delay(1000);
  digitalWrite(two, 0);
  delay(1000);
  digitalWrite(three, 0);
  delay(1000);
  digitalWrite(four, 0);
  delay(1000);
  digitalWrite(five, 0);
  delay(1000); 
    if(ledCnt == 0) {
    ledCnt = 10;
  }

  if(ledOff == 10) {
    ledOff = 0;
  }

  digitalWrite(one, !ledState);
  delay(ledCnt);
  digitalWrite(one, ledState);
  delay(ledOff);
  ledCnt--;
  ledOff++;
  delay(10); 

  analogWrite(one, ledState);
  ledState = ledState + ledAmount;

  if(ledState <= 0 || ledState >= 255) {
    ledAmount = -ledAmount;
  }
  delay(30);

  */