#include "checker_prv.h"

int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
{
  return ((temperatureSectorStatus(temperature,sector))
	  && (statusOfCharge(soc)) && (rateOfCharge(chargeRate)));
}
	
