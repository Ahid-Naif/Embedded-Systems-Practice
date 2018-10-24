#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
public:
  Button(char, int, unsigned long, bool, bool); // constructor
  void (*Pressed)(void);
  void Refresh();

private:
  char _portName; // to store port name
  int _pin; // to store pin number
  unsigned long _debouncePeriod, _startTimer = 0;
  bool _isButtonHigh; // is button high by default?
  bool _isPullUp; // is internal Pull up used?
  bool _isWaiting = 0; // this variable is ON when the button pressed, it is used to wait a bit for the debounce
  bool _currentState, _previousState; // to store previous & current states of the button

  void initialize(); // to set the initial values of the registers & previous state (ON/OFF)
  void updateStatus(); // to read the state of the button from the register pin B/C/D
};

#endif