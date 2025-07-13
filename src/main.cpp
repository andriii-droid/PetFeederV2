#include <Arduino.h>
#include <Screw.h>
#include <Display.h>


Screw feedSrew{4, 5, 3, 1};

void setup() 
{
    Serial.begin(115200);
    feedSrew.begin();
}
 
void loop() 
{

}