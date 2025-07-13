//Header File for Level Class
//by Andri Andermatt, 13.07.2025
#include <Arduino.h>

class Strip
{

};

class Sensor
{
    public:
    void begin();

    int getLevel();

    private:
    const int sensPin[11] = {   A2, A3, A4, A5, A6, A7, 
                                A8, A9, A10, A11, A12};
    const int numSens = 11;
    int level = 0;
};

class Level: public Sensor, public Strip
{

};