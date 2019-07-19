/*

프레스기계 제어

요구사항
1. 버튼 I와 II 동시 누르면 서보모터 동작 I번 + 빨간색 LED 0.5초간격 점멸 동작하지 않으면 파란색 LED 점멸
2. 비상정지버튼 눌렀을 시 부저 + 모든기능 정지
 */

//라이브러리 추가

#include<Servo.h>
Servo servo;

//소자별 정보

#define motor 8
#define buzzer 7
#define redLed 6
#define blueLed 5
#define firstBtn 4
#define secondBtn 3
#define thirdBtn 2

//소자상태 정의

char motor_value = 0;
char motor_state = 0;
char buzzer_state = 0;
char redLed_state = 0;
char blueLed_state = 0;
char firstBtn_state = 0;
char secondBtn_state = 0;
char thirdBtn_state = 0;

//init 함수

void setup() {
    Serial.begin(9600);
    pinMode(motor, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(firstBtn, INPUT);
    pinMode(secondBtn, INPUT);
    pinMode(thirdBtn, INPUT);
}

void loop() {
    EMERGENCY();
    INPUT_BTN();
}

//모듈함수

void EMERGENCY() {
    attachInterrupt(digitalPinToInterrupt(thirdBtn), STOP, CHANGE);
}

void STOP() {
    motor_value = 0;
    motor_state = 0;
    buzzer_state = 0;
    redLed_state = 0;
    blueLed_state = 0;
    firstBtn_state = 0;
    secondBtn_state = 0;
    thirdBtn_state = 0;
    WORKING_BUZZER();
    Serial.println("EMERGENCY!");
}

void INPUT_BTN() {
    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    firstBtn_state = analogRead(firstBtn);
    secondBtn_state = analogRead(secondBtn);
    thirdBtn_state = analogRead(thirdBtn);

    if(firstBtn_state == 1 || secondBtn_state == 1) {
        previous_Millis = current_Millis;
    }

    if(firstBtn_state == 1 && secondBtn ==1 && current_Millis - previous_Millis <= 40) {
        WORKING_LED();
        WORKING_MOTOR();
        Serial.println("It's working!");
    }

    if(firstBtn_state == 0 || secondBtn_state == 0) {
        NOT_WORKING_LED();
        Serial.println("Not working");
    }
}

void WORKING_LED() {
    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    if (current_Millis - previous_Millis >= 500) {
        previous_Millis = current_Millis;
        if (redLed_state == 0) {
            redLed_state = 1;
        } else {
            redLed_state = 0;
        }
        digitalWrite(redLed, redLed_state);
    }
}

void NOT_WORKING_LED() {
    unsigned long previous_Millis = 0;
    unsigned long current_Millis = millis();

    if (current_Millis - previous_Millis >= 500) {
        previous_Millis = current_Millis;
        if (blueLed_state == 0) {
            blueLed_state = 1;
        } else {
            blueLed_state = 0;
        }
        digitalWrite(blueLed, blueLed_state);
    }
}

void WORKING_MOTOR() {
    motor_value += 30;
    if(motor_value == 180) {
        motor_value = 0;
    }
}

void WORKING_BUZZER() {
    buzzer_state = 1;
}