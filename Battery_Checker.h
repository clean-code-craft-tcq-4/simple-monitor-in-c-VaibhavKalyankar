#include<stdio.h>
#include <assert.h>

#define Not_Ok 1
#define Ok 0
#define Min_Temp 0
#define Max_Temp 45
#define Min_Soc 20
#define Max_Soc 80
#define Max_ChargeRate 0.8

int IsbatteryOk(float,float, float); 
int IsbatteryTempCheck(float);
int IsbatterySocCheck(float);
int IsbatteryChargeRateCheck(float);
