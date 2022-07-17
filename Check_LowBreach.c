#include<stdio.h>
#include<Battery_Checker.h

extern BatteryStatus_tst BatteryStatus_st

CheckTempforLowBreach()
{
  BatteryStatus_st.TempStatus = LOW_TEMP_BREACH;
  printf("\nLow Temprature Breach\n");
}

CheckSocforLowBreach()
{
  BatteryStatus_st.SocStatus = LOW_SOC_BREACH;
  printf("\nLow Soc Breach\n");
}

CheckChargeRateforLowBreach()
{
  BatteryStatus_st.ChargeRateStatus = LOW_ChargeRate_BREACH;
  printf("\nLow ChargeRate Breach\n");
}
