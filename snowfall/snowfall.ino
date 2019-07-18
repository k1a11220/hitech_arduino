//변수
//char blueLedPin = 9;
#define one 3
#define two 5
#define three 6
#define four 10
#define five 11

char ledState = 0;
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
  analogWrite(two, ledState - 30);
  analogWrite(three, ledState - 60);
  analogWrite(four, ledState - 90);
  analogWrite(five, ledState - 120);

  ledState = ledState + ledAmount;

  if(ledState <= 0 || ledState >= 255) {
    ledAmount = -ledAmount;
  }
  delay(30);
}