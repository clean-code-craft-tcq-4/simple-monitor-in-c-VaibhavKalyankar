#include <stdio.h>
#include "Battery_Checker.h"

BatteryStatus_tst BatteryStatus_st;

float TempratureUnitConversion(float Temperature,TempratureUnit_ten TempUnit)
{
   float TempinCelcius = Temperature;
  if(TempUnit == FAHRENHEIT)
  {
    TempinCelcius = ((Temperature - 32)*5/9);
  }
  return TempinCelcius;
}
int IsbatteryTempCheck(float Temprature)
{
   int ParamStatus = 0;
  if(Temprature >= Min_Temp && Temprature <= Max_Temp) 
  {
      printf("Temperature out of range!\n");
      if(Temprature < Min_Temp)
      CheckTempforLowBreach();
      else
      CheckTempforHighBreach();
        
      ParamStatus = Not_Ok;
  }
  else
  {
    // CheckforWarning(Temprature);
     ParamStatus = Ok;
  }
}

int IsbatterySocCheck(float Soc)
{
   int ParamStatus = 0;
  if(Soc > Min_Soc && Soc < Max_Soc) 
  {
    printf("State of Charge out of range!\n");
    
     if(Soc < Min_Soc)
     CheckSocforLowBreach();
     else
     CheckSocforHighBreach();
    
     ParamStatus = Not_Ok;
  }
  else
  {
    // CheckforWarning(Soc);
     ParamStatus = Ok;
  }
} 

int IsbatteryChargeRateCheck(float ChargeRate)
{
   int ParamStatus = 0;
   if(ChargeRate >= Min_ChargeRate && ChargeRate <= Max_ChargeRate) 
   {
     printf("Charge Rate out of range!\n");
      
     if(ChargeRate < Min_ChargeRate)
     CheckChargeRateforLowBreach();
     else
     CheckChargeRateforHighBreach();
     
     ParamStatus = Not_Ok;
   }
  else
  {
    // CheckforWarning(ChargeRate);
     ParamStatus = Ok;
  }
}
                     
int IsbatteryOk(float Temperature, float Soc, float ChargeRate,TempratureUnit_ten TempUnit) 
{
   float ConvertedTemprature;
   ConvertedTemprature =TempratureUnitConversion(Temperature,TempUnit);
   return IsbatteryTempCheck(ConvertedTemprature) && IsbatterySocCheck(Soc) && IsbatteryChargeRateCheck(ChargeRate);
 
 }

int main() {
  assert(IsbatteryOk(25, 70, 0.7,FAHRENHEIT));
//  assert(!IsbatteryOk(30, 85, 0.9,CELCIUS));
//  assert(IsbatteryOk(25,70,1,FAHRENHEIT));
//  assert(!IsbatteryOk(55,65,0.7,CELCIUS));
// assert(IsbatteryOk(10,30,1.5,FAHRENHEIT));
}
