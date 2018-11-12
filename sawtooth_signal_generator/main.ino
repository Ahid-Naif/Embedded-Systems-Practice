unsigned char* tccr2a = (unsigned char*) 0xB0;
unsigned char* tccr2b = (unsigned char*) 0xB1;
unsigned char* ocr2b = (unsigned char*) 0xB4;
unsigned char* ddrd = (unsigned char*) 0x2A;

void setup()
{
    // pre-scalar 64 + FAST PWM + top value 0xFF
    *tccr2a = 0b00100011;
    *tccr2b = 0b00000100;
    *ddrd |= (1 << 3); // set pin D03 as output

    unsigned long startTimer = 0;
    unsigned long samplingPeriod = 11;  // unit is ms .. 1/90.91Hz = 11 ms
    float signalPeriod = 3; // signal frquency = 1 / signal period = 1 / 3 = 0.33
    unsigned char topValue = 255;
    unsigned char slope = topValue / signalPeriod;
    float t = 0; // represents time axis/x-axis
    Serial.begin(9600);
    startTimer = millis();
    for(;;)
    {
        if((millis() - startTimer) >= samplingPeriod)
        {
            unsigned char value = slope * t;
            *ocr2b = value;
            Serial.println(value);
            t+= 0.01;

            startTimer = millis();
        }
    }
}

void loop()
{

}