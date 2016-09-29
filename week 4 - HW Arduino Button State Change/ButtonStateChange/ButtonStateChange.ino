/*
 State change detection (edge detection)
  
 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED attached from pin 13 to ground (or use the built-in LED on
   most Arduino boards)

 created  27 Sep 2005
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/ButtonStateChange

 Modified 29 Sept 2016
 by Aimee Abalos
 */

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
boolean up = LOW;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
 
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    Serial.println(up);
    if (buttonState == HIGH) {
      up = !up;
      Serial.println("on");
    } else {
      Serial.println("off");
    }
    // Debouncing
    delay(30);
  }
  //save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;

  // turns on LED
  // digitalWrite(ledPin, up);

  // add blink
  if(up)
  {
    digitalWrite(ledPin, HIGH);
    delay(50);
  }
  digitalWrite(ledPin, LOW);
  delay(50);
  else{
    digitalWrite(ledPin, LOW);
  }
}









