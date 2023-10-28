#ifndef RELE_H
#define RELE_H

class Rele
{
public:
    Rele() { pin = 14; } // pin A0

    bool getIsOn() { return isOn; }
    void setIsOn(bool releIsOn) { isOn = releIsOn; }

    void initPinMode() { pinMode(pin, OUTPUT); } // pin to output

    void switchOn(bool releOn) // rele on/off
    {
        isOn = releOn;
        digitalWrite(pin, isOn);
    }     
    
private:
    int pin;   // pin rele

    bool isOn; // on/off
};

#endif //


