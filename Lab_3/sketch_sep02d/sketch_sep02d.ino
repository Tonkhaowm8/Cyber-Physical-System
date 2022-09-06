#include <EEPROM.h>

struct MyObject {
  char field1[7];
  char date[11];
  char company[4];
};

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  int eeAddress = 0;   //Location we want the data to be put.


  //One simple call, with the address first and the object second.


  /** Put is designed for use with custom structures also. **/

  //Data to store.
  MyObject customVar = {
    "TH01234",
    "Oct 7, 2020",
    "SIIE"
  };

  eeAddress += sizeof(float); //Move address to the next byte after float 'f'.

  EEPROM.put(eeAddress, customVar);
}

void loop() {   /* Empty loop */ }
