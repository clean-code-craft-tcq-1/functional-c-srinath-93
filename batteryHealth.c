#include "checker_prv.h"
/*
 **********************************************************************************************************************
 * Service name         : batteryHealth
 * Syntax               : int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
 * param[in]            : temperature
 * param[in]            : soc
 * param[in]            : chargeRate
 * param[in]            : sector
 * return               : 0, 1
 * Description          : Program to verify battery health based on temperature, state of charge and charge rate
 **********************************************************************************************************************
 */
int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector)
{
  return ((temperatureSectorStatus(temperature,sector))
	  && (statusOfCharge(soc)) && (rateOfCharge(chargeRate)));
}
	
