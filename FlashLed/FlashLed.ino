unsigned char sw2 = 2;
unsigned char led8 = 8;

void setup() {
  pinMode(led8, OUTPUT);
  pinMode(sw2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sw2), swInt, FALLING);
}

void loop() {
    
}

void swInt() {
    static unsigned char ledState = 0;
    ledState = !ledState;
    digitalWrite(led8, ledState);
    delay(40);
    interrupts();
}
