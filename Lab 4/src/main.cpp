#include <Arduino.h>
/*
void setup() {
  Serial.begin(9600);

}

void loop() {
  float input = analogRead(A0);
  float outputValue = map(input, 0, 1023, 0, 255);
  analogWrite(3,outputValue);


  delay(500);


  Serial.println(input);
  
}
*/

/*
part 2
char ch;
int motorPin = 3; // PWM pin where the motor/MOSFET is connected

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  
  // Wait for Serial Monitor to connect
  while (!Serial); 
  
  Serial.println("--- DC Motor Control ---");
  Serial.println("Enter a speed (0 to 255)");
  Serial.println("Enter 'q' to stop and exit loop");
}

void loop() {
  // Main control loop
  while (1) {
    if (Serial.available() > 0) {
      // Check if the first character is 'q' to quit
      if (Serial.peek() == 'q') {
        ch = Serial.read();
        Serial.println("Quitting current state...");
        analogWrite(motorPin, 0); // Safety: Stop motor on quit
        break; 
      }

      // Otherwise, parse the integer for speed
      int speed = Serial.parseInt();

      // Validate speed range
      if (speed >= 0 && speed <= 255) {
        analogWrite(motorPin, speed);
        Serial.print("Motor speed set to: ");
        Serial.println(speed);
      } else {
        Serial.println("Invalid input. Please enter 0-255 or 'q'.");
      }

      // Clear any remaining characters (like \n or \r) from the buffer
      while (Serial.available() > 0) {
        Serial.read();
      }
    }
  }
  
  // After 'break', it stays here until the loop() starts over
  delay(1000);
}

*/


/*
part 3

#include <Servo.h>
Servo myservo;
int pos=0;
double angle;
void setup()
{
 Serial.begin(9600);
 myservo.attach(9);
}
void loop()
{
 for (pos=0; pos<=180; pos+=1)
 {
 myservo.write(pos);
 delay(15);
 }
 for (pos=180; pos>=0; pos-=1)
 {
 myservo.write(pos);
 delay(15);
 }
}

*/

#include <Servo.h>
Servo myservo;
int value; //variable to readthe value from analog pin
double angle;
void setup()
{
 Serial.begin(9600); //initialize the Serial Monitor
 myservo.attach(9); //attaches the servo on pin 9 to the servo object
}
void loop()
{
 value = analogRead(A0); //reads the value of the potentiometer (value between 0 and 1023)
 angle = map(value, 0, 1023, 0, 180); //scale it to use it with the servo (value between 0 and 180)
 Serial.println(angle);
 myservo.write(angle);
 delay(15);
}