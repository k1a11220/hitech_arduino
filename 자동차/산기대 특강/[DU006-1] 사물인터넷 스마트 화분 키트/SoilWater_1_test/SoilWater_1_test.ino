int sensorValue = 0; //센서의 값을 받아 옴
int SoilWaterPin = A0; //토양수분센서 pin번호

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
  sensorValue = analogRead(SoilWaterPin); 
  
  if ( sensorValue < 300 )
  {
        Serial.print("sensor = " );                       
        Serial.print(sensorValue);  
        Serial.println("-> Please give me some water ");
  }
  
  else
  {
        Serial.print("sensor = " );                       
        Serial.print(sensorValue);  
        Serial.println("-> The soil is in good condition ");
  }
  delay(1000);       
}
