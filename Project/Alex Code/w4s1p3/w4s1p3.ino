#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED_DELAY  100
void setup()
{
  // Set pins 11 and 12 to output. Pin 11 is PB3, pin 12 is PB4
  DDRB |= 0b00011000;

  EICRA |= 0b00000010;

  EIMSK |= 0b00000001;

  sei();

  Serial.begin(9600);
}

ISR(INT0_vect){
  Serial.println("Hi");
}

void loop()
{
  int a = 1;
}
