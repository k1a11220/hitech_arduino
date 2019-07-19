const int LED1 = A1;
const int LED2 = A2;
const int LED3 = A3;

static unsigned long swNowTime = 0;
static unsigned long swClickTime = 0;
static unsigned char oldSw1 = 0;
static unsigned char newSw1 = 0;
static unsigned int clickCnt = 0;


void setup(){
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(6,INPUT);
    Serial.begin(9600);
}

void loop(){
    ledblink();
    swclickconfig();
    swClickEvent();
    swNomalClick();
    swDoubleClick();
    swLongClick();
}

void ledblink(){
    static unsigned long led3prev_time = 0;
    static unsigned long led3curr_time = 0;
    static unsigned long led3State = 0;
    int led3duration = 100;
    led3curr_time = millis();
    if(led3curr_time-led3prev_time>=led3duration)
    {
        led3prev_time = led3curr_time;
        if(led3State==LOW)
        {
            led3State=HIGH;
        }
        else
        {
            led3State=LOW;
        }
        digitalWrite(LED1,!led3State);
        digitalWrite(LED2,!led3State);
        digitalWrite(LED3,led3State);
    }
}

void swclickconfig(){
    newSw1 = digitalRead(6);
    swNowTime = millis();
}

void swClickEvent(){
    if(swNowTime - swClickTime >= 10)
    {
        if(oldSw1 != newSw1)
        {
            oldSw1 = newSw1;
            if(newSw1 == 1)
            {
                clickCnt++; //클릭이벤트 발생
                if(clickCnt==1)
                {
                    swClickTime=swNowTime;                    
                }
            }
        }
    } 
}

void swNomalClick(){
    if(newSw1==0)
    {
        if(clickCnt==1)
        {
            if(swNowTime - swClickTime >= 400)
            {
                Serial.println("Click");
                clickCnt=0;
                swClickTime=swNowTime; 
            }
        }
    }
}

void swDoubleClick(){
    if(clickCnt==2)
    {
        if(swNowTime - swClickTime <= 400)
        {
            Serial.println("Double Click");
            clickCnt=0;
            swClickTime=swNowTime; 
        }
    } 
}
void swLongClick(){
    if(newSw1==1)
    {
        if(clickCnt==1)
        {
            if(swNowTime - swClickTime >= 600)
            {
                Serial.println("Long Click");
                clickCnt=0;
                swClickTime=swNowTime; 
            }
        }
    }    
}
