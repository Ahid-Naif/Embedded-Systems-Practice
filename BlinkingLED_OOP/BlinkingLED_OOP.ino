#include "Blinky.h"

void setup()
{
    Blinky led1('D', 5, 10, 190);

    while (1)
    {
        led1.Refresh();
    }
}

void loop()
{
}