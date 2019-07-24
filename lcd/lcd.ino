#include <LiquidCrystal.h>
#include <MsTimer2.h>
#include <Toggle.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
Toggle tgg(HIGH,LOW,LOW);
int m=0, s=0, c=0;

void stopwatch()
{
  c++;
  if(c==10)
  {
    c=0;
    s++;    
    if(s==60)
    {
      s=0;
      m++;      
      if(m==100)
        m=0;
      lcd.setCursor(0,0);
      if(m<10)
        lcd.write('0');
      lcd.print(m);
    }  
    lcd.setCursor(3,0);
    if(s<10)
      lcd.write('0');
    lcd.print(s);
  }  
  lcd.setCursor(6,0);
  lcd.print(c);  
}

void buttonIsr()
{
  if(tgg.toggle()==HIGH)
    MsTimer2::stop();
  else
    MsTimer2::start();
}

void setup(){
  lcd.begin(8, 2);
  lcd.print("00:00.0");
  MsTimer2::set(100, stopwatch);
  MsTimer2::start();
  attachInterrupt(0, buttonIsr, RISING);
}

void loop()
{
}