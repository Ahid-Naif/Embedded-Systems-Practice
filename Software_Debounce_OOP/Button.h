#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
public:
  Button(char, int, unsigned long, bool, bool);
  void (*Pressed)(void);
  void Refresh();

private:
  char _portName;
  int _pin;
  unsigned long _debouncePeriod, _startTimer = 0;
  bool _isButtonHigh, _isPullUp, _isWaiting = 0, _currentState = 0, _previousState = 0;

  void initializePorts();
  void updateStatus();
};

#endif