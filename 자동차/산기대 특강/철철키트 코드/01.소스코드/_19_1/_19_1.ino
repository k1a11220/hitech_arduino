#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  //1602 LCD로 설정

void setup()
{
  lcd.init();    //LCD 초기화
  lcd.backlight(); //백라이트를 켠다
  lcd.print("Hello ChulChul"); //Hello ChulChul 문구 출력
}

void loop()
{
}
