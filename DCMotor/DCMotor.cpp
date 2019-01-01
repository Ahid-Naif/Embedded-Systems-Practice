#include "DCMotor.h"
/////////////////// define Constructor //////////
DCMotor::DCMotor(char port, int pin, double frequency) : 
    _portName(port), _pin(pin), _frequency(frequency)
{
    this->initialize();
}
///////////////// define class methods /////////
void DCMotor::initialize()
{
    oscilator.initialize(this->_portName, this->_pin);
}

void DCMotor::Write(double dutyCycle)
{
    this->_period = 1000000 / this->_frequency;
    unsigned long ONTime = this->_period * dutyCycle;
    unsigned long OFFTime = this->_period - ONTime;
    oscilator.changeOnOffTimes(ONTime, OFFTime);
}

void DCMotor::Refresh()
{
    oscilator.Refresh();
}