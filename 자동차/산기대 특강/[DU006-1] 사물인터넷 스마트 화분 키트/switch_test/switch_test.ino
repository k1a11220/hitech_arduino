int switchPin = D0;

void setup() 
{
      pinMode(switchPin , INPUT);
      Serial.begin(9600);
}

void loop() 
{
      Serial.println(digitalRead(switchPin));
}
