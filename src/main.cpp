#include <Arduino.h>
#include <Screw.h>

Screw testScrew{4, 5, 1};

void setup() 
{
    Serial.begin(115200);
    testScrew.begin();
}
 
void loop() 
{
  static int tag = 0;
  static int tagLast = 1;

  switch (tag)
  {
  case 0:
    if (tag != tagLast)
    {
        testScrew.dispensePortion();
        tag = tagLast;
    }
  
    if (testScrew.isStopped()) tag = 1;
    break;
  
  case 1:
    delay(5000);
    tag = 0;
    break;
  }
}