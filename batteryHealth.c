#include "checker_prv.h"
/*
 **********************************************************************************************************************
 * Service name         : batteryHealth
 * Syntax               : int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
 * param[in]            : temperature
 * param[in]            : soc
 * param[in]            : chargeRate
 * param[in]            : sector
 * param[in]            : temperatureUnit
 * return               : 0, 1
 * Description          : Program to verify battery health based on temperature, state of charge and charge rate
 **********************************************************************************************************************
 */
int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector, int temperatureUnit)
{
  return ((temperatureSectorStatus(temperature,sector,temperatureUnit))
	  && (statusOfCharge(soc)) && (rateOfCharge(chargeRate)));
}
	
