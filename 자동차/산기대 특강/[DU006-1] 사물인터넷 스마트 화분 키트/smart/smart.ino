#include <ESP8266WiFi.h>                   //WiFi 통신을 위한 라이브러리

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>           //LCD 라이브러리 사용하기
LiquidCrystal_I2C lcd(0x27,16,2);


const char* accessToken = "o.OL9mTrdrGq6Ay6fbk1clr14zBvQxNYfb";  //  PushBullet에서 복사한 토큰주소를 적어주세요
String Title = " Water "; 

const char* ssid = "melab";             // 사용할 공유기 ID를 적어주세요
const char* password = "melab12345";        // 사용할 공유기 패스워드를 적어주세요


// pin 번호 선언//////////////////////////////////////////////////////////////

int pinSw = D0;          //스위치 Pin

int pinMotor_A = D3;      //펌프모터 핀 (모터 드라이버 모듈 A1-A )
int pinMotor_B = D4;      //펌프모터 핀 (모터 드라이버 모듈 A1-B )

int pinRed = D5;        //RGB_LED RED Pin
int pinGreen = D6;     //RGB_LED GREEN Pin
int pinBlue = D7;      //RGB_LED BLUE Pin


int pinSoilWater = A0; //토양수분센서 Pin

////////////////////////////////////////////////////////////////////////////////



// 전역 변수 선언 //////////////////////////////////////////////////////////////

int SoilWaterValue = 0; //수분센서 값 저장 변수
int SwValue = 0;   //스위치 상태 저장 변수

///////////////////////////////////////////////////////////////////////////////



WiFiClientSecure client;


void setup() 
{
    Serial.begin(9600);               // 시리얼 통신 시작, 통신속도 설정
    
    pinMode(pinMotor_A, OUTPUT);    // 펌프모터 핀모드 설정
    pinMode(pinMotor_B, OUTPUT);    // 펌프모터 핀모드 설정

    pinMode(pinRed, OUTPUT);      // RGB_LED RED 핀모드 설정
    pinMode(pinGreen, OUTPUT);    // RGB_LED GREEN 핀모드 설정
    pinMode(pinBlue, OUTPUT);     // RGB_LED BLUE 핀모드 설정
    
    pinMode(pinSw, INPUT_PULLUP); // 스위치 풀업저항 사용


     WiFi.begin(ssid, password);

     
      while (WiFi.status() != WL_CONNECTED) 
      { 
            delay(500);
            Serial.print(".");
      }
      
      Serial.println("");
      Serial.print("Connected to ");
      Serial.println(ssid);
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      
}



void loop() 
{
    SoilWaterValue = map(analogRead(pinSoilWater), 0, 1023, 0,100 );   // 토양 수분 센서 값을 읽습니다.
    SoilWaterValue = SoilWaterValue;
         
 //시리얼 모니터에 출력하기 //////////////////////////////////////////////////////////////
    
    Serial.print("Swich Value : ");
    Serial.println(SwValue);

   //////////////////////////////////////////////////////////////////////////////////////////



    if ( SwValue == 0 )
    {
        digitalWrite(pinMotor_A,HIGH);   //모터 작동 On
        digitalWrite(pinMotor_B,LOW);   //모터 작동 On

    }
    
    else if ( SwValue == 1 )
    {
        digitalWrite(pinMotor_A,LOW); //모터 작동 Off
        digitalWrite(pinMotor_B,LOW); //모터 작동 Off     
     
    }


   
   //LCD 창에 토양의 수분량을 백분율로 출력//////////////////////////////////////////////////////////////////
   
  lcd.init();                  // LCD 초기화 
  lcd.backlight();               // LCD 백라이트 on
  lcd.setCursor(0,0);              // 0.0 좌표로 커서 이동
  lcd.print("Soil Water: ");         // 'Soil Water' 문구 출력 
  lcd.setCursor(12,0);            
  lcd.print(SoilWaterValue);        // 토양 수분 센서 측정 값 출력 
  lcd.print("%");
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  

   

  //토양 수분 상태에 따른 RGB_LED로 경고등 코딩하기///////////////////////////////////////////////////////////////////////////
  
  if ( SoilWaterValue < 26 )      // 토양에 물이 충분하다면 26% 미만일 때 (기준 임의로 지정)
  {
     analogWrite(pinRed,255);      // Red on
     analogWrite(pinGreen,0);       // Green off
     analogWrite(pinBlue,0);       // Blue off
     delay ( 200 );             //딜레이 0.2초
     
     analogWrite(pinRed,0);       // Red off
     analogWrite(pinGreen,0);      // Green off
     analogWrite(pinBlue,0);       // Blue off
     delay ( 100 );           //딜레이 0.1초

     lcd.setCursor(0,1);
     lcd.print("Water, please");           // 'Water,please' 문구 출력
     sendToPushBullet("Water, please");   //   PushBullet 전송 메시지
     delay(3000);
  }
  
  else if (SoilWaterValue >= 26 && SoilWaterValue < 50 )    // 토양에 물이 충분하다면 26% 이상 50% 미만일 때 (기준 임의로 지정)
  {
     analogWrite(pinRed,0);         // Red off
     analogWrite(pinGreen,255);        // Green on
     analogWrite(pinBlue,0);        // Blue off
  }
  
  else if (SoilWaterValue >= 50 && SoilWaterValue < 100 )    // 토양에 물이 충분하다면 50% 이상 100% 미만일 때 (기준 임의로 지정)
  {
     analogWrite(pinRed,0);         // Red off
     analogWrite(pinGreen,0);         // Green off
     analogWrite(pinBlue,255);          // Blue on
  }
  
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // 토양에 물 공급하기
    // 스위치를 누르는 동안 펌프모터가 작동 시키기
    
   ////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    
}

void sendToPushBullet(String Msg) 
{
  Msg = "{\"type\": \"note\", \"title\": \"" + Title + "\", \"body\": \"" + Msg + "\"}\r\n";
  if (client.connect("api.pushbullet.com", 443)) 
  {
    client.println("POST /v2/pushes HTTP/1.1");
    client.println("Host: api.pushbullet.com");
    client.println("Authorization: Bearer " + String(accessToken));
    client.println("Content-Type: application/json");
    client.println("Content-Length: " + String(Msg.length()) + "\r\n");
    client.print(Msg);  
    client.stop();
  }
}


