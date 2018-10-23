#include "Blinky.h"

void setup()
{
    Blinky led('D', 4, 750, 350);

    while(1)
    {
        led.Refresh();
    }

}

void loop()
{

}