#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  //1602 LCD로 설정

int count = 0;

void setup()
{
  lcd.init();    //LCD 초기화
  lcd.backlight(); //백라이트를 켠다
  lcd.setCursor(0,0);          //커서를 0,0으로 이동
}

void loop()
{
    lcd.setCursor(0,0); //커서를 0,0으로 이동
    lcd.print(count);   //count값을 LCD에 표시
    count = count + 1;  //count값을 1씩 증가시킨다
    delay(1000); //1초 기다린다
}
