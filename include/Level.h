//Header File for Level Class
//by Andri Andermatt, 13.07.2025
#include <Arduino.h>

class Strip
{
    public:
    Strip();

    void begin();

    void allWhite();

    void showPercentile();

    private:
    int numPixels;

};

class Sensor
{
    public:
    int calcLevel();

    private:
    const int sensPin[11] = {   A2, A3, A4, A5, A6, A7, 
                                A8, A9, A10, A11, A12};
    const int numSens = 11;
    int level = 0;
};

class Level: public Sensor, public Strip
{
    Level();

    int getlevel();
};