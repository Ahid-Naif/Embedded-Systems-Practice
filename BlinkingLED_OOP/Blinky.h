#ifndef Blinky_h
#define Blinky_h

#include <Arduino.h>

class Blinky
{
public:
  Blinky(char, int, unsigned long, unsigned long); // constructor
  void Refresh(); // to keep counting delays & blinking the LEDs

private:
  unsigned long _ONWait, _OFFWait; // used when keeping the LED ON
  unsigned long _ONTime, _OFFTime; // used when keeping the LED OFF
  char _portName;
  int _pin;
  bool _isON = 0; // is LED ON?
  bool _is1stRun = 1 // true if the LED just started blinking, then, it's set OFF all the time

  void initialize(); // to set the initial values of the registers
  void turnON(); // turn LED ON
  void turnOFF(); // turn LED OFF
};

#endif