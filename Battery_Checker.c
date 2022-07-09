#include <stdio.h>
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
  if(Soc < Min_Soc || Soc > Max_Soc) 
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
int IsbatteryOk(float Temperature, float Soc, float ChargeRate) 
{
   return IsbatteryTempCheck(Temperature);
   return IsbatterySocCheck(Soc);
   return IsbatteryChargeRateCheck(ChargeRate);
 
 }

int main() {
  assert(IsbatteryOk(60, 15, 0.8));
  assert(!IsbatteryOk(30, 85, 0.9));
}
