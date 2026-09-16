#include <Arduino.h>
/*
void setup() {
  Serial.begin(9600);
    pinMode(8, OUTPUT);

  // put your setup code here, to run once:
}

void loop() {
  float input = analogRead(A0) * (5.0 / 1023);     
  digitalWrite(8, HIGH);
  delay(3000); 
  digitalWrite(8, LOW);
  delay(3000);             
}
*/

const int pResistor = A0; 
const int ledPin=9; 

int value; 

void setup(){
pinMode(ledPin, OUTPUT); 
pinMode(pResistor, INPUT); 
  Serial.begin(9600);
}
void loop(){
 value = analogRead(pResistor);
  Serial.println(value);
 
 if (value < 500){
 digitalWrite(ledPin, LOW); 
 }
 else{
 digitalWrite(ledPin, HIGH); 
 }
  
 delay(500); 
}