/*Created By Aimee Abalos*/
import processing.serial.*;

Serial myPort;        // The serial port
float fTemp = 0;
String Temp;
PFont font;

void setup () {
  // set the window size:
  size(400, 300);
  
  font = createFont("Arial",20);
  textFont(font);
  
  myPort = new Serial(this, Serial.list()[0], 9600);
  
  frameRate(5);
}

void draw () {
  
  // get the ASCII string:
  String readTemp = myPort.readStringUntil('\n');

  if (readTemp != null) {
    // convert to an int and map to the screen height:
    fTemp = float(readTemp);
    
    //Change to degree celcius
    fTemp = ((fTemp * 5.0 /1024)-0.5)*100; 
    Temp = nf(fTemp,2,2);
    
    if(fTemp<=18)
      fTemp = 18;
    if(fTemp>=26.46)
      fTemp = 26.46;
    print(fTemp+" ");   
    //remove the decimal point
    
    
    fTemp = map(fTemp, 18, 26, 0, 180);
    println(fTemp);
  }
  
  
  background(255);
  fill(222,94,86);
  textSize(10);
  //minus the half of the text width for x
  text("18", 120, 90); 
  text("26", 288, 90); 
  textSize(50);
  
  text(Temp+" °C", width/2-90, height/2+35); 
  
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
  
  //Temp Degree Celcius
  
  
}