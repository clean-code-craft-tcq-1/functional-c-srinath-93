#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

extern accumalateRange_st dataRange;
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

void controllerAction()
{
	accumalateRange_st cntrlrAction = dataRange;
	printf("\n\n\nBreached type - %d \n",cntrlrAction.parameterType);
	/* cntrlAction can be used for further action like - email alert, new feauture addition, etc */
}
