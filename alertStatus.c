#include "checker_prv.h"
#include "accumalate_Report_Prv.h"

unsigned int accumateReportCnt;
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

unsigned int controllerAction()
{
//	unsigned int retStatus = 1;
	accumalateRange_st cntrlrAction = dataRange;
	printf("\n\n\nBreached type - %d \n",cntrlrAction.parameterType);
	/* cntrlAction can be used for further action like - email alert, new feauture addition, etc */
	if(dataRange.retstatus < 1)
	{
		accumateReportCnt++; /* increments when some breach has occured */
//		retStatus = 0;
	}
	return accumateReportCnt;
}
