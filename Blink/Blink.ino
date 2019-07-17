//변수
//char blueLedPin = 9;
#define one 2
#define two 3
#define three 4
#define four 5
#define five 6

unsigned char blueLedCnt = 0;
unsigned char redLedCnt = 0;
unsigned char blueOff = 12;
unsigned char redOff = 13;
unsigned char blueLedState = 0;
unsigned char redLedState = 0;

void setup()
{
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(five, OUTPUT);
}

void loop() {
  if (blueLedCnt >= 30)
  {
    blueLedCnt = 0;
    digitalWrite(BLUE_LED_PIN, blueLedState);
  }

  else
  {
    digitalWrite(BLUE_LED_PIN, 1);
  }

  if (blueLedCnt == 17)
  {
    blueLedCnt = 0;
  }

  if (redLedCnt >= 5)
  {
    redLedCnt = 0;
    digitalWrite(GREEN_LED_PIN, redLedState);
  }

  else
  {
    digitalWrite(GREEN_LED_PIN, 1);
  }
  if (blueLedCnt == 21)
  {
    blueLedCnt = 0;
  }

  blueLedCnt++;
  redLedCnt++;
  delay(1);
}