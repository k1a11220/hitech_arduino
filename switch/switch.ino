#define redLed A0
#define yellowLed A1
#define blueLed A2

int switchValue = 0;
int switchCnt = 0;
int switchSec = 0;

void setup() {
    pinMode(blueLed, OUTPUT);
    pinMode(7, INPUT);
    pinMode(redLed, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    switchValue = digitalRead(7);

    if(switchValue == 1) {
        switchCnt++;
    } else {
        digitalWrite(redLed, 0);
        digitalWrite(blueLed, 0);
    }

    if(switchCnt == 1) {
        switchCnt == 0;
        switchSec++;
        Serial.println("Click");
    }

    if(switchSec >= 10) {
        switchSec = 0;
        Serial.println("Long Click");
        digitalWrite(redLed, 1);
        digitalWrite(blueLed, 0);
    } else {
        digitalWrite(blueLed, 0);
    }
    
    delay(100);
}

/*
int LED = 0;		//LED 상태저장

  int Switch = 0;	//스위치 값 저장

  int pass = 0;		//정상적으로 누르고 때는 스위치동작 확인용

  

  while(1){		//루프 돌때마다 변수가 초기화되므로 반복문으로 무한반복

    Switch = digitalRead(7);	//7번 포트로 입력을 받는다

    if(Switch==1){

      delay(200);		//debounce 0.2초 대기

      while(Switch==1)		//bounce이후 재확인 스위치가 때어지면 나온다

        Switch = digitalRead(7);

      if(Switch==0){

        delay(200);

        Switch = digitalRead(7);

        if(Switch==0)

          pass++;

      }

    }

    if(pass==2){		//스위치 인식확인

      LED = !LED;		//LED현재 값을 반전시킨다.

      digitalWrite(A1,LED);

      pass=0;			//초기화

    }

  }				//while END
    Serial.begin(9600);
    pinMode(7,INPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
  if(swValue == on) {
        digitalWrite(6, on);
    } else {
        on = !on;
        digitalWrite(6, on);
            int swValue;
    digitalWrite(redLed, state);
    swValue = digitalRead(7);
    Serial.println(swValue);

    if(state != swValue) {
        state = swValue;
    } else {
        state = 1;
    }
    
    if(lastBtn == LOW && currentBtn == HIGH) {
        ledOn = !ledOn;
    }

    lastBtn = currentBtn;

    digitalWrite(redLed, ledOn);

    }
        currentBtn = digitalRead(7);
    
    if(currentBtn == 1) {
        btnCnt++;
    }

    else if(btnCnt == 1) {
        digitalWrite(redLed, 1);
        digitalWrite(yellowLed, 0);
        digitalWrite(blueLed, 0);
    }

    else if(btnCnt == 2) {
        digitalWrite(redLed, 0);
        digitalWrite(yellowLed, 1);
        digitalWrite(blueLed, 0);
    }
    else if(btnCnt == 3) {
        btnCnt = 0;
        digitalWrite(redLed, 0);
        digitalWrite(yellowLed, 0);
        digitalWrite(blueLed, 1);
*/