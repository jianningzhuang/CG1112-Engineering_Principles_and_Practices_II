#include "Arduino.h"

#define PIN4 (1 << 4)
#define PIN5 (1 << 5)
#define PIN6 (1 << 6)
#define PIN7 (1 << 7)

void setup() {
  DDRD = (PIN4 | PIN5 | PIN6 | PIN7);
  Serial.begin(9600);

}

void loop() {
  PORTD = B00000000;
  delay(500);
  Serial.println(PORTD);
  PORTD = B00010000;
  delay(500);
  PORTD = B00100000;
  Serial.println(PORTD);
  delay(500);
  PORTD = B00110000;
  delay(500);
  PORTD = B01000000;
  delay(500);
  PORTD = B01010000;
  delay(500);
  PORTD = B01100000;
  delay(500);
  PORTD = B01110000;
  delay(500);
  PORTD = B10000000;
  delay(500);
  PORTD = B10010000;
  delay(500);

}
