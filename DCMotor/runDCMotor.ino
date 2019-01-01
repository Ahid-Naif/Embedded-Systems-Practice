#include "DCMotor.h"

void setup()
{
    DCMotor motor1('D', 5, 50);
    motor1.Write(0.1);

    while(1)
    {
        motor1.Refresh();
    }

}

void loop()
{

}