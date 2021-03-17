#ifndef ACCUMALATE_REPORT_PRV_H_
#define ACCUMALATE_REPORT_PRV_H_

#include <stdio.h>
#include <assert.h>

/* Structure */
typedef struct
{
  int parameterType;
  float tempInputParam;
	float tempMinBreach;
	float tempMaxBreach;
  float socInputParam;
	float socMinBreach;
	float socMaxBreach;
  float rocInputParam;
	float rocMinBreach;
	float rocMaxBreach;
	int breachMinRange; /* can be maintained as 1 byte integer in future update */
  int breachMaxRange; /* can be maintained as 1 byte integer in future update */
}accumalateRange_st;

#endif /* ACCUMALATE_REPORT_PRV_H_ */
