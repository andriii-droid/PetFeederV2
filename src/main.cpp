#include <Arduino.h>
#include <Screw.h>
#include <Display.h>


Screw feedSrew{4, 5, 3, 1};
Display Nex;

void setup() 
{
    Serial.begin(115200);
    feedSrew.begin();
    Nex.begin();
}
 
void loop() 
{

}
