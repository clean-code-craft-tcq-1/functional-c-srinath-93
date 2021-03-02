#ifndef CHECKER_PRV_H_
#define CHECKER_PRV_H_

/* Macros */
#define TEMP_MIN (float)0
#define TEMP_GENRAL_MAX (float)45
#define TEMP_HOME_MAX (float)80
#define TEMP_PUBLIC_MAX (float)210
#define TEMP_EV_MAX (float)150

/* Enums */
enum MajorSector {GENERAL, HOME, PUBLIC, EV};


/* Declaration */
int batteryHealth(float temperature, float soc, float chargeRate, enum MajorSector sector);
int temperatureStatus(float temperature,enum MajorSector sectorType);

#endif /* CHECKER_PRV_H_ */
