#include "checker_prv.h"

void warningsGenerator(float breachedValue, toleranceRange_st warnType)
{
	char warnMessage[MAX_WARNING_TEXT_CHARS];
	ParamToString(warnMessage,warnType);
	printf(" Breached value - %f \t %s \n",breachedValue, warnMessage);
}
