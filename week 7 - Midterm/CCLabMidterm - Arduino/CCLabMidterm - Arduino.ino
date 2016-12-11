#include <Servo.h>

//code for testing Ultrasonic Module
#define ECHOPIN 8        // Pin to receive echo pulse 
#define TRIGPIN 9        // Pin to send trigger pulse

Servo myservo; // create servo object to control a servo
int pos = 0;
boolean punch = false;
float distance;

int totalPunch=0;
int punched=0;
int sensorValue = 0;
  
void setup() 
{ 
  Serial.begin(9600); 
  myservo.attach(13);
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 
}
void loop() 
{ 
  Serial.print(totalPunch);
  Serial.print(" ");
  Serial.print(punched);
  Serial.println();
  // Start Ranging -Generating a trigger of 10us burst 
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  // Distance Calculation
  distance = pulseIn(ECHOPIN, HIGH); 
  distance= distance/58; 
//  Serial.println(distance);

  if(distance<=15&&distance!=0)
  {
    tryPunch();
  }
}

void tryPunch()
{
   totalPunch++;
   for (pos = 70; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
   for (pos = 150; pos >=70; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    delay(1000);
}

