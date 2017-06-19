 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int _photocellReading;     // the analog reading from the analog resistor divider

int inputPin = 9;               // choose the input pin (for PIR sensor)
int pirState = LOW; 
int _val = 0;  

void setup(void) {
  pinMode(inputPin, INPUT);
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
  
}
 
void loop(void) {
  _photocellReading = analogRead(photocellPin);  
  _val = digitalRead(inputPin); 
  
  checkPIRState(_val);
  checkLightSensor(_photocellReading);
  
  delay(1000);
}

void checkLightSensor(int photocellReading){
  Serial.print("Analog reading = ");
  Serial.print(photocellReading);     // the raw analog reading
 
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 10) {
    Serial.println(" - Dark");
  } else if (photocellReading < 200) {
    Serial.println(" - Dim");
  } else if (photocellReading < 500) {
    Serial.println(" - Light");
  } else if (photocellReading < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
}

void checkPIRState(int val){
   if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}

