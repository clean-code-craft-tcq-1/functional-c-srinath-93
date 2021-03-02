#include "checker_prv.h"

int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
{
  if(((temperature>(float)TEMP_MIN)&&(temperatureSectorStatus(temperature,sector)) == 0))
  {
    printf("Provided input is out of range!\n");
    return 0;
  } 
	(void)soc;
	(void)chargeRate;
//  else if(soc < 20 || soc > 80) 
//  {
//    printf("State of Charge out of range!\n");
//    return 0;
//  } 
//  else if(chargeRate > 0.8) 
//  {
//    printf("Charge Rate out of range!\n");
//    return 0;
//  }
  return 1;
}
	
