#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

const char* MinToleranceNames[] = {"Low_Temperature", "Approaching_discharge", "LOW_ROC"};
const char* MaxToleranceNames[] = {"High_Temperature_Charging_Paused", "Approaching_charge_peak", "HIGH_ROC"};
extern accumalateRange_st dataRange;
toleranceRange_st checkTolerance(float dataInput,toleranceRange_st range,int tempUnit)
{
  float rangeMin = range.minTolerance;
  float rangeMax = range.maxTolerance;
  range.minTolerance += CALCTOLERANCE(range.minTolerance);
  range.maxTolerance -= CALCTOLERANCE(range.maxTolerance);
  if(dataInput <= range.minTolerance)
  {
	  range.dataMinMax = MIN;
	  dataRange.breachMinType = range.dataMinMax;
	  warningsGenerator(dataInput, range,tempUnit);
  }
  if(dataInput >= range.maxTolerance)
  {
	  range.dataMinMax = MAX;
	  dataRange.breachMaxType = range.dataMinMax;
	  warningsGenerator(dataInput, range,tempUnit);
  }
  return range;
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
