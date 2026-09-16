#include <Arduino.h>

// put function declarations here:
//Part 1 
/*
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,HIGH);
  delay(250);
  digitalWrite(13,LOW);
  delay(250);
}
*/

//part 2 lab
/*void setup()
{
  pinMode(13, OUTPUT);

  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(7, HIGH);
  digitalWrite(13, HIGH);
  delay(500); 
  digitalWrite(7, LOW);
  digitalWrite(13, LOW);
  delay(500);

}

*/

//part 3
/*
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  pinMode(2, INPUT);

}

void loop()
{
	int pushButton = digitalRead(2);
    Serial.println(pushButton);
    digitalWrite(13,LOW);
    if(pushButton>0){digitalWrite(13,HIGH);}
  
  
}

*/

//part 4

void setup()
{
  for (int i =0; i <14; i++)
 {
 pinMode(i,OUTPUT);
 }

}

void loop()
{
  for(int i =0; i<14; i++)
 {
 digitalWrite(i,HIGH);
 delay(100);
 digitalWrite(i,LOW);
 } 
  
  for(int i =13; i!=0; i--)
 {
 digitalWrite(i,HIGH);
 delay(100);
 digitalWrite(i,LOW);
 

 }
}

