#include "Arduino.h"
#include "DbButton.h"

unsigned long int DbButton::_debounceTime = 20; 
// https://forum.arduino.cc/t/static-methods-and-members/269653
// with C++ the implementation and definition must be seperate

DbButton::DbButton(int pin){
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
}

void DbButton::btnLoop(){
  int buttonState = digitalRead(_pin);
  if (millis() - _lastPressTime > DbButton::_debounceTime){
    _lastPressTime = millis();
    if (buttonState == LOW && _lastButtonState == HIGH){
      _toggleState = !_toggleState;
      _lastButtonState = LOW;
    }else if(buttonState == HIGH && _lastButtonState == LOW){
      _lastButtonState = HIGH;
    }
  }
}

int DbButton::getState(){
  return _toggleState;
}

static void DbButton::setDebounceTime(unsigned long int time){
  DbButton::_debounceTime = time;
}
