//Header File for Stepper Class
//by Andri Andermatt, 13.07.2025

#include <Arduino.h>
#include "BasicStepperDriver.h"

class Screw
{
    public:
    Screw(int dir, int step, int initPortionSize = 5, int initRpm = 20, int initMicroSteps = 4, int motorSteps = 200)
    :stepper{motorSteps, dir, step}, portionSize{initPortionSize}, rpm{initRpm}, microSteps{initMicroSteps}
    {
    }
    //Initializes a Stepper with the given Arguments 

    void begin()
    { stepper.begin(rpm, microSteps); }
    // calls .begin()

    void dispensePortion(int numPortions = 1)
    { stepper.move(200 * numPortions * portionSize); }
    //Rotates the Screw so Much, that the specified Number of Portions are dispensed

    bool isStopped()
    { 
        bool flag;
        if (stepper.getCurrentState() == 0) flag = true; 
        else flag = false; 
    
        return flag;        
    }
    //True if the Screw is Stopped

    private:
    BasicStepperDriver stepper;
    int portionSize;
    //Number of Screw Rotations for one Portion
    int rpm;
    int microSteps;
};