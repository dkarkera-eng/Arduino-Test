#include <Arduino.h>

/*
void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogInput = analogRead(A0);
  float voltage  = analogInput * (5.0 / 1023.0);
  float angle = map(analogInput, 0, 1023, 0, 270); 
    
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.println(" V");

  Serial.println("Angle: ");

  Serial.println(angle);
  Serial.println(" degree\n #####");

  
  delay(1000);
}

*/
void setup()
{
  Serial.begin(9600);

}

void loop()
{
  float input = analogRead(A0) * (5.0 / 1023);                 
  
  
  float temperature = (30 + (((1.324)-input)/0.0082));
  
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  delay(1000);
}

