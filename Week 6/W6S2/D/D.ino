#include "Arduino.h"
#include <avr/interrupt.h>
unsigned int adcvalue, loval, hival;
void InitPWM()
{
  TCNT0 = 0;
  OCR0A = 0;
  TCCR0A = 0b00000001;
  TIMSK0 |= 0b10;
}
void startPWM()
{
  TCCR0B = 0b00000100;
}
ISR(TIMER0_COMPA_vect)
{
// Provide your code for the ISR
  //OCR0A = map(adcvalue, 690, 865, 0, 255);
  OCR0A = (adcvalue-690)*255/175;
  PORTB ^= (1 << PORTB5);

}
ISR(ADC_vect)
{
// Provide your code for the ISR
  loval = ADCL;
  hival = ADCH;
  adcvalue = (hival << 8) | loval;
  ADCSRA |= (1 << ADSC);
  
}
void setup() {
// put your setup code here, to run once:
  PRR &= 0b11111110;
  ADCSRA = 0b10001111;
  ADMUX = 0b01000000;
  DDRB |= 0b00100000;
  InitPWM();
  startPWM();
  sei();
  ADCSRA |= 0b01000000;
}
void loop() {}


//#define PIN6 (1 << 6)
//
//unsigned int remapped_adc;
//unsigned int adcvalue, loval, hival;
//void InitPWM()
//{
//  TCNT0 = 0;
//  OCR0A = 0;
//  TCCR0A = 0b10000001;
//  TIMSK0 |= 0b10;
//}
//void startPWM()
//{
//  TCCR0B = 0b00000100;
//}
//ISR(TIMER0_COMPA_vect)
//{
//// Provide your code for the ISR
//
//  remapped_adc = adcvalue;
//  OCR0A = map(remapped_adc, 690, 865, 0, 255);
//  //Serial.println(adcvalue);
//  //PORTB |= 0b00100000;
//
//}
//ISR(ADC_vect)
//{
//// Provide your code for the ISR
//  loval = ADCL;
//  hival = ADCH;
//  adcvalue = (hival << 8) | loval;
//  Serial.println(adcvalue);
//  
//}
//void setup() {
//// put your setup code here, to run once:
//  PRR &= 0b11111110;
//  ADCSRA = 0b10001111;
//  ADMUX = 0b01000000;
//  DDRD |= PIN6;
//  InitPWM();
//  startPWM();
//  sei();
//  ADCSRA |= 0b01000000;
//  Serial.begin(9600);
//}
//void loop() {}
