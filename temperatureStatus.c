#include "checker_prv.h"
/*
 **********************************************************************************************************************
 * Service name         : temperatureStatus
 * Syntax               : int temperatureStatus(float temperature, float cmprTemperature) 
 * param[in]            : cmprTemperature
 * param[in]            : sectorType
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to check if requested temperature is out of range
 **********************************************************************************************************************
 */
int temperatureStatus(float temperature, float cmprTemperature) 
{
	int retStatus = 1;
	/* Check if the temperature is out of range */
	if((temperature>(float)TEMP_MIN) && (temperature > cmprTemperature))
	{
		retStatus = 0;
                printf("temperature %f has breached the expected range(%d - %f)celcius!\n",temperature,TEMP_MIN,cmprTemperature);
	}
	return retStatus;
}
