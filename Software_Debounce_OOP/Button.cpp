#include "Button.h"
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
Button::Button(char port, int pin, unsigned long debouncePeriod, bool isButtonHigh, bool isPullUp) : 
    _portName(port), _pin(pin), _debouncePeriod(debouncePeriod), _isButtonHigh(isButtonHigh), _isPullUp(isPullUp)
{
    this->initialize();
}
///////////////// define class methods /////////
void Button::initialize()
{
    // if one of _isButtonHigh & _isPullUp is HIGH, logic is going to be inverted, otherwise, it stays the same
    this->_previousState = this->_isButtonHigh ^ this->_isPullUp;

    switch (this->_portName)
    {
    case 'B':
        *ddrb &= ~(1 << this->_pin);                                                    // determine direction of the pin as INPUT
        (this->_isPullUp) ? *portb |= (1 << this->_pin) : *portb &= ~(1 << this->_pin); // set Pull Up if it's used
        break;
    case 'C':
        *ddrc &= ~(1 << this->_pin);                                                    // determine direction of the pin as INPUT
        (this->_isPullUp) ? *portc |= (1 << this->_pin) : *portc &= ~(1 << this->_pin); // set Pull Up if it's used
        break;
    case 'D':
        *ddrd &= ~(1 << this->_pin);                                                    // determine direction of the pin as INPUT
        (this->_isPullUp) ? *portd |= (1 << this->_pin) : *portd &= ~(1 << this->_pin); // set Pull Up if it's used
        break;
    }
}

void Button::Refresh()
{
    if (this->_isWaiting)
    {
        if ((millis() - this->_startTimer) >= this->_debouncePeriod)
        {
            this->updateStatus();
            if (this->_currentState)
            {
                this->Pressed();
            }
            this->_isWaiting = 0;
            this->_previousState = this->_currentState;
        }
    }
    else
    {
        this->updateStatus();
        if (this->_currentState && !this->_previousState) // if change of state occurs
        {
            this->_startTimer = millis();
            this->_isWaiting = 1;
        }
        this->_previousState = this->_currentState;
    }
}

void Button::updateStatus()
{
    switch (this->_portName)
    {
    case 'B':
        this->_currentState = (*pinb & (1 << this->_pin)); // read the current state of button
        break;
    case 'C':
        this->_currentState = (*pinc & (1 << this->_pin)); // read the current state of button
        break;
    case 'D':
        this->_currentState = (*pind & (1 << this->_pin)); // read the current state of button
        break;
    }
}