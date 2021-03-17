#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

accumalateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : dataAccumalator
 * Syntax               : void dataAccumalator(float dataInput,toleranceRange_st range)
 * param[in]            : dataInput
 * param[in]            : range
 * return               : None
 * Description          : Program to check and accumalte the required BMS data 
 **********************************************************************************************************************
 */

void dataAccumalator(float dataInput,toleranceRange_st range)
{
  switch(range.paramType)
  {
      
      if(dataRange.breachMinType == MIN)
      {
        case TEMPERATURE: dataRange.tempInputParam = dataInput; dataRange.tempMinBreach = range.minTolerance; break;
        case SOC:         dataRange.socInputParam = dataInput; dataRange.socMinBreach = range.minTolerance; break;
        case ROC:         dataRange.rocInputParam = dataInput; dataRange.rocMinBreach = range.minTolerance; break;
        default: /* Do nothing */ break;
      }
      else
      {
        case TEMPERATURE: dataRange.tempInputParam = dataInput; dataRange.tempMaxBreach = range.maxTolerance; break;
        case SOC:         dataRange.socInputParam = dataInput; dataRange.socMaxBreach = range.maxTolerance; break;
        case ROC:         dataRange.rocInputParam = dataInput; dataRange.rocMaxBreach = range.maxTolerance; break;
        default: /* Do nothing */ break;
      }
          
  }
}
