#ifndef DCMotor_h
#define DCMotor_h
#include "Blinky.h"

class Servo
{
    public:
        Servo(char port, int pin, unsigned long period);

        void Write(unsigned long ONTime);
        void Refresh();
    private:
        Blinky oscilator;
        unsigned long _period;
        char _portName;
        int _pin;

        void initialize();
};

#endif