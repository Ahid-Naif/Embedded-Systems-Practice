unsigned char* tccr1a = (unsigned char*) 0x80;
unsigned char* tccr1b = (unsigned char*) 0x81;
unsigned char* ocr1ah = (unsigned char*) 0x88;
unsigned char* ocr1al = (unsigned char*) 0x89;
unsigned char* ddrb = (unsigned char*) 0x24;

void setup()
{
    // pre-scalar 64 + FAST PWM
    *tccr1a = 0b10000011;
    *tccr1b = 0b00011011;
    *ddrb |= (1 << 1); // set pin B01 as output

    unsigned long startTimer = 0;
    // sampling period.. a bit little that 11 ms because other operations are causing delay as well
    unsigned long delayTime = 10.95;  // unit is ms
    int t = 0;
    Serial.begin(9600);

    check = millis();
    for(;;)
    {
        if((millis() - startTimer) >= delayTime)
        {
            float angle_radians = (PI/180)*t;
            float value = sin(angle_radians) + 1; // shift sin fuction 1 unit up to have only positive output

            *ocr1al = value;
            Serial.println(value);
            if(t == 360)
            {
                t = 0;
            }
            else
            {
                t++;
            }

            startTimer = millis();
        }
    }
}

void loop()
{

}