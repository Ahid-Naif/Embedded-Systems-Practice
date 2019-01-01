#ifndef DCMotor_h
#define DCMotor_h
#include "Blinky.h"

class DCMotor
{
    public:
        DCMotor(char port, int pin, double frequency);

        void Write(double dutyCycle);
        void Refresh();
    private:
        Blinky oscilator;
        char _portName;
        int _pin;
        double _frequency;
        unsigned long _period;

        void initialize(); // to set the initial values of the registers
};

#endif