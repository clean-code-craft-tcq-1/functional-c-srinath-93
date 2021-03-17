#ifndef CHECKER_PRV_H_
#define CHECKER_PRV_H_

#include <stdio.h>
#include <assert.h>

/* Macros */
#define TEMP_MIN 0
#define TEMP_GENRAL_MAX 45
#define TEMP_HOME_MAX 80
#define TEMP_PUBLIC_MAX 210
#define TEMP_EV_MAX 150
#define MAXNUMBEROFSECTORS 4
#define SOC_MIN (float)20
#define SOC_MAX (float)80
#define RATEOFCHARGE (float)0.8
#define MIN 0
#define MAX 1
#define MAX_WARNING_TEXT_CHARS 40
#define CALCTOLERANCE(x) (float)(x*(0.05))
#define CEL 0 /* celcius */
#define FAHR 1 /* Fahrenheit */
#define CELTOFAHR(Y) (float)((Y*(9/5))+32)
/* Enums */
enum MajorSector {GENERAL, HOME, PUBLIC, EV};
typedef enum {TEMPERATURE, SOC, ROC}BmsParam;
/* Structure */
typedef struct
{
	float minTolerance;
	float maxTolerance;
	BmsParam paramType;
	int dataMinMax;
}toleranceRange_st;
/* Declaration */
int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector, int temperatureUnit);
int temperatureSectorStatus(float temperature,enum MajorSector sectorType, int temperatureUnit);
int temperatureStatus(float temperature, float cmprTemperature, int tempUnit) ;
int statusOfCharge(float stateofcharge);
int rateOfCharge(float chargeRate);
toleranceRange_st checkTolerance(float dataInput,toleranceRange_st range,int tempUnit);
void warningsGenerator(float breachedValue, toleranceRange_st warnType,int tempUnit);
void ParamToString(char* buffer, toleranceRange_st inputDetails);
void dataAccumalator(float dataInput,toleranceRange_st range);
#endif /* CHECKER_PRV_H_ */
