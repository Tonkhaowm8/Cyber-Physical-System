#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  for(int i=0; i < 3; i++){
    Serial.println(EEPROM.read(i));
    delay(4000);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
