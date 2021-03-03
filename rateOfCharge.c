#include "checker_prv.h"

/*
 **********************************************************************************************************************
 * Service name         : rateOfCharge
 * Syntax               : int rateOfCharge(float chargeRate) 
 * param[in]            : chargeRate
 * return               : 0 - out of range, 1 - in range
 * Description          : Program to check if Charge Rate is out of range
 **********************************************************************************************************************
 */
int rateOfCharge(float chargeRate)
{
  if(chargeRate > 0.8)
  {
    printf("Charge Rate(%f) out of range(%f)!\n",chargeRate,(float)RATEOFCHARGE);
    return 0;
  }
  return 1;
}
