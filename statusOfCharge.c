#include "checker_prv.h"

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
  if(stateofcharge < SOC_MIN || stateofcharge > SOC_MAX)
  {
    printf("State of Charge(%f) is not with the expected range(%f - %f)!\n\n",stateofcharge,SOC_MIN,SOC_MAX);
    return 0;
  }
  return 1;
}
