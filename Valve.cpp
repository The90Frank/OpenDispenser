#include "Valve.h"

void Valve::exec(){
  if(valveActive){
    button->exec();
    if(!(button->getButtonON())){
      valveActive = false;
      inibition = false;
    }
  } else {
    if(!inibition){
      button->exec();
      if(button->getButtonON()){
         valveActive = true;
         inibition = true;
      }else{
         valveActive = false;
      }
    }
  }
  digitalWrite(valvePin, valveActive);
}

Valve::Valve(uint32_t inputpin, uint32_t valvepin){
  valvePin = valvepin;
  valveActive = false;
  button = new DoubleStateButton(inputpin);
  pinMode(valvePin, OUTPUT);
  digitalWrite(valvePin, LOW);
}
