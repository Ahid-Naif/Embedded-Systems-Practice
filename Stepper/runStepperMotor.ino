#include "Stepper.h"

void setup()
{
    Stepper stepper1('B', 'F', 5);
    unsigned long counter1 = millis();
    unsigned long counter2 = millis();
    unsigned long counter3 = millis();
    while(true)
    {
        while( (millis() - counter1) < 2000)
        {
            stepper1.rotateCounterClockwise();
        }
        while( (millis() - counter2) < 4000)
        {
            stepper1.stopRotating();
        }
        while( (millis() - counter3) < 6000)
        {
            stepper1.rotateClockwise();
        }
    }
}

void loop()
{

}