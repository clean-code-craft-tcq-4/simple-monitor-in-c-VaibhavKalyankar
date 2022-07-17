#include<stdio.h>
#include <assert.h>

#define Not_Ok 1
#define Ok 0
#define Min_Temp 0
#define Max_Temp 45
#define Min_Soc 20
#define Max_Soc 80
#define Min_ChargeRate 0
#define Max_ChargeRate 0.8
#define Tolerence 0.05

typedef enum
{
  CELCIUS,
  FAHRENHEIT
}TempratureUnit_ten

typedef enum
{
  LOW_TEMP_BREACH,
  LOW_TEMP_WARNING,
  TEMP_NORMAL,
  HIGH_TEMP_WARNING,
  HIGH_TEMP_BREACH
}BatteryTemp_Status_ten

typedef enum
{
  LOW_SOC_BREACH,
  LOW_SOC_WARNING,
  SOC_NORMAL,
  HIGH_SOC_WARNING,
  HIGH_SOC_BREACH
}BatterySoc_Status_ten

typedef enum
{
  LOW_ChargeRate_BREACH,
  LOW_ChargeRate_WARNING,
  ChargeRate_NORMAL,
  HIGH_ChargeRate_WARNING,
  HIGH_ChargeRate_BREACH
}BatteryChargeRate_Status_ten

typedef struct
{
  BatteryTemp_Status_ten TempStatus;
  BatterySoc_Status_ten SocStatus;
  BatteryChargeRate_Status_ten ChargeRateStatus;
}BatteryStatus_tst
  

int IsbatteryOk(float,float, float,TempratureUnit_ten); 
int IsbatteryTempCheck(float);
int IsbatterySocCheck(float);
int IsbatteryChargeRateCheck(float);
void CheckTempforLowBreach();
void CheckSocforLowBreach();
void CheckChargeRateforLowBreach();
void CheckTempforHighBreach();
void CheckSocforHighBreach();
void CheckChargeRateforHighBreach();


