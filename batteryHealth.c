#include "checker_prv.h"

int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
{
  if(((temperature>(float)TEMP_MIN)&&(temperatureSectorStatus(temperature,sector)) == 0))
  {
    printf("Provided input is out of range!\n");
    return 0;
  } 
  return ((temperature>(float)TEMP_MIN) 
	  && (temperatureSectorStatus(temperature,sector))
	  && (statusOfCharge(soc)) && (rateOfCharge(chargeRate)));
}
	
