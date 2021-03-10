#include "checker_prv.h"

const char* MinToleranceNames[] = {"Low_Temperature", "Approaching_discharge", " "};
const char* MaxToleranceNames[] = {"High_Temperature_Charging_Paused", "Approaching_charge_peak", " "};

void checkTolerance(float dataInput,toleranceRange_st range,int tempUnit)
{
  float tempMin = range.minTolerance;
  float tempMax = range.maxTolerance;
  tempMin += CALCTOLERANCE(range.minTolerance);
  tempMax -= CALCTOLERANCE(range.maxTolerance);
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
  if(tempUnit == FAHR)
  {
	  convTemp = CELTOFAHR(temperature);
	  printf("Requested temperature in Fahrenhiet %f \n",convTemp);
  }
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
    default:/* do nothing */ break;
  }
}
