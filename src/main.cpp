#include <Arduino.h>
#include <Screw.h>

Screw testScrew{4, 5};

void setup() 
{
}
 

void loop() 
{

  testScrew.dispensePortion();

  delay(5000);
  // int tag = 0;

  // switch (tag)
  // {
  // case 0:
  //   testScrew.dispensePortion();

  //   if (testScrew.isStopped()) tag = 1;
  //   break;
  
  // case 1:
  //   delay(5000);
  //   tag = 0;
  //   break;
  // }
}