import processing.sound.*;

import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

int lastPlayVal = 0 ;
//paper roll turn 5 times
int intervalCycleNum = 5 ;
int signalCountPerCycle = 20 ;

void setup(){
  //load music here
  String portName = Serial.list()[0];
  println(portName);
  myPort = new Serial(this, portName, 9600);

}
void draw()
{
  //assume just one direction
  if ( myPort.available() > 0) {  // If data is available,
    //val = Math.abs(int(myPort.readStringUntil('\n')));         // read it and store it in val
    
    String test = myPort.readStringUntil('\n');
    if (test != null){
      val = int(test.trim()) ;
      //println(val);
      //println(val % 100) ;
    } 
  }
  
  int count = intervalCycleNum * signalCountPerCycle ;
  //println("Calculated cycles " + count) ;
  if (val % 100 == 0 && val != lastPlayVal){
    println("Triggered once.Current Val " + val);
    lastPlayVal = val; 
  }
  //if (Math.abs(val) > Math.abs(lastPlayVal) + count){
  //  lastPlayVal = val ;
  //  println("Triggered once.Current Val " + val);
  //  //trigger lock here
    
  //  //start play
    
  //  //delay
    
  //}
  
  
  
}