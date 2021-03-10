#include "checker_prv.h"

void warningsGenerator(float breachedValue, toleranceRange_st warnType, int tempUnit)
{
  float convTemp = 0.0;
  char warnMessage[MAX_WARNING_TEXT_CHARS];
  if(tempUnit == FAHR)
  {
	  convTemp = CELTOFAHR(breachedValue);
	  printf("Requested temperature in Fahrenhiet %f \n",convTemp);
  }
  ParamToString(warnMessage,warnType);
  printf(" Breached value - %f \t %s \n",breachedValue, warnMessage);
}
