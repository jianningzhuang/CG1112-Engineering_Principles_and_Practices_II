#define PIN4 (1 << 4)
#define PIN5 (1 << 5)
#define PIN6 (1 << 6)
#define PIN7 (1 << 7)
#define PIN10 (1 << 2)
#define PIN11 (1 << 3)
#define PIN12 (1 << 4)
#define PIN13 (1 << 5)

void setup() {
  DDRB = (PIN10 | PIN11 | PIN12 | PIN13);
  DDRD = (~PIN4 & ~PIN5 & ~PIN6 & ~PIN7);
  Serial.begin(9600);

}

void loop() {
  PIND &= 0xF0;
  
  if (PIND == 11110000){
    PORTB |= PIN10;
    delay(100);
    PORTB &= ~PIN10;
    PORTB |= PIN11;
    delay(100);
    PORTB &= ~PIN11;
    PORTB |= PIN12;
    delay(100);
    PORTB &= ~PIN12;
    PORTB |= PIN13;
    delay(100);
    PORTB &= ~PIN13;
  }
  else if (PIND == 00000000){
    PORTB |= PIN10;
    delay(100);
    PORTB &= ~PIN10;
    PORTB |= PIN11;
    delay(100);
    PORTB &= ~PIN11;
    PORTB |= PIN12;
    delay(100);
    PORTB &= ~PIN12;
    PORTB |= PIN13;
    delay(100);
    PORTB &= ~PIN13;
  }
  else{
    if (PIND & PIN7){
    PORTB |= PIN10;
  }
  else{
    PORTB &= ~PIN10;
  }
  if (PIND & PIN6){
    PORTB |= PIN11;
  }
  else{
    PORTB &= ~PIN11;
  }
  if (PIND & PIN5){
    PORTB |= PIN12;
  }
  else{
    PORTB &= ~PIN12;
  }
  if (PIND & PIN4){
    PORTB |= PIN13;
  }
  else{
    PORTB &= ~PIN13;
  }
  }

}



#define PIN4 (1 << 4)
#define PIN5 (1 << 5)
#define PIN6 (1 << 6)
#define PIN7 (1 << 7)
#define PIN10 (1 << 2)
#define PIN11 (1 << 3)
#define PIN12 (1 << 4)
#define PIN13 (1 << 5)

void setup() {
  DDRB = (PIN10 | PIN11 | PIN12 | PIN13);
  DDRD = (~PIN4 & ~PIN5 & ~PIN6 & ~PIN7);
  Serial.begin(9600);

}

void loop() {
  Serial.println((PIND & PIN4)&& (PIND & PIN5) && (PIND & PIN6) && (PIND & PIN7));
  if ((PIND & PIN4)&& (PIND & PIN5) && (PIND & PIN6) && (PIND & PIN7)){
    PORTB |= PIN10;
    delay(100);
    PORTB &= ~PIN10;
    PORTB |= PIN11;
    delay(100);
    PORTB &= ~PIN11;
    PORTB |= PIN12;
    delay(100);
    PORTB &= ~PIN12;
    PORTB |= PIN13;
    delay(100);
    PORTB &= ~PIN13;
  }
  else if (!((PIND & PIN4) || (PIND & PIN5) || (PIND & PIN6) || (PIND & PIN7))){
    PORTB |= PIN10;
    delay(100);
    PORTB &= ~PIN10;
    PORTB |= PIN11;
    delay(100);
    PORTB &= ~PIN11;
    PORTB |= PIN12;
    delay(100);
    PORTB &= ~PIN12;
    PORTB |= PIN13;
    delay(100);
    PORTB &= ~PIN13;
  }
  else{
    if (PIND & PIN7){
    PORTB |= PIN10;
  }
  else{
    PORTB &= ~PIN10;
  }
  if (PIND & PIN6){
    PORTB |= PIN11;
  }
  else{
    PORTB &= ~PIN11;
  }
  if (PIND & PIN5){
    PORTB |= PIN12;
  }
  else{
    PORTB &= ~PIN12;
  }
  if (PIND & PIN4){
    PORTB |= PIN13;
  }
  else{
    PORTB &= ~PIN13;
  }
  }

}
