#include "checker_prv.h"

int temperatureSectorStatus(float temperature,enum MajorSector sectorType) 
{
	int retStatus = 1;
	/* choose respective sector */
	switch(sectorType)
	{
		case GENERAL:
		retStatus = temperatureStatus(temperature, (float)TEMP_GENRAL_MAX);
		break;
		case HOME:
		retStatus = temperatureStatus(temperature, (float)TEMP_HOME_MAX);
		break;
		case PUBLIC:
		retStatus = temperatureStatus(temperature, (float)TEMP_PUBLIC_MAX);
		break;	
		case EV:
		retStatus = temperatureStatus(temperature, (float)TEMP_EV_MAX);
		break;
                default:
                {
		printf("Please choose a proper sector!\n");
		retStatus = 0;
	        }
	        break;
	}/* End of switch */
	return retStatus;
}
