#include "Blinky.h"

void setup()
{
    Blinky led1('D', 3, 1000, 300);
    Blinky led2('D', 2, 700, 400);

    while (1)
    {
        led1.Refresh();
        led2.Refresh();
    }
}

void loop()
{
}