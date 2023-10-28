#ifndef STEPPERC_H
#define STEPPERC_H

#include "GyverStepper2.h" // library for stepper motor
int steps = 2048; // number of steps/revolutions
GStepper2<STEPPER4WIRE> gyverStepper(steps, 5, 7, 6, 8); // object - stepper motor

class Stepperc
{
public:
    Stepperc()
    {
        stepOmega = 480; // angular velocity, step/sec = 14 revolutions/min
        stepDirection = 0; // direction, step
    }

    int getStepOmega() { return stepOmega; }
    double getDegreeOmega() { return stepOmega * (360.0 / steps); }
    double getRadOmega() { return stepOmega * (360.0 / steps) * (3.14 / 180); }

    void setStepOmega(int omega) { stepOmega = omega; }
    void setDegreeOmega(double degreeOmega) { stepOmega = degreeOmega * (steps / 360.0); }
    void setRadOmega(double radOmega) { stepOmega = radOmega * (steps / 360.0) * (180 / 3.14); }

    int getStepDirection() { return stepDirection; }
    double getDegreeDirection() { return stepDirection * (360.0 / steps); }
    double getRadDirection() { return stepDirection * (360.0 / steps) * (3.14 / 180); }

    void setStepDirection(int direction) { stepDirection = direction; }
    void setDegreeDirection(double degreeDirection) { stepDirection = degreeDirection * (steps / 360.0); }
    void setRadDirection(double radDirection) { stepDirection = radDirection * (steps / 360.0) * (180 / 3.14); }

    //void initPinMode()
    //{
    //    pinMode(5, OUTPUT); // pinIN1 to output
    //    pinMode(6, OUTPUT); // pinIN2 to output
    //    pinMode(7, OUTPUT); // pinIN3 to output
    //    pinMode(8, OUTPUT); // pinIN4 to output
    //}

    void initStepper()
    {
        gyverStepper.setTarget(stepDirection); // angle of rotation, step
        gyverStepper.setMaxSpeed(stepOmega);   // angular velocity, step/sec
        gyverStepper.setAcceleration(0);       // angular acceleration = 0, step/sec/sec
        gyverStepper.autoPower(true);          // turn off the motor when it is not rotating
    }

    void turnStep(int direction)
    {
        stepDirection = direction;
        gyverStepper.tick();      // the motor is spinning asynchronously here
        if (gyverStepper.ready()) // if you have arrived
        {
            gyverStepper.setTarget(stepDirection); // angle of rotation
        }
    }

    void turnDegree(double degreeDirection)
    {
        stepDirection = degreeDirection * (steps / 360.0);
        gyverStepper.tick();
        if (gyverStepper.ready())
        {
            gyverStepper.setTarget(stepDirection);
        }
    }

    void turnRad(double radDirection)
    {
        stepDirection = radDirection * (steps / 360.0) * (180 / 3.14);
        gyverStepper.tick();
        if (gyverStepper.ready())
        {
            gyverStepper.setTarget(stepDirection);
        }
    }

private:
    int stepOmega;     // angular velocity, step/sec
    int stepDirection; // direction, step
};

#endif //