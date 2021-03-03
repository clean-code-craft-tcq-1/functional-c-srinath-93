#include <stdio.h>
#include <assert.h>
#include "checker_prv.h"

int main() 
{
  /* Negative test case - BMS issue detected (Temperature, Soc and Charge rate is not in expected range) */
  assert(batteryHealth(25, 70, 0.7,GENERAL));
  assert(batteryHealth(80, 70, 0.7,HOME));
  assert(batteryHealth(190, 70, 0.7,PUBLIC));
  assert(batteryHealth(140, 70, 0.7,EV));
  
  /* Positive test case - BMS Passed (Temperature, Soc and Charge rate is within expected range) */
  assert(!batteryHealth(25, 85, 0,GENERAL));
  assert(!batteryHealth(80, 85, 0,HOME));
  assert(!batteryHealth(190, 85, 0,PUBLIC));
  assert(!batteryHealth(140, 85, 0,EV));
  
  /* to check function response */
  batteryHealth(25, 85, 0,GENERAL);     /* Temperature in range */
  batteryHealth(55, 70, 0,HOME);        /* soc out of range */
  batteryHealth(55, 85, 0.9,PUBLIC);    /* charge rate not in range */
  batteryHealth(45, 85, 0,EV);          /* everything in range */
  batteryHealth(45, 85, 0,(int)5);      /* Sector out of range */
  
}
