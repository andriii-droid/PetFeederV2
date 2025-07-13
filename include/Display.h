//Header File for Display Class
//by Andri Andermatt, 13.07.2025
#include <Arduino.h>
#include "EasyNextionLibrary.h"



class Display
{
    public:
    Display()
    {
    }
    //Ctor

    enum mealType {Morgen, Mittag, Abend};

    void begin()
    {
        Nextion.begin(9600);
    }
    //Calls .begin() Function

    void displayLevel(int level);
    //Prints the Level onto the Display

    void syncTime(int time);
    //Updates the RTC on the Nextion Display

    int getFeedAmount(mealType meal);
    //Gets the Amount of Feed for a specific meal

    void setFeedAmount(mealType meal, int amount);
    //Sets the Amount of Feed for a specific meal

    int getFeedTime(mealType meal);
    //Gets the Amount of Feed for a specific meal

    void setFeedTime(mealType meal, int time);
    //Sets the Amount of Feed for a specific meal

    bool isActive(mealType meal);
    //returns TRUE if Meal is Active

    void setActive(mealType meal, bool active);
    //sets Active for specified meal to specified value

    private:
    EasyNex Nextion{Serial2};

    mealType meal = Morgen;

    struct Page
    {
        String amount;
        String active;
        String time;
    };

    Page pages[3] = {   {"fs0.val", "ut0.txt", "ak0.val"}, 
                        {"fs1.val", "ut1.txt", "ak1.val"},     
                        {"fs2.val", "ut2.txt", "ak2.val"}};
    //Ids to accsess the Variables in Display
    
};