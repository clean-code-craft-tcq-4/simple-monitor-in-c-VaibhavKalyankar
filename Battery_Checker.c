#include <stdio.h>
#include <assert.h>
#include "Battery_Checker.h"

int IsbatteryTempCheck(float Temprature)
{
  if(Temprature < Min_Temp || Temprature > Max_Temp) 
  {
      printf("Temperature out of range!\n");
      return Not_Ok;
  }
  else
    return Ok;
}

int IsbatterySocCheck(float Soc)
{
  if(soc < Min_Soc || soc > Max_Soc) 
  {
    printf("State of Charge out of range!\n");
    return Not_Ok;
  }
  else
    return Ok;
  
} 

int IsbatteryChargeRateCheck(float ChargeRate)
{
   if(ChargeRate > Max_ChargeRate) 
   {
     printf("Charge Rate out of range!\n");
      return Not_Ok;
   }
  else
     return Ok;
}
int IsbatteryOk(float Temperature, float soc, float chargeRate) 
{
   return IsbatteryTempCheck(Temperature);
   return IsbatterySocCheck(soc);
   return IsbatteryChargeRateCheck(ChargeRate);
 
 }

int main() {
  assert(IsbatteryOk(25, 70, 0.7));
  assert(!IsbatteryOk(50, 85, 0));
}