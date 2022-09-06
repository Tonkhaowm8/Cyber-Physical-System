#include <EEPROM.h>

struct MyObject{
  char field1[7];
  char date[11];
  char company[4];
};

void setup(){

  float f = 0.00f;   //Variable to store data read from EEPROM.
  int eeAddress = 0; //EEPROM address to start reading from

  Serial.begin( 9600 );
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  // get() can be used with custom structures too.
  eeAddress = sizeof(float); //Move address to the next byte after float 'f'.
  MyObject customVar; //Variable to store custom object read from EEPROM.
  EEPROM.get( eeAddress, customVar );

  //Serial.println( customVar.field1 );
  Serial.println( customVar.date);
  Serial.println( customVar.company);
}

void loop(){
  
}
