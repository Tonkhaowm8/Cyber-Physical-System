#include <SoftwareSerial.h>
SoftwareSerial BLESerial(2,3); // RX = 2, TX = 3

long previousMillis_BLE = 0;
long previousMillis_SRE = 0;

int interval_BLE = 100;
int interval_SRE = 200;
void setup()
{
  Serial.begin(9600);

  BLESerial.begin(9600);
  while(!Serial){
    ; // wait for serial port to connect
  }
  Serial.println("Ready to go");
}
void loop(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_BLE > interval_BLE) {
    previousMillis_BLE = currentMillis;
    while (BLESerial.available() > 0){
      String in_str = BLESerial.readString();
      if (in_str.length() == 0); 
      else if (in_str != "read"){
        Serial.println(in_str);
      } else {
        while (in_str != "stop"){
          BLESerial.println(analogRead(A0));
          in_str = BLESerial.readString();
          delay(3000);
        }
      }
      BLESerial.println("Stopped");
    }
  }

  if (currentMillis - previousMillis_SRE > interval_BLE) {
    previousMillis_SRE = currentMillis;
    while (Serial.available()){
      BLESerial.print((char) Serial.read());
    }
  }
}
