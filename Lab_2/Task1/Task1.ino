//defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

//defines variables
long duration; // recieved value from sensor
int SampleTime = 1000; // Sampling Time

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    String incomingBytes = Serial.readString();
    SampleTime = incomingBytes.toInt();
    Serial.println(incomingBytes);
  }

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Prints the distance on the Serial Monitor
  Serial.println(duration);
  delay(SampleTime - 1); // Sampling Time
}
