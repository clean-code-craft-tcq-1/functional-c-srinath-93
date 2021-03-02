#include "checker_prv.h"

int temperatureStatus(float temperature,enum MajorSector sectorType) 
{
	int retStatus = 1;
	/* choose respective sector */
	switch(sectorType)
	{
		case GENERAL:
		{
			if(temperature < TEMP_MIN || temperature > TEMP_GENRAL_MAX)
			{
				printf("General temperature out of range!\n");
				retStatus = 0;
			}
		}
		break;
		case HOME:
		{
			if(temperature < TEMP_MIN || temperature > TEMP_HOME_MAX)
			{
				printf("Home temperature out of range!\n");
				retStatus = 0;
			}			
		}
		break;
		case PUBLIC:
		{
			if(temperature < TEMP_MIN || temperature > TEMP_PUBLIC_MAX)
			{
				printf("Public temperature out of range!\n");
				retStatus = 0;
			}			
		}
		break;	
		case EV:
		{
			if(temperature < TEMP_MIN || temperature > TEMP_EV_MAX)
			{
				printf("EV temperature out of range!\n");
				retStatus = 0;
			}			
		}
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
