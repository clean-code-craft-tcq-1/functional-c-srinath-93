#include "checker_prv.h"

int statusOfCharge(float stateofcharge)
{
  if(soc < 20 || soc > 80)
  {
    printf("State of Charge out of range!\n\n");
    return 0;
  }
  return 1;
}
