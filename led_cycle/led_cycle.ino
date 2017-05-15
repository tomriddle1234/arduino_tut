int led=9;
int fadeAmount=3;
int brightness=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led,brightness);
  brightness=brightness+fadeAmount ;
  if (brightness <= 0 || brightness >= 255){
    delay(200);
    fadeAmount = -fadeAmount ;
  }
  delay(30);

}
