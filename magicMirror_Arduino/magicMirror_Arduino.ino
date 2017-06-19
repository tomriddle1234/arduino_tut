 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int _photocellReading;     // the analog reading from the analog resistor divider

int pirPin = 9;               // choose the input pin (for PIR sensor)
int pirState = LOW; 
int _val = 0;  

/////////////////////////////
//VARS
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 10;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  


void setup(void) {
  pinMode(pirPin, INPUT);
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(500);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
  
  
}
 
void loop(void) {
  
  checkPIRStateSimple();
  _photocellReading = analogRead(photocellPin);  
   
  checkLightSensorSimple(_photocellReading);
  
  delay(500);
}

void checkLightSensorSimple (int photocellReading){
//  Serial.println(photocellReading);
//  delay(10);
  if (photocellReading >= 900){
    Serial.println("Light Trigger");
    delay(10);
  }
}

void checkPIRStateSimple(){
      if(digitalRead(pirPin) == HIGH){
//       Serial.println("High");
//       delay(10);
       if(lockLow){  
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;            
//         Serial.println("---");
//         Serial.print("motion detected at ");
//         Serial.print(millis()/1000);
//         Serial.println(" sec"); 
         Serial.println("Body In");
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin) == LOW){    
//      Serial.println("Low");
//      delay(10);   
       if(takeLowTime){
          lowIn = millis();          //save the time of the transition from high to LOW
          takeLowTime = false;       //make sure this is only done at the start of a LOW phase
       }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
//           Serial.print("motion ended at ");      //output
//           Serial.print((millis() - pause)/1000);
//           Serial.println(" sec");
           Serial.println("Body Out");
           delay(50);
           }
       }
}



