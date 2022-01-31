#include "DbButton.h"

DbButton btn(0);

unsigned long int lastTime = 0;
int i = 0;

void setup() {
  for(int i = 8; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  int waitTime = map(val, 0, 1023, 70, 1000);
  btn.btnLoop();
  
  if ((millis() - lastTime >= waitTime) && !btn.getState()){
    lastTime = millis();
    //using millis instead of delay for blinking
    if (i == 6){
      i = 0;
    }
    
    PORTB ^= (1 << i); //flipping the state of the pin;
    i++;
  }
}
