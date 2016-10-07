/*
  Modified From: Analog input, analog output, serial output
                 by Tom Igoe
                 Arduino Uno Tutorial analog inputs and measuring temperature
                 by eTechTom
                 https://www.youtube.com/watch?v=EbaY5D0O9S0
Modified by:Aimee Abalos
 */

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  //Outpute LED
  for(int pinNumber = 9; pinNumber<=10; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = sensorValue * 5.0 /1024;
  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
  
  outputValue = map(temperatureC, 15, 30, 0, 255);
  // change the analog out value:
   if(temperatureC < 19){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  } else if(temperatureC >= 19 && temperatureC < 24){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  } else{
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }
    
  // print the results to the serial monitor:
  Serial.print("sensor = ");Serial.print(sensorValue);
  Serial.print("\t output = ");Serial.println(outputValue);

  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(1);
}
