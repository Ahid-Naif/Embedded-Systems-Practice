#ifndef Stepper_h
#define Stepper_h

class Stepper
{
    public:
        Stepper(char, char, unsigned long);

        void rotateClockwise();
        void rotateCounterClockwise();
        void stopRotating();

        char getPos();
    private:
        char _portName;
        char _mode;
        unsigned long _delayTime;
        unsigned long _checkPoint;
        char _steps[8]; // to store all steps patterns the Stepper motor is going to follow
        char _position = 0; // to store the index that represents the currrent position of the steps
        char _maxPosition;

        bool _is1stRun = 1; // true if the LED just started blinking, then, it's set OFF all the time

        void initialize(); // to set the initial values of the registers
        void runMotor();
};

#endif