#include "checker_prv.h"

int rateOfCharge(float chargeRate)
{
  if(chargeRate > 0.8)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}
