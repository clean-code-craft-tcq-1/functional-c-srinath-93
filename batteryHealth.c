#include "checker_prv.h"

int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
{
  return ((temperature>(float)TEMP_MIN) 
	  && (temperatureSectorStatus(temperature,sector))
	  && (statusOfCharge(soc)) && (rateOfCharge(chargeRate)));
}
	
