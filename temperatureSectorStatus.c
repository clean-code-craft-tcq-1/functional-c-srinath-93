#include "checker_prv.h"

int temperatureMax[]={TEMP_GENRAL_MAX, TEMP_HOME_MAX, TEMP_PUBLIC_MAX, TEMP_EV_MAX};
/*
 **********************************************************************************************************************
 * Service name         : temperatureSectorStatus
 * Syntax               : int temperatureSectorStatus(float temperature,enum MajorSector sectorType) 
 * param[in]            : temperature
 * param[in]            : sectorType
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to check if requested sector is valid and to identify the max sector range
 **********************************************************************************************************************
 */
int temperatureSectorStatus(float temperature,enum MajorSector sectorType) 
{
	int retStatus = 1;
	/* choose respective sector */
	if(sectorType<((int)MAXNUMBEROFSECTORS))
	{
		retStatus = temperatureStatus(temperature, (float)temperatureMax[sectorType]);
	}
	else
	{
		printf("requested sector is invalid\n\n");
		retStatus = 0;
	}
	/* Return the sector and temperature status */
	return retStatus;
}
