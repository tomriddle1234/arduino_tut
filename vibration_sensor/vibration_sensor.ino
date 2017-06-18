// Watch video here: https://www.youtube.com/watch?v=235BLk7vk00

/* Vibration sensor connected to Arduino pins as follows:
 Arduino            Vibration Sensor
   D9                    DOut
   GND                   GND
   +5V                   VCC     
   
   D13                Indication LED   
*/

int EP =9;

int shakeCount = 0 ;
unsigned long currenttime ;
void setup(){
  pinMode(EP, INPUT); //set EP input for measurment
  Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}
void loop(){
  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);

  if (measurement > 30000){
    if (shakeCount == 0)
      currenttime = millis() ;
    shakeCount += 1; 
    Serial.println("Shake add 1");
    delay(500);
  }

  if (shakeCount > 1 && millis() - currenttime < 3000){
    Serial.println("Shake twice.");
    shakeCount = 0 ;
    delay(1000) ;
  }
  else if (shakeCount > 1 && millis() - currenttime >= 3000){
    shakeCount = 0 ;
    delay(500) ;
  }
  
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (EP, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}

