#include "checker_prv.h"

const char* MinToleranceNames[] = {"Low_Temperature", "Approaching_discharge", " "};
const char* MaxToleranceNames[] = {"High_Temperature_Charging_Paused", "Approaching_charge_peak", " "};

void checkTolerance(float dataInput,toleranceRange_st range)
{
  float tempMin, tempMax;
  tempMin += (float)CALCTOLERANCE(range.minTolerance);
  tempMax -= (float)CALCTOLERANCE(range.maxTolerance);
  if(dataInput <= tempMin)
  {
	  range.dataMinMax = MIN;
	  warningsGenerator(dataInput, range);
  }
  if(dataInput >= tempMax)
  {
	  range.dataMinMax = MAX;
	  warningsGenerator(dataInput, range);
  }
}

void warningsGenerator(float breachedValue, toleranceRange_st warnType)
{
	char warnMessage[MAX_WARNING_TEXT_CHARS];
	ParamToString(warnMessage,warnType);
	printf(" Breached value - %f \t %s \n",breachedValue, warnMessage);
}

void ParamToString(char* buffer, toleranceRange_st inputDetails)
{
  switch(inputDetails.dataMinMax)
  {
    case MIN:
      {
        sprintf(buffer, "%s ",
        MinToleranceNames[inputDetails.paramType]);
      }
      break;
    case MAX:
      {
        sprintf(buffer, "%s ",
        MaxToleranceNames[inputDetails.paramType]);
      }
      break;
    default:/* do nothing */
      break;
  }
}
