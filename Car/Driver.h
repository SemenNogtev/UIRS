#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
public:
    Driver()
    {
        pinIN1 = 2;     // pin D2
        pinIN2 = 4;     // pin D4
        pinEN1 = 3;     // pin D3
        motorSpeed = 0; // PWM = 0
    }

    int getMotorSpeed() { return motorSpeed; }
    void setMotorSpeed(int motorSpeedPWM) { motorSpeed = motorSpeedPWM; }

    //void initPinMode()
    //{
    //    pinMode(pinIN1, OUTPUT); // pinIN1 to output
    //    pinMode(pinIN2, OUTPUT); // pinIN2 to output
    //    pinMode(pinEN1, OUTPUT); // pinEN1 to output
    //}

    void motorControl(int motorSpeedPWM)
    {
        motorSpeed = motorSpeedPWM;
        if (motorSpeed > 0) {                // forward
            analogWrite(pinEN1, motorSpeed);
            digitalWrite(pinIN1, 1);
            digitalWrite(pinIN2, 0);
        }
        else if (motorSpeed < 0) {           // back
            analogWrite(pinEN1, -motorSpeed);
            digitalWrite(pinIN1, 0);
            digitalWrite(pinIN2, 1);
        }
        else {                                // stop
            digitalWrite(pinEN1, 0);
            digitalWrite(pinIN1, 0); // 1
            digitalWrite(pinIN2, 0); // 1
        }
    }

private:
    int pinIN1;
    int pinIN2;
    int pinEN1;

    int motorSpeed; // PWM [-255; 255]
};

#endif //

