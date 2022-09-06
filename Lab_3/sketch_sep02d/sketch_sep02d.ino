#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  String productInfo[] = {"TH01234", "Oct 7 2020", "SIIE"};
  for(int i = 0; i < 3; i++){
    EEPROM.put(i, productInfo[i]);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
