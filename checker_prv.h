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
#define SOC_MIN 20
#define SOC_MAX 80
#define RATEOFCHARGE (float)0.8

/* Enums */
enum MajorSector {GENERAL, HOME, PUBLIC, EV};


/* Declaration */
int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector);
int temperatureSectorStatus(float temperature,enum MajorSector sectorType);
int temperatureStatus(float temperature, float cmprTemperature) ;

#endif /* CHECKER_PRV_H_ */
