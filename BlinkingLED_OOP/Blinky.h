#ifndef Blinky_h
#define Blinky_h

#include <Arduino.h>

class Blinky
{
public:

  Blinky(char, int, unsigned long, unsigned long);
  void Refresh();

private:
  unsigned long _ONWait, _OFFWait, _ONTime, _OFFTime;
  char _portName;
  int _pin;
  bool _isON = 0;

  void initializePorts();
  void turnON();
  void turnOFF();
};

#endif