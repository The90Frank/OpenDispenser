#ifndef __DOUBLESTATEBUTTON_H
#define __DOUBLESTATEBUTTON_H

#include <Arduino.h>

class DoubleStateButton
{
private:
    uint32_t inputPin;
    bool buttonPress;
    byte lastState;
    
public:
    DoubleStateButton(uint32_t pin);
    bool isON() { return buttonPress; }
    
    void exec();
};

#endif
