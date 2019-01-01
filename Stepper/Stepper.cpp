#include "Stepper.h"
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
Stepper::Stepper(char port, char mode, unsigned long delayTime) : _portName(port), _mode(mode), _delayTime(delayTime)
{
    this->initialize();
}
///////////////// define class methods /////////
void Stepper::initialize()
{
    switch (this->_portName)
    {
    case 'B':
        *ddrb = 0b00001111; // set PINs from 0 to 3 as OUTPUT
        break;
    case 'C':
        *ddrc = 0b00001111; // set PINs from 0 to 3 as OUTPUT
        break;
    case 'D':
        *ddrd = 0b00001111; // set PINs from 0 to 3 as OUTPUT
        break;
    }

    switch (this->_mode)
    {
    case 'W': // wave dive
        this->_steps[0] = 1;
        this->_steps[1] = 2;
        this->_steps[2] = 4;
        this->_steps[3] = 8;
        this->_maxPosition = 4;
        break;
    case 'F': // full step
        this->_steps[0] = 3;
        this->_steps[1] = 6;
        this->_steps[2] = 12;
        this->_steps[3] = 9;
        this->_maxPosition = 4;
        break;
    case 'H': // half step
        this->_steps[0] = 1;
        this->_steps[1] = 3;
        this->_steps[2] = 2;
        this->_steps[3] = 6;
        this->_steps[4] = 4;
        this->_steps[5] = 12;
        this->_steps[6] = 8;
        this->_steps[7] = 9;
        this->_maxPosition = 8;
        break;
    }
}

void Stepper::rotateClockwise()
{
    if (this->_is1stRun)
    {
        this->_checkPoint = millis();
        this->_is1stRun = false;
    }
    if ((millis() - this->_checkPoint) >= this->_delayTime)
    {
        this->runMotor();
        this->_position++;
        if (this->_position >= this->_maxPosition)
        {
            this->_position = 0;
        }
        this->_checkPoint = millis();
    }
}

void Stepper::rotateCounterClockwise()
{
    if (this->_is1stRun)
    {
        this->_checkPoint = millis();
        this->_is1stRun = false;
    }
    if ((millis() - this->_checkPoint) >= this->_delayTime)
    {
        this->_position--;
        if(this->_position < 0)
        {
            this->_position = this->_maxPosition - 1;
        }
        this->runMotor();
        this->_checkPoint = millis();
    }
}

void Stepper::runMotor()
{
    switch (this->_portName)
    {
    case 'B':
        *portb = this->_steps[this->_position]; // set PINs from 0 to 3 as OUTPUT
        break;
    case 'C':
        *portc = this->_steps[this->_position]; // set PINs from 0 to 3 as OUTPUT
        break;
    case 'D':
        *portd = this->_steps[this->_position]; // set PINs from 0 to 3 as OUTPUT
        break;
    }
}

void Stepper::stopRotating()
{
    PORTB = 0;
    this->_is1stRun = true;
    this->_position = 0;
}

char Stepper::getPos()
{
    return this->_position;
}