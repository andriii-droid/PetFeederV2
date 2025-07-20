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

    void displayLevel(int level) {
        Nextion.writeNum("f0.val", level);
    }
    //Prints the Level onto the Display

    void syncTime(int time);
    //Updates the RTC on the Nextion Display

    int getFeedAmount(mealType meal) {
        return  Nextion.readNumber(pages[meal].amount);
    }
    //Gets the Amount of Feed for a specific meal

    //Necessary??
    void setFeedAmount(mealType meal, int amount);
    //Sets the Amount of Feed for a specific meal

    String getFeedTime(mealType meal) { //TODOS Return in proper Time Format
        return  Nextion.readStr(pages[meal].time);
    }
    //Gets the Amount of Feed for a specific meal

    //Necessary??
    void setFeedTime(mealType meal, int time);
    //Sets the Amount of Feed for a specific meal

    int isActive(mealType meal) {
        return  Nextion.readNumber(pages[meal].active);
    }
    //returns TRUE if Meal is Active

    //Necessary??
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

    Page pages[3] = {   {"page0.fs0.val", "page0.ac0.val", "page0.ut0.val"}, 
                        {"page1.fs1.val", "page1.ac1.val", "page1.ut1.val"},     
                        {"page2.fs2.val", "page2.ac2.val", "page2.ut2.val"}};
    //Ids to accsess the Variables in Display



};