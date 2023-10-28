#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

class Magnetometer
{
public:
    Magnetometer() 
    { 
        course = 0;
    }

    double getDegreeCourse() { return course * (180 / 3.14); }
    double getRadCourse() { return course; }

    double setDegreeCourse(double degreeCourse) { course = degreeCourse * (3.14 / 180); }
    double setRadCourse(double radCourse) { course = radCourse; }

    //void initPinMode()
    //{ 
    //    pinMode(18, OUTPUT); // pinSDA to output
    //    pinMode(19, OUTPUT); // pinSCL to output
    //}

private:
    double course; // rad
};

#endif //

