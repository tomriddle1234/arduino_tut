const int TrigPin=8;
const int EchoPin=9;
float cm ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  cm = pulseIn(EchoPin,HIGH)/58.0;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}
