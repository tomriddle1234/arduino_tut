void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Body In");
  delay(5000);
  Serial.println("Light Trigger");
  delay(5000);
    Serial.println("Body Out");
  delay(5000);

}
