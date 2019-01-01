void setup()
{
    DDRB = 0b00001111; // set PINs from 0 to 3 as OUTPUT
    char steps[] = {1, 2, 4, 8};
    char position = 0;
    unsigned long delayTime = 5; // unit is ms

    unsigned long checkPoint = millis();
    while(true)
    {
        if( (millis() - checkPoint) >= delayTime)
        {
            PORTB = steps[position];
            position++;
            if(position >= 4)
            {
                position = 0;
            }
            // position--;
            // if(position <= 0)
            // {
            //     position = 3;
            // }
            checkPoint = millis();
        }
    }
}

void loop()
{

}