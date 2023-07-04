#define REDPIN    11
#define GREENPIN  12
#define SWITCHPIN 2

#define LED_DELAY   100

// This variable decides which LED's turn it is to flash.
// 0 = green, 1 = red
static volatile int turn = 0;

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(SWITCHPIN, INPUT);
  Serial.begin(9600);
}

void testButton(){
  int buttonState = digitalRead(SWITCHPIN);
  Serial.println(buttonState);
  
  if (buttonState == HIGH){
    turn = 1 - turn;
  }
}

void flashGreen(){
  int counter = 1;

  while(turn==0){
    for(int i=0; i<counter; i++){
      digitalWrite(GREENPIN, HIGH);
      delay(LED_DELAY);
      digitalWrite(GREENPIN, LOW);
      delay(LED_DELAY);
    }
  
    counter++;
    delay(1000);

    testButton();
  }
}

void flashRed(){
  int counter = 1;

  while(turn==1){
    for(int i=0; i<counter; i++){
      digitalWrite(REDPIN, HIGH);
      delay(LED_DELAY);
      digitalWrite(REDPIN, LOW);
      delay(LED_DELAY);
    }

    counter++;
    delay(1000);

    testButton();
    
  }
}
void loop() {

  if(turn == 0)
    flashGreen();

  if(turn == 1)
    flashRed();
}
