#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

const char* MinToleranceNames[] = {"Low_Temperature", "Approaching_discharge", "LOW_ROC"};
const char* MaxToleranceNames[] = {"High_Temperature_Charging_Paused", "Approaching_charge_peak", "HIGH_ROC"};
extern accumalateRange_st dataRange;
void checkTolerance(float dataInput,toleranceRange_st range,int tempUnit)
{
  float tempMin = range.minTolerance;
  float tempMax = range.maxTolerance;
  tempMin += CALCTOLERANCE(range.minTolerance);
  tempMax -= CALCTOLERANCE(range.maxTolerance);
  if(dataInput <= tempMin)
  {
	  range.dataMinMax = MIN;
	  dataRange.breachMinType = range.dataMinMax;
	  warningsGenerator(dataInput, range,tempUnit);
  }
  if(dataInput >= tempMax)
  {
	  range.dataMinMax = MAX;
	  dataRange.breachMaxType = range.dataMinMax;
	  warningsGenerator(dataInput, range,tempUnit);
  }
  dataAccumalator(dataInput,range);
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
