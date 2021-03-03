#include "checker_prv.h"

int statusOfCharge(float stateofcharge)
{
  if(stateofcharge < 20 || stateofcharge > 80)
  {
    printf("State of Charge out of range!\n\n");
    return 0;
  }
  return 1;
}
