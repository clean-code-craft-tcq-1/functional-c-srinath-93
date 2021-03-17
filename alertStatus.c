#include "checker_prv.h"

void warningsGenerator(toleranceRange_st warnType)
{
  float convTemp = 0.0;
  char warnMessage[MAX_WARNING_TEXT_CHARS];
  if(warnType.tempUnitConv == FAHR)
  {
	  convTemp = CELTOFAHR(warnType.inputParam);
	  printf("Requested temperature in Fahrenhiet %f \n",convTemp);
  }
  ParamToString(warnMessage,warnType);
  printf(" Breached value - %f \t %s \n",warnType.inputParam, warnMessage);
}
