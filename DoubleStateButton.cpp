#include "DoubleStateButton.h"

void DoubleStateButton::exec(){
  byte state = digitalRead(inputPin);
  if(state != lastState){
    if(state == HIGH){
      buttonPress = !buttonPress;
    }
  }
  lastState = state;
}

DoubleStateButton::DoubleStateButton(uint32_t pin){
  inputPin = pin;
  buttonPress = false;
  lastState = 0;
  
  pinMode(inputPin, INPUT);
}
