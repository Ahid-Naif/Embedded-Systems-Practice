#include "Button.h"

unsigned int A_count = 0, B_count = 0;
Button A('B', 0, 20, 0, 0);
Button B('B', 1, 20, 0, 1);

    void setup()
{
    Serial.begin(9600);
    A.Pressed = A_gets_pressed;
    B.Pressed = B_gets_pressed;

    while (1)
    {
        A.Refresh();
        B.Refresh();
    }
}

void loop()
{
}

void A_gets_pressed()
{
    A_count++;
    print();
}

void B_gets_pressed()
{
    B_count++;
    print();
}

void print()
{
    Serial.print("A = ");
    Serial.print(A_count);
    Serial.print(" B = ");
    Serial.println(B_count);
}