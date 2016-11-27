// Declare a "SerialPort" object
var serial;
var latestData = "0 0";  // you'll use this to write incoming data to the canvas

var totalPunch = 40, Punch = 0;
var barwidth = 0;
var barPos = 50;
var portName = "COM3";

function setup() {

  

  createCanvas(windowWidth, windowHeight);
  barwidth = windowWidth - 100;

  // Instantiate our SerialPort object
  serial = new p5.SerialPort();

  // Get a list the ports available
  // You should have a callback defined to see the results
  serial.list();

  // Assuming our Arduino is connected, let's open the connection to it
  // Change this to the name of your arduino's serial port
  serial.open("COM3", 9600);

  // When we connect to the underlying server
  serial.on('connected', serverConnected);

  // When we get a list of serial ports that are available
  serial.on('list', gotList);
  // OR
  //serial.onList(gotList);

  // When we some data from the serial port
  serial.on('data', gotData);
  // OR
  //serial.onData(gotData);

  // When or if we get an error
  serial.on('error', gotError);
  // OR
  //serial.onError(gotError);

  // When our serial port is opened and ready for read/write
  serial.on('open', gotOpen);
  // OR
  //serial.onOpen(gotOpen);

  // Callback to get the raw data, as it comes in for handling yourself
  //serial.on('rawdata', gotRawData);
  // OR
  //serial.onRawData(gotRawData);
}

// We are connected and ready to go
function serverConnected() {
  println("Connected to Server");
}

// Got the list of ports
function gotList(thelist) {
  println("List of Serial Ports:");
  // theList is an array of their names
  for (var i = 0; i < thelist.length; i++) {
    // Display in the console
    println(i + " " + thelist[i]);
  }
}

// Connected to our serial device
function gotOpen() {
  println("Serial Port is Open");
}

// Ut oh, here is an error, let's log it
function gotError(theerror) {
  println(theerror);
}

// There is data available to work with from the serial port
function gotData() {
  var currentString = serial.readLine("\n");  // read the incoming string
  trim(currentString);                    // remove any trailing whitespace
  if (!currentString) return;             // if the string is empty, do no more
  console.log(currentString);             // println the string
  latestData = currentString;            // save it for the draw method
}

// We got raw from the serial port
function gotRawData(thedata) {
  println("gotRawData" + thedata);
}

// Methods available
// serial.read() returns a single byte of data (first in the buffer)
// serial.readChar() returns a single char 'A', 'a'
// serial.readBytes() returns all of the data available as an array of bytes
// serial.readBytesUntil('\n') returns all of the data available until a '\n' (line break) is encountered
// serial.readString() retunrs all of the data available as a string
// serial.readStringUntil('\n') returns all of the data available as a string until a specific string is encountered
// serial.readLine() calls readStringUntil with "\r\n" typical linebreak carriage return combination
// serial.last() returns the last byte of data from the buffer
// serial.lastChar() returns the last byte of data from the buffer as a char
// serial.clear() clears the underlying serial buffer
// serial.available() returns the number of bytes available in the buffer
// serial.write(somevar) writes out the value of somevar to the serial device

function draw() {
  // get the ASCII string:
  //String readPunch = myPort.readStringUntil('\n');
  var readPunch = "40 0";
  // var readPunch = latestData;
  var punchList= readPunch.split(' ');

  console.log(punchList[0]);
  
  totalPunch = int(punchList[0]);
  Punch = int(punchList[1]);
    
  background(255);
  
  //Title Bar
  //title bar rec
  fill(88,182,194);
  noStroke();
  rect(0,0, windowWidth, 100);
  
  //title bar title
  textAlign(CENTER);
  textSize(35);
  fill(255);
  text("YOU'VE BEEN DISTRACTED", windowWidth/2,60);
  
  //COUNT
  //Count circle
  fill(238,81,47);
  ellipse(windowWidth/2,windowHeight/2-40, 150, 150);
  
  //Count outline
  stroke(238,81,47);
  strokeWeight(6);
  noFill();
  ellipse(windowWidth/2,windowHeight/2-40, 180, 180);
  
  //times
  fill(255);
  textSize(100);
  text(totalPunch, windowWidth/2, windowHeight/2);

  stroke(255);
  fill(238,81,47);
  textSize(20);
  text("Times", windowWidth/2, windowHeight/1.5);
  
  //Progressbar Outline
  //Gray Outer Outline
  fill(210,211,212);
  stroke(210,211,212);
  strokeWeight(7);
  rect(25, windowHeight/1.3, barwidth+40, 40, 40);
  
  //White Outline
  rectMode(CORNER);
  stroke(255);
  strokeWeight(35);
  line(50, windowHeight/1.250, barwidth,windowHeight/1.250);
  
  //Grey Outline
  stroke(240,239,239);
  strokeWeight(25);
  line(50, windowHeight/1.250, barwidth,windowHeight/1.250);
  

  noStroke();
  fill(0);
  textSize(20);
  text(totalPunch, windowWidth-60, (windowHeight/1.3)+27);
  
  //Orange Bar
  barPos = barwidth * (float(totalPunch)/float(totalPunch));
  stroke(245,173,39);
  strokeWeight(25);
  line(50, windowHeight/1.250, barPos,windowHeight/1.250);
  
  noStroke();
  fill(255);
  textSize(20);
  text(totalPunch, barPos, (windowHeight/1.3)+27);
  // Polling method
  /*
  if (serial.available() > 0) {
  var data = serial.read();
  ellipse(50,50,data,data);
}
*/
}
