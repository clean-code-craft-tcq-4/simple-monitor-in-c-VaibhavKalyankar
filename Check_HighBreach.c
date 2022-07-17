#include<stdio.h>
#include<Battery_Checker.h>


extern BatteryStatus_tst BatteryStatus_st;

void CheckTempforHighBreach()
{
  BatteryStatus_st.TempStatus = HIGH_TEMP_BREACH;
  printf("\nHigh Temprature Breach\n");
}

void CheckSocforHighBreach()
{
  BatteryStatus_st.SocStatus = HIGH_SOC_BREACH;
  printf("\nHigh Soc Breach\n");
}

void CheckChargeRateforHighBreach()
{
  BatteryStatus_st.ChargeRateStatus = HIGH_ChargeRate_BREACH;
  printf("\nHigh ChargeRate Breach\n");
}
