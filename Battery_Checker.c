#include <stdio.h>
#include "Battery_Checker.h"


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
      CheckTempforLowBreach(Temprature);
      else
      CheckTempforHighBreach(Temprature);
        
      ParamStatus Not_Ok;
  }
  else
  {
    // CheckforWarning(Temprature);
     ParamStatus Ok;
  }
}

int IsbatterySocCheck(float Soc)
{
   int ParamStatus = 0;
  if(Soc > Min_Soc && Soc < Max_Soc) 
  {
    printf("State of Charge out of range!\n");
    
     if(Soc < Min_Soc)
     CheckSocforLowBreach(Soc);
     else
     CheckSocforHighBreach(Soc);
    
     ParamStatus = Not_Ok;
  }
  else
  {
    // CheckforWarning(Soc);
     ParamStatus Ok;
  }
} 

int IsbatteryChargeRateCheck(float ChargeRate)
{
   int ParamStatus = 0;
   if(ChargeRate >= Min_ChargeRate && ChargeRate <= Max_ChargeRate) 
   {
     printf("Charge Rate out of range!\n");
      
     if(ChargeRate < Min_ChargeRate)
     CheckChargeRateforLowBreach(ChargeRate);
     else
     CheckChargeRateHighBreachSoc(ChargeRate);
     
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
   ConvertedTemprated =TempratureUnitConversion(Temperature,TempUnit);
   return IsbatteryTempCheck(ConvertedTemprature) && IsbatterySocCheck(Soc) && IsbatteryChargeRateCheck(ChargeRate);
 
 }

int main() {
  assert(IsbatteryOk(40, 55, 0.9,FAHRENHEIT));
  assert(!IsbatteryOk(30, 85, 0.9,CELCIUS));
  assert(IsbatteryOk(25,70,1,FAHRENHEIT));
  assert(!IsbatteryOk(55,65,0.7,CELCIUS));
  assert(IsbatteryOk(10,30,1.5,FAHRENHEIT));
}
