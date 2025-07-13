//Header File for Stepper Class
//by Andri Andermatt, 13.07.2025

#include <Arduino.h>
#include "BasicStepperDriver.h"

class Screw
{
    public:
    Screw(int dir, int step, int enable, int initPortionSize = 5, int initRpm = 20, int initMicroSteps = 4, int motorSteps = 200)
    :stepper{motorSteps, dir, step, enable}, portionSize{initPortionSize}, rpm{initRpm}, microSteps{initMicroSteps}
    {
    }
    //Initializes a Stepper with the given Arguments 

    void begin()
    { 
        stepper.begin(rpm, microSteps); 
        stepper.setEnableActiveState(LOW);
    }
    // calls .begin() and setup for enable

    void dispensePortion(int numPortions = 1)
    { 
        stepper.enable();
        stepper.move(200 * numPortions * portionSize); 
        stepper.disable();
    }
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