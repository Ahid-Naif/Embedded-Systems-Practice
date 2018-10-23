#include "Blinky.h"

unsigned char *pinb  = (unsigned char*) 0x23;
unsigned char *ddrb  = (unsigned char*) 0x24;
unsigned char *portb = (unsigned char*) 0x25;
unsigned char *pinc  = (unsigned char*) 0x26;
unsigned char *ddrc  = (unsigned char*) 0x27;
unsigned char *portc = (unsigned char*) 0x28;
unsigned char *pind  = (unsigned char*) 0x29;
unsigned char *ddrd  = (unsigned char*) 0x2A;
unsigned char *portd = (unsigned char*) 0x2B;

Blinky::Blinky(char port, int pin, unsigned long ONTime, unsigned long OFFTime)
{
    this->portName = portName;
    this->pin = pin;
    this->ONTime = ONTime;
    this->OFFTime = OFFTime;

    this->mapPorts();
    this->initializePorts();
}

void Blinky::Refresh()
{
    if (this->isFirstTimeRun)
    {
        **port |= (1 << this->pin); // turn pin ON
        ONWait = millis();
        OFFWait = millis();
        this->isFirstTimeRun = 0;
    }

    if ((**port & (1 << this->pin))) // if LED is ON
    {
        if ((millis() - ONWait) >= this->ONTime)
        {
            **port &= ~(1 << this->pin); // turn pin OFF
            OFFWait = millis();
        }
    }
    else // else if LED is OFF
    {
        if ((millis() - OFFWait) >= this->OFFTime)
        {
            **port |= (1 << this->pin); // turn pin ON
            ONWait = millis();
        }
    }
}

void Blinky::mapPorts()
{
    switch (this->portName)
    {
    case 'B':
        ddr = (unsigned char **)&ddrb;
        port = (unsigned char **)&portb;
        break;
    case 'C':
        ddr = (unsigned char **)&ddrc;
        port = (unsigned char **)&portc;
        break;
    case 'D':
        ddr = (unsigned char **)&ddrd;
        port = (unsigned char **)&portd;
        break;
    }
}

void Blinky::initializePorts()
{
    **ddr |= (1 << this->pin); // determine directions as OUTPUT
}