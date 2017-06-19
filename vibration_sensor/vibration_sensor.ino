// Watch video here: https://www.youtube.com/watch?v=235BLk7vk00

/* Vibration sensor connected to Arduino pins as follows:
 Arduino            Vibration Sensor
   D9                    DOut
   GND                   GND
   +5V                   VCC     
   
   D13                Indication LED   
*/

int EP =9;

//relay pin input
int RELAY_PIN = 10 ;
int RELAY_POWER_PIN = 11 ;

int shakeCount = 0 ;
unsigned long lastShakeTime ;

bool turn_flag = false ;

void setup(){
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_POWER_PIN, OUTPUT);
  digitalWrite(RELAY_POWER_PIN,HIGH);
  digitalWrite(RELAY_PIN,LOW); //keep it stop for the beginning
  
  pinMode(EP, INPUT); //set EP input for measurment
  Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}
void loop(){
  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);

  if (measurement > 15000){
    if (shakeCount == 0)
      lastShakeTime = millis() ;
    shakeCount += 1; 
    Serial.println("Shake add 1");
    delay(200);
  }

  if (shakeCount > 1 && millis() - lastShakeTime < 4000){
    Serial.println("Shake twice.");
    shakeCount = 0 ;
    turn_flag = !turn_flag ;
    trigger_relay() ;
    delay(200) ;
  }

 //reset time after 4 seconds no shake
 if (shakeCount == 1 && millis() - lastShakeTime >= 4000){
    shakeCount = 0 ;
    lastShakeTime = millis() ;
    Serial.println("Reset shake count");
    delay(200) ;
  }
  
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (EP, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}

void trigger_relay(){
  if (turn_flag){
    turn_on_relay() ;
  }
  else{
    turn_off_relay();
  }
}

void turn_on_relay(){
  digitalWrite(RELAY_PIN, HIGH) ;
  Serial.println("Fan RUN");  
  delay(1000) ;
}

void turn_off_relay(){
  digitalWrite(RELAY_PIN, LOW) ;
  Serial.println("Fan STOP");  
  delay(1000);
}

