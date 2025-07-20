//cpp File for Level Class
//by Andri Andermatt, 13.07.2025
#include <Arduino.h>
#include <Level.h>

int Sensor::calcLevel()
{
    int totalReadOut = 0;

    for (size_t i = 0; i < numSens; i++)
    {
        totalReadOut += analogRead(sensPin[i]);
    }
  
    return map(totalReadOut, 30, 10000, 100, 0);
}