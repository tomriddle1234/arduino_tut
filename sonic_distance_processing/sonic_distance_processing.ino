const int pingPin = 8;
const int echoPin = 9;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
  // establish variables for duration of the ping
  int duration;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH); // Read pulse length and store it in 'duration'
  int val = map(duration, 1000, 5000, 0, 255); // Map duration to the range 0 - 255
  val = constrain(val, 0, 255); // Limit to desired range
  Serial.write(val); // Print as bytes
  delay(5);
}
