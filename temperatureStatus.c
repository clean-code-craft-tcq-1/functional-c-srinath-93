#include "checker_prv.h"

int temperatureStatus(float temperature, float cmprTemperature) 
{
	int retStatus = 1;
	/* Check if the temperature is out of range */
	if(temperature > cmprTemperature)
	{
		retStatus = 0;
                printf("Selected temperature has breached the max range!\n");
	}
	return retStatus;
}
