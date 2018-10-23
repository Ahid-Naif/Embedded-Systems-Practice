#ifndef Blinky_h
#define Blinky_h

#include <Arduino.h>

class Blinky
{
  public:
    char portName;
    int pin;
    unsigned long ONTime, OFFTime;

    void Refresh();
    Blinky(char, int, unsigned long, unsigned long);

  private:
    unsigned char **ddr = (unsigned char **)NULL;
    unsigned char **port = (unsigned char **)NULL;
    bool isFirstTimeRun = 1;
    unsigned long ONWait, OFFWait;

    void mapPorts();
    void initializePorts();
};

#endif