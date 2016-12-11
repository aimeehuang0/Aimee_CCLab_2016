/*Modified from 
 * Arduino to Processing: Serial Communication without Firmata by thelostspore
 * http://www.instructables.com/id/Arduino-to-Processing-Serial-Communication-withou/?ALLSTEPS
 */
int AnalogPin0 = A0;
void setup() {
  Serial.begin(9600);
}
void loop() {
    int TempVal = analogRead(AnalogPin0);
    Serial.println(TempVal,DEC);
    delay(1000);
}
