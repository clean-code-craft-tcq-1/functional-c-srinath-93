#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

extern accumalateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : temperatureStatus
 * Syntax               : int temperatureStatus(float temperature, float cmprTemperature, int temperatureUnit) 
 * param[in]            : cmprTemperature
 * param[in]            : sectorType
 * param[in]            : tempUnit
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to check if requested temperature is out of range
 **********************************************************************************************************************
 */
int temperatureStatus(float temperature, float cmprTemperature, int tempUnit) 
{
	int retStatus = 1;
	toleranceRange_st tempRange;
	/* Check if the temperature is out of range */
	if((temperature>(float)TEMP_MIN) && (temperature > cmprTemperature))
	{
		retStatus = 0;
                printf("temperature %f has breached the expected range(%d - %f)celcius!\n",temperature,TEMP_MIN,cmprTemperature);
		tempRange.minTolerance = (float)TEMP_MIN;
		tempRange.maxTolerance = cmprTemperature;
		tempRange.paramType = TEMPERATURE;
		tempRange.inputParam = temperature;
		tempRange.tempUnitConv = tempUnit;
		tempRange = checkTolerance(tempRange);
		dataRange.tempInputParam = tempRange.inputParam;
		dataRange.tempMinBreach = tempRange.minTolerance;
		dataRange.tempMaxBreach = tempRange.maxTolerance;
		dataAccumalator(tempRange);
	}
	dataRange.retstatus = retStatus;
	return retStatus;
}
