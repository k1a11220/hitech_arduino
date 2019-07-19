unsigned char oldSw2 = 0;
unsigned char newSw2 = 0;

const int ledPin =  A2;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    led3onOff();

    newSw2 = digitalRead(7);

    if(oldSw2 != newSw2) {
        oldSw2 = newSw2;
        if(newSw2 == 1) {
            Serial.println("click");
        }
        delay(40);
    }
}

void led3onOff() {
    static unsigned long prevTimeLed3 = 0;
    static unsigned long nowTimeLed3 = 0;
    static unsigned long led3State = 0;

    nowTimeLed3 = millis();
    if(nowTimeLed3 - prevTimeLed3 >= 1000) {
        prevTimeLed3 = nowTimeLed3;
        led3State = !led3State;
        digitalWrite(ledPin, led3State);
    }
}