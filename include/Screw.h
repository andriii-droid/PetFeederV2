//Header File for Stepper Class
//by Andri Andermatt, 13.07.2025

#include <Arduino.h>
#include "BasicStepperDriver.h"

class Screw
{
    public:
    Screw(int dir, int step, int rpm = 20, int initPortionSize = 5, int microSteps = 4, int motorSteps = 200)
    :stepper{motorSteps, dir, step}, portionSize{initPortionSize}
    {
        stepper.begin(rpm, microSteps);
    }
    //Initializes a Stepper with the given Arguments and calls .begin()

    void dispensePortion(int numPortions = 1)
    { stepper.rotate(360 * numPortions * portionSize); }
    //Rotates the Screw so Much, that the specified Number of Portions are dispensed

    bool isMoving()
    { 
        bool flag;
        if (stepper.getCurrentState() == 0) flag = true; 
        else flag = false; 
    
        return flag;        
    }
    //True if the Screw is Moving

    private:
    BasicStepperDriver stepper;
    int portionSize;
    //Number of Screw Rotations for one Portion
};