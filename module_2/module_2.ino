#define led_1 6
#define led_2 7
#define btn 8

void setup() {
    pinMode(btn, INPUT_PULLUP);
    pinMode(btn, INPUT);
    pinMode(led_1, OUTPUT);
    pinMode(led_2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    btnPush();
}

void WORKING_LED() {
    unsigned char redLed_state = 0;

    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    if (current_Millis - previous_Millis >= 500) {
        previous_Millis = current_Millis; 
        if (redLed_state == 0) {
            redLed_state = 1;
        } else {
            redLed_state = 0;
        }
        digitalWrite(led_1, redLed_state);
    }
}