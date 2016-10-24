/*By Aimee Abalos*/
import processing.serial.*;

Serial myPort;        // The serial port
int totalPunch = 0, Punch = 0;
int barwidth = 0;
float barPos = 50;
PFont font;


void setup () {
  // set the window size:
  size(500, 500);
  
  font = createFont("Arial Bold",20);
  textFont(font);  
  //myPort = new Serial(this, Serial.list()[0], 9600);
  
  barwidth = width - 100;
  
  frameRate(5);
}

void draw () {
  
  // get the ASCII string:
  //String readPunch = myPort.readStringUntil('\n');
  String readPunch = "10 6";
  String[] punchList = split(readPunch, ' ');
  
  totalPunch = int(punchList[0]);
  Punch = int(punchList[1]);
    
  background(255);
  
  //Title Bar
  //title bar rec
  fill(88,182,194);
  noStroke();
  rect(0,0, width, 100);
  
  //title bar title
  textAlign(CENTER);
  textSize(35);
  fill(255);
  text("YOU'VE BEEN DISTRACTED", width/2,60);
  
  //COUNT
  //Count circle
  fill(238,81,47);
  ellipse(width/2,height/2-40, 150, 150);
  
  //Count outline
  stroke(238,81,47);
  strokeWeight(6);
  noFill();
  ellipse(width/2,height/2-40, 180, 180);
  
  //times
  fill(255);
  textSize(100);
  text(Punch, width/2, height/2);
  
  fill(109,115,113);
  textSize(20);
  text("Times", width/2, height/1.5);
  
  //Progressbar Outline
  //Gray Outer Outline
  fill(210,211,212);
  stroke(210,211,212);
  strokeWeight(7);
  rect(25, height/1.3, barwidth+40, 40, 40);
  
  //White Outline
  rectMode(CORNER);
  stroke(255);
  strokeWeight(35);
  line(50, height/1.235, barwidth,height/1.235);
  
  //Grey Outline
  stroke(240,239,239);
  strokeWeight(25);
  line(50, height/1.235, barwidth,height/1.235);
  
  fill(0);
  textSize(20);
  text(totalPunch, width-60, (height/1.3)+27);
  
  //Orange Bar
  barPos = barwidth * (float(Punch)/float(totalPunch));
  stroke(245,173,39);
  strokeWeight(25);
  line(50, height/1.235, barPos,height/1.235);
  
  fill(255);
  textSize(20);
  text(Punch, barPos, (height/1.3)+27);
}