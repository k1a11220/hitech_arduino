int redPin = D5 ;
int greenPin = D6 ;
int bluePin = D7 ;

void setup()
{
 pinMode(redPin,OUTPUT);
 pinMode(greenPin,OUTPUT);
 pinMode(bluePin,OUTPUT);
}

void loop()
{
  setColor(255, 0, 0); // red
  delay(2000);
  setColor(0, 255, 0); // green
  delay(2000);
  setColor(0, 0, 255); // blue
  delay(2000); 
  setColor(255, 255, 0); // yellow
  delay(2000); 
  setColor(255, 0, 255); // purple
  delay(2000);
  setColor(0, 255, 255); // aqua
  delay(2000);
  setColor(255, 255, 255); // white
  delay(2000);
  setColor(0, 0, 0); // Off
  delay(2000); 
}
 
// RGB 값을 받아 analogWrite를 통해 각 핀에 연결된 LED에 전달 함수
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}





