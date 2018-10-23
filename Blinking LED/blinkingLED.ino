unsigned char *pinb  = (unsigned char*) 0x23;
unsigned char *ddrb  = (unsigned char*) 0x24;
unsigned char *portb = (unsigned char*) 0x25;
unsigned char *pinc  = (unsigned char*) 0x26;
unsigned char *ddrc  = (unsigned char*) 0x27;
unsigned char *portc = (unsigned char*) 0x28;
unsigned char *pind  = (unsigned char*) 0x29;
unsigned char *ddrd  = (unsigned char*) 0x2A;
unsigned char *portd = (unsigned char*) 0x2B;

void setup()
{   
    int ONTime = 1000, OFFTime = 100; // unit is microseconds
    *ddrd |= (1 << 2); // set pin D02 for output
    unsigned long ONWait = 0, OFFWait = 0;

    *portd |= (1 << 2); // turn pin B01 ON
    ONWait = millis();
    for(;;)
    {   
        if( (*portd & (1 << 2)) ) // if LED is ON
        {
            if((millis() - ONWait) >= ONTime)
            {
                *portd &= ~(1 << 2); // turn pin B01 OFF
                OFFWait = millis();
            }
        }
        else // else if LED is OFF
        {
            if((millis() - OFFWait) >= OFFTime)
            {
                *portd |= (1 << 2); // turn pin B01 ON
                ONWait = millis();
            }
        }
    }
}

void loop()
{

}