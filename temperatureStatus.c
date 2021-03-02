#include "checker_prv.h"

int temperatureStatus(float temperature,enum MajorSector sectorType, float cmprTemperature) 
{
	int retStatus;
	/* Check if the temperature is out of range */
	if(temperature > cmprTemperature)
	{
		retStatus = 0;
    printf("Selected temperature has breached the max range!\n");
	}
	else
	{
		retStatus = 1;
    printf("Selected temperature is within the range!\n");
	}
	return retStatus;
}
