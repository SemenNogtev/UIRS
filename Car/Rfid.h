#ifndef RFID_H
#define RFID_H

#include <MFRC522.h>
MFRC522 rfidRC522(9, 10); // SDA, RST

class Rfid
{
public:
    Rfid()
    {
        rfidOn = 0;  // rfid Off
    }

    bool getRfidOn() { return rfidOn; }
    void setRfidOn(bool rfid) { rfidOn = rfid; }

    //void initPinMode()
    //{
    //    pinMode(9, OUTPUT); // pinSDA to output
    //    pinMode(10, OUTPUT); // pinRST to output
    //}

    void initRfid()
    {
        SPI.begin();          // starting the bus
        rfidRC522.PCD_Init(); // initializing the module
    }

    void readRfid()
    {
        if (rfidRC522.PICC_IsNewCardPresent() && rfidRC522.PICC_ReadCardSerial()) // if the label is applied
        {
            uint32_t rfidID = 0; // let's write the label in 4 bytes
            for (uint8_t i = 0; i < 4; i++) {
                rfidID <<= 8;
                rfidID |= rfidRC522.uid.uidByte[i];
            }
            if (rfidID == 3646882533) // if the tag ID matches
            {
                rfidOn = 1;
            }
        }
    }

private:
    bool rfidOn; // on/off
};

#endif //



