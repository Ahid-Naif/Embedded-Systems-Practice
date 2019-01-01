#include "Servo.h"

void setup()
{
    Servo servo1('D', 7, 20000);
    servo1.Write(1000);
    while(1)
    {   
        servo1.Refresh();
    }
}

void loop()
{

}