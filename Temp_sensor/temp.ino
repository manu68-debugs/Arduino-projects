#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int AP = A1;
int DP = 4; 
int Min = -25;
int Max = 80;
const float CURRENT=5.0;
const float Max_AD=1023.0; 
const float AD_Value_Volt = (Max_AD / 5.0) * CURRENT;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup (){

  pinMode (AP, INPUT);
  pinMode (DP, INPUT);
  lcd.begin();
  lcd.backlight();   
}
void loop (){

  float Analog;
  float Tf;
  float Tc;
  int Digital;
  //formula for temp
  int Temp_Range = (abs(Min) + abs(Max));
  Analog = analogRead(AP);   
  Tf = Analog * (Temp_Range / AD_Value_Volt);
  Tc = (Tf - 32) * 5/9;
  Digital = digitalRead (DP);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(Tc);
  lcd.setCursor(6,0);
  lcd.print((char)223);
  lcd.setCursor(7,0);
  lcd.print("C");
  
  delay (200);
}