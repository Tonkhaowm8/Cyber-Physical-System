const int LEDPin = 13;
const int RLEDPin = 12;
char con_val = '0';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()>0)
  {
    con_val = char(Serial.read());
    LEDcontrol(con_val);  
  }
  delay(100);
}

void LEDcontrol(char con)
{
  if(con == '1')
  {
    Serial.print("From Arduino, RED LED is on \n");
    digitalWrite(RLEDPin, HIGH);
  }
  if(con == '0')
  {
    Serial.print("From Arduino, RED LED is OFF \n");
    digitalWrite(RLEDPin, LOW);
  }
  if(con == '2')
  {
    Serial.print("From Arduino, GREEN LED is ON \n");
    digitalWrite(LEDPin, HIGH);
  }
  if(con == '3')
  {
    double val = (analogRead(0)-512)/512.0;
    Serial.println(val);
  }
}
