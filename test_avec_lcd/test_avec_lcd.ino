int i=0;
int f=0;
int r=0;
int c=0;
float n=0;
#include <Wire.h>

#include "rgb_lcd.h"

rgb_lcd lcd;
void setup() {
  pinMode(3, OUTPUT);   
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 0);
 
}

void loop() {
  lcd.clear();
  f=analogRead(A0);
  i=map(f,0,1023,0,255 );
  r=map(i,0,254,0,100);
  c=(r*78)/100;
  analogWrite(3, i);

  if (r<23) {
  lcd.clear();
  lcd.setRGB(75, 169, 190);
  lcd.print("Moteur off : "); 
  lcd.print(r);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print(c);
  lcd.print(" tr/min ");
  n=c/60.00;
  lcd.print(n);
  lcd.print("Hz");
  lcd.setCursor(0, 2);
  delay(100);
  }
  else {
  lcd.clear();
  lcd.setRGB(36, 235, 15);
  lcd.print("Moteur on : "); 
  lcd.print(r);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print(c);
  lcd.print(" tr/min ");
  n=c/60.00;
  lcd.print(n);
  lcd.print("Hz");
  lcd.setCursor(0, 2);
  delay(100);
  }
}
