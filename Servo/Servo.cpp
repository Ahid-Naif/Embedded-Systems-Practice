#include "Servo.h"
/////////////////// define Constructor //////////
Servo::Servo(char port, int pin, unsigned long period) : 
    _portName(port), _pin(pin), _period(period)
{
    this->initialize();
}
///////////////// define class methods /////////
void Servo::initialize()
{
    oscilator.initialize(this->_portName, this->_pin);
}

void Servo::Write(unsigned long ONTime)
{
    unsigned long OFFTime = this->_period - ONTime;
    oscilator.changeOnOffTimes(ONTime, OFFTime);
}

void Servo::Refresh()
{
    oscilator.Refresh();
}