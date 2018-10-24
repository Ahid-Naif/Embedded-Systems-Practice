void setup()
{
    unsigned char *pinb = (unsigned char*) 0x23;
    unsigned char *ddrb = (unsigned char*) 0x24;
    unsigned char *portb = (unsigned char*) 0x25;
    
    *ddrb |= (1 << 5);
    *ddrb &= ~(1 << 0); // pin 8 to read button input
    *portb &= ~(1 << 0);

    Serial.begin(115200);

    int counter = 0;
    bool previousState = 0, currentState = 0, isWaiting = 0;
    unsigned long start = 0;

    for(;;)
    {   
        if(isWaiting)
        {   
            if( (millis() - start) >= 20)
            {
                if(*pinb & (1 << 0))
                {
                    counter++;
                    Serial.println(counter);
                }
                isWaiting = 0;
                previousState = currentState;
            }
        }
        else
        {
            currentState = *pinb & (1 << 0);
            if(currentState && !previousState)
            {
                start = millis();
                isWaiting = 1;
            }
            previousState = currentState;
        }
        
    }
}

void loop()
{

}