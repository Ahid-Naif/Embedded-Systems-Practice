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
    unsigned long samplingPeriod = 11;  // unit is ms .. 1/90.91Hz = 11 ms
    float frequency = 0.2; // signal frquency = 1 / signal period = 1 / 5 = 0.2
    float t = 0; // represents angles axis/x-axis
    Serial.begin(9600);
    startTimer = millis();
    for(;;)
    {
        if((millis() - startTimer) >= samplingPeriod)
        {
            // shift sin fuction 1 unit up to have only positive output
            // multiply by 125 so top value becomes 255
            float value = 125 * (sin(2*PI * frequency * t) + 1); 

            *ocr1al = value;
            Serial.println(value);
            t+= 0.01; // increment the angle

            startTimer = millis();
        }
    }
}

void loop()
{

}