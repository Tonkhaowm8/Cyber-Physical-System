const int trigPin = 9;
const int echoPin = 10;
long duration;
int SampleTime = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String incomingBytes = Serial.readString();
    SampleTime = incomingBytes.toInt();
    Serial.println(incomingBytes);
    Serial.println(0);
  }
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  Serial.println(duration);
  delay(SampleTime-1);
} 
