void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("FLASHEND DEC: ");
  Serial.println(FLASHEND);
  Serial.print("FLASHEND HEX: ");
  Serial.println(FLASHEND, HEX);
  Serial.print("RAMEND DEC: ");
  Serial.println(RAMEND);
  Serial.print("RAMEND HEX: ");
  Serial.println(RAMEND, HEX);
  Serial.print("E2END DEC: ");
  Serial.println(E2END);
  Serial.print("E2END HEX: ");
  Serial.println(E2END, HEX);
}

void loop() {
  // put your main code here, to run repeatedly:

}
