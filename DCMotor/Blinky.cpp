#include "Blinky.h"
//////////////// define registers //////////////
unsigned char *pinb = (unsigned char *)0x23;
unsigned char *ddrb = (unsigned char *)0x24;
unsigned char *portb = (unsigned char *)0x25;
unsigned char *pinc = (unsigned char *)0x26;
unsigned char *ddrc = (unsigned char *)0x27;
unsigned char *portc = (unsigned char *)0x28;
unsigned char *pind = (unsigned char *)0x29;
unsigned char *ddrd = (unsigned char *)0x2A;
unsigned char *portd = (unsigned char *)0x2B;
/////////////////// define Constructor //////////
Blinky::Blinky()
{
    ;
}
///////////////// define class methods /////////
void Blinky::Refresh()
{
    if (this->_isON) // if LED is ON
    {
        if ((micros() - this->_ONWait) >= this->_ONTime)
        {
            this->turnOFF();
            this->_isON = 0;
            this->_OFFWait = micros();
        }
    }
    else // else if LED is OFF
    {
        if(this->_is1stRun)
        {
            this->_OFFWait = micros();
            this->_is1stRun = false;
        }
        if ((micros() - this->_OFFWait) >= this->_OFFTime)
        {
            this->turnON(); // turn pin ON
            this->_isON = 1;
            this->_ONWait = micros();
        }
    }
}

void Blinky::initialize(char portName, char pin)
{
    this->_portName = portName;
    this->_pin = pin;
    switch (this->_portName)
    {
    case 'B':
        *ddrb |= (1 << this->_pin); // determine direction of the pin as OUTPUT
        break;
    case 'C':
        *ddrc |= (1 << this->_pin); // determine direction of the pin as OUTPUT
        break;
    case 'D':
        *ddrd |= (1 << this->_pin); // determine direction of the pin as OUTPUT
        break;
    }
}

void Blinky::turnON()
{
    switch (this->_portName)
    {
    case 'B':
        *portb |= (1 << this->_pin);
        break;
    case 'C':
        *portc |= (1 << this->_pin);
        break;
    case 'D':
        *portd |= (1 << this->_pin);
        break;
    }
}

void Blinky::turnOFF()
{
    switch (this->_portName)
    {
    case 'B':
        *portb &= ~(1 << this->_pin);
        break;
    case 'C':
        *portc &= ~(1 << this->_pin);
        break;
    case 'D':
        *portd &= ~(1 << this->_pin);
        break;
    }
}

void Blinky::changeOnOffTimes(unsigned long newONTime, unsigned long newOFFTime)
{
    this->_ONTime = newONTime;
    this->_OFFTime = newOFFTime;
}