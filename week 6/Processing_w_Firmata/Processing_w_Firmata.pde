import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int temp;
float fTemp;
String sTemp;

PFont font;

void setup() {
  size(400, 300);
  
  font = createFont("Arial",20);
  textFont(font);

  // Prints out the available serial ports.
  println(Arduino.list());

  arduino = new Arduino(this, Arduino.list()[0], 57600);
}

void draw() {
    temp = arduino.analogRead(0);

    //Change to degree celcius
    fTemp = ((temp * 5.0 /1024)-0.5)*100; 
    sTemp = nf(fTemp,2,2);

    if(fTemp>26.46)
      arduino.digitalWrite(13, 1);
    if(fTemp<26.46)
      arduino.digitalWrite(13, 0);
    
    if(fTemp<=18)
      fTemp = 18;
    if(fTemp>=26.46)
      fTemp = 26.46;   
    
    
    
    fTemp = map(fTemp, 18, 26, 0, 180);
    println(fTemp);

    background(255);
    fill(222,94,86);
    textSize(10);
    //minus the half of the text width for x
    text("18", 120, 90); 
    text("26", 288, 90); 
    textSize(50);
    
    text(sTemp+" °C", width/2-90, height/2+35); 
    
    noFill();
    stroke(222,94,86);
    strokeWeight(4);
    rect(75, 95, 250, 40, 20);
  
    strokeWeight(30);
    line(100,115,100+10+fTemp,115);
    
    //18-26
    noStroke();
    fill(255);
    rect(125, 100, 5, 15);
    rect(146, 100, 5, 15);
    rect(167, 100, 5, 20);
    rect(188, 100, 5, 15);
    rect(209, 100, 5, 15);
    rect(230, 100, 5, 15);
    rect(251, 100, 5, 15);
    rect(272, 100, 5, 20);
    rect(293, 100, 5, 15);
    //+21
}

//import processing.serial.*;
//import cc.arduino.*;

//Arduino arduino;

//boolean LEDlight = false;

//void setup() {
//  size(400, 300);
//  arduino = new Arduino(this, Arduino.list()[0], 57600);
//}
//void draw(){
//}
//void mousePressed()
//{
//    println(LEDlight);
//    if(LEDlight)
//      arduino.digitalWrite(13, Arduino.HIGH) ;
//    else
//      arduino.digitalWrite(13, Arduino.LOW) ;  
      
//    LEDlight=!LEDlight;
//}