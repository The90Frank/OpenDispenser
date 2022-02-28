#ifndef __VALVE_H
#define __VALVE_H

#include <Arduino.h>
#include "DoubleStateButton.h"

class Valve
{
private:
    static inline bool inibition{ false };

    DoubleStateButton* button;
    uint32_t valvePin;
    bool valveActive;
    
public:
    Valve(uint32_t inputpin, uint32_t valvepin);
    bool getValveON() { return valveActive; }
    
    void exec();
};

#endif
