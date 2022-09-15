#include <Wire.h>

void setup()
{
 // Potentiometer
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

//byte x = 0;


void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(analogRead(A1));             // sends one byte  
  Wire.endTransmission();    // stop transmitting
  delay(500);
}
