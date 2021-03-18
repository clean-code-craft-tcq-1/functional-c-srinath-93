#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

extern accumalateRange_st dataRange;
/*
 **********************************************************************************************************************
 * Service name         : statusOfCharge
 * Syntax               : int statusOfCharge(float stateofcharge)
 * param[in]            : stateofcharge
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to check if Charge Rate is out of range
 **********************************************************************************************************************
 */
int statusOfCharge(float stateofcharge)
{
  int retStatus = 1;
  toleranceRange_st socRange;
  if(stateofcharge < SOC_MIN || stateofcharge > SOC_MAX)
  {
    printf("State of Charge(%f) is not with the expected range(%f - %f)!\n\n",stateofcharge,SOC_MIN,SOC_MAX);
    retStatus = 0;
    socRange.minTolerance = SOC_MIN;
    socRange.maxTolerance = SOC_MAX;
    socRange.paramType = SOC;
    socRange.inputParam = stateofcharge;
    socRange.tempUnitConv = 0;
    socRange = checkTolerance(socRange);
    dataRange.socInputParam = socRange.inputParam;
    dataRange.socMinBreach = socRange.minTolerance;
    dataRange.socMaxBreach = socRange.maxTolerance;
    dataAccumalator(socRange);
  }
  dataRange.retstatus = retStatus;
 return retStatus;
}
