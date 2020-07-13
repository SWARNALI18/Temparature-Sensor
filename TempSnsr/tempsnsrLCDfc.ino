#include <LiquidCrystal.h>

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T,Tc,Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin(9600);
analogWrite(6,20);
lcd.begin(16,2);
}

void loop() {

 Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  lcd.print("Temp:"); 
  lcd.print(Tf);
  lcd.print(" F");
  lcd.setCursor(2,1);
  lcd.print(Tc);
  lcd.print(" C");   
  
  delay(500);            
  lcd.clear();
}
