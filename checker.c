#include <stdio.h>
#include <assert.h>
#include "checker_prv.h"

int main() 
{
  /* Negative test case - BMS issue detected */
  assert(batteryHealth(25, 70, 0.7,GENERAL));
  assert(batteryHealth(80, 70, 0.7,HOME));
  assert(batteryHealth(190, 70, 0.7,PUBLIC));
  assert(batteryHealth(140, 70, 0.7,EV));
  
  /* cases to verify all function calls */
//  batteryHealth(45, 85, 0,GENERAL);
//  batteryHealth(100, 85, 0,HOME);
//  batteryHealth(210, 85, 0,PUBLIC);
//  batteryHealth(150, 85, 0,EV);
  
   /* Positive test case - BMS Passed */
  assert(!batteryHealth(25, 85, 0,GENERAL));
  assert(!batteryHealth(80, 85, 0,HOME));
  assert(!batteryHealth(190, 85, 0,PUBLIC));
  assert(!batteryHealth(140, 85, 0,EV));
  
  /* Positive test case - BMS Passed */
//  assert(!batteryHealth(45, 85, 0,GENERAL));
//  assert(!batteryHealth(100, 85, 0,HOME));
//  assert(!batteryHealth(210, 85, 0,PUBLIC));
//  assert(!batteryHealth(150, 85, 0,EV));
}
