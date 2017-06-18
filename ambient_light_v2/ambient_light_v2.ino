//https://anasdalintakam.blogspot.in/
//this code is for sensing ambient light using sparkfuns temt6000 ambient light sensor and arduino


int temt6000Pin = A0;// Analog pin for reading sensor data
float light;
int light_value;
void setup() {
  Serial.begin(9600);
  pinMode(temt6000Pin, INPUT); //data pin for ambientlight sensor
//  pinMode(13, OUTPUT);
}

void loop() {
  int light_value = 1024 -  analogRead(temt6000Pin);
//  light = light_value * 0.0976;// percentage calculation 
//  light_value = map(light_value,0,1023,0,255) ;
  Serial.println(light_value);
  delay(100);
//  if (light_value > 1000) {
//    digitalWrite(13, HIGH);
//  }
//  else {digitalWrite(13,LOW);}

}
