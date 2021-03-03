#include "checker_prv.h"

int temperatureMax[]={TEMP_GENRAL_MAX, TEMP_HOME_MAX, TEMP_PUBLIC_MAX, TEMP_EV_MAX};
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
