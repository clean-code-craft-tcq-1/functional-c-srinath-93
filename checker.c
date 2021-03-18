#include <stdio.h>
#include <assert.h>
#include "checker_prv.h"

int main() 
{
  /* Negative test case - BMS issue detected (Temperature, Soc and Charge rate is not in expected range) */
  assert(batteryHealth(25, 70, 0.7,GENERAL,CEL));
  assert(batteryHealth(80, 70, 0.7,HOME,FAHR));
  assert(batteryHealth(190, 70, 0.7,PUBLIC,CEL));
  assert(batteryHealth(140, 70, 0.7,EV,FAHR));
  
  assert(controllerAction());
  
  /* Positive test case - BMS Passed (Temperature, Soc and Charge rate is within expected range) */
  assert(!batteryHealth(25, 85, 0,GENERAL,CEL));
  assert(!batteryHealth(80, 85, 0,HOME,FAHR));
  assert(!batteryHealth(190, 85, 0,PUBLIC,CEL));
  assert(!batteryHealth(140, 85, 0,EV,FAHR));
  
  /* to check function response */
  batteryHealth(25, 70, 0,GENERAL,CEL);     /* Temperature in range */
  batteryHealth(55, 85, 0,HOME,FAHR);        /* soc out of range */
  batteryHealth(55, 70, 0.9,PUBLIC,CEL);    /* charge rate not in range */
  batteryHealth(45, 70, 0,EV,FAHR);          /* everything in range */
  batteryHealth(45, 70, 0,(int)5,CEL);      /* Sector out of range */
}
