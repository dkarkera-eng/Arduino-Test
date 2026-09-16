#include <Arduino.h>

/*
//potentiometer readings
double value;
double angle;

//ultrasonic sensor reading
const int trigPin = 2;
const int echoPin = 3;

//ultrasonic sensor calculations
long duration;
double distance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  Serial.begin(9600); // Must match Receiver's baud rate
}

void loop() {
    // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  value = analogRead(A0);
  angle = map(value,0,1023,0,180);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;

  //  Serial.println(distance);

  
  if(angle<90 && distance>10 ){  
    Serial.println('B'); // Send character 'B'
    delay(2000);
  }
  
  else if(angle>90 || distance<10 ){
  Serial.println('A'); // Send character 'A'
    delay(2000);       // Wait 2 seconds
  }
  
}
*/

double sensorValue = 0; // Variable to store the value read from the analog pin

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Read the value from the specified analog input pin (A0):
  sensorValue = analogRead(A0);

  // Print the value to the Serial Monitor:
  Serial.println(sensorValue);

  // Add a small delay to avoid flooding the serial monitor with data:
  delay(2000); 
}
