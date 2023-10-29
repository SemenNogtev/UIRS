#ifndef CAR_H
#define CAR_H

#include "Rfid.h"
#include "Rele.h"
#include "Driver.h"
#include "Stepperc.h"
#include "Magnetometer.h"

class Car
{
public:
    Car()
    {
        wheelAngleDegreeMax = 10;
        errorDegree = 0;
    }

    double getWheelAngle() { return stepperMotor.getDegreeDirection(); }

    void initCar()
    {
        rfid.initRfid();
        airMotor.initPinMode();
        stepperMotor.initStepper();
    }

    double getCourse() { return magnetometer.getDegreeCourse(); }

    void go (double courseDegree, bool airIsOn, double speedPercent) // courseDegreeZad, rele on/off, speedPercent [-100, 100]
    {
        controlSystem(courseDegree);
        airSystem(airIsOn);
        motorSystem(speedPercent);
    }

    void stop()
    {
        turnWheel(0);   // wheels straight
        airSystem(0);   // airmotors off
        motorSystem(0); // driver motor stop
    }

    void turnWheel(double wheelAngleDegree)
    {
        stepperMotor.turnDegree(wheelAngleDegree);
    }

    void controlSystem(double courseDegreeZad)
    {
        errorDegree = courseDegreeZad - getCourse();
        if (errorDegree >= wheelAngleDegreeMax) turnWheel(wheelAngleDegreeMax);
        else if (errorDegree <= -wheelAngleDegreeMax) turnWheel(-wheelAngleDegreeMax);
        else turnWheel(errorDegree);
    }

    void airSystem(bool airIsOn)
    {
        airMotor.switchOn(airIsOn);
    }

    void motorSystem(double speedPercent)
    {
        driverMotor.motorControl(speedPercent * 2.55); // PWM [-255; 255]
    }

    bool unlocked()
    {
        if (rfid.getRfidOn()) return 1;
        return 0;
    }

private:
    double wheelAngleDegreeMax;
    double errorDegree;

    Rfid rfid;
    Rele airMotor;
    Driver driverMotor;
    Stepperc stepperMotor;
    Magnetometer magnetometer;
};

#endif //

