#define REDPIN    11
#define GREENPIN  12
#define SWITCHPIN 2

#define LED_DELAY   100
#define THRESHOLD   300

// This variable decides which LED's turn it is to flash.
// 0 = green, 1 = red
static volatile int turn = 0;
static unsigned long lastTime = 0;
static unsigned long currTime;

void switchISR(){
  currTime = millis();
  Serial.println(currTime - lastTime);
  if (currTime - lastTime > THRESHOLD){
    lastTime = currTime;
    turn = 1 - turn;
  }
  Serial.println(turn);
}

void setup(){
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCHPIN), switchISR, RISING);
  Serial.begin(9600);
}

void flashGreen(){
  int counter=1;

  while(turn==0){
    for(int i=0; i<counter; i++){
      digitalWrite(GREENPIN, HIGH);
      delay(LED_DELAY);
      digitalWrite(GREENPIN, LOW);
      delay(LED_DELAY);
    }

    counter++;
    delay(1000);
  }
}

void flashRed(){
  int counter=1;

  while(turn==1){
    for(int i=0; i<counter; i++){
      digitalWrite(REDPIN, HIGH);
      delay(LED_DELAY);
      digitalWrite(REDPIN, LOW);
      delay(LED_DELAY);
    }

    counter++;
    delay(1000);
  }
}
void loop() {

  if(turn == 0)
    flashGreen();

  if(turn == 1)
    flashRed();
}


//#define REDPIN    11
//#define GREENPIN  12
//#define SWITCHPIN 2
//
//#define LED_DELAY   100
//
//// This variable decides which LED's turn it is to flash.
//// 0 = green, 1 = red
//static volatile int turn = 0;
//
//void switchISR(){
//  turn = 1 - turn;
//}
//
//void setup(){
//  pinMode(REDPIN, OUTPUT);
//  pinMode(GREENPIN, OUTPUT);
//  attachInterrupt(digitalPinToInterrupt(SWITCHPIN), switchISR, RISING);
//}
//
//void flashGreen(){
//  int counter=1;
//
//  while(turn==0){
//    for(int i=0; i<counter; i++){
//      digitalWrite(GREENPIN, HIGH);
//      delay(LED_DELAY);
//      digitalWrite(GREENPIN, LOW);
//      delay(LED_DELAY);
//    }
//
//    counter++;
//    delay(1000);
//  }
//}
//
//void flashRed(){
//  int counter=1;
//
//  while(turn==1){
//    for(int i=0; i<counter; i++){
//      digitalWrite(REDPIN, HIGH);
//      delay(LED_DELAY);
//      digitalWrite(REDPIN, LOW);
//      delay(LED_DELAY);
//    }
//
//    counter++;
//    delay(1000);
//  }
//}
//void loop() {
//
//  if(turn == 0)
//    flashGreen();
//
//  if(turn == 1)
//    flashRed();
//}
