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