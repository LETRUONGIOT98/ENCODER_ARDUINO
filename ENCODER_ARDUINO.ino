int tat = 4;
int cap1 = 5;
int cap2 = 6;
int cap3 = 7;
int thuan = 8;
int nguoc = 9;
int IN1 = 10;
int IN2 = 11;
int i = 0;
String j="TAT";
String h="THUAN";
int pwm = 0;
 #include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

 
void setup() {
  lcd.init();
  //lcd.begin();
  lcd.backlight();
  pinMode(tat, INPUT_PULLUP);
  pinMode(cap1, INPUT_PULLUP);
  pinMode(cap2, INPUT_PULLUP);
  pinMode(cap3, INPUT_PULLUP);
  pinMode(thuan, INPUT_PULLUP);
  pinMode(nguoc, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
 
 
}
 
void chay(int chedo,int pwm1){
  if(chedo == 0){
  analogWrite(IN1, pwm1);
  analogWrite(IN2, 0);}
  if(chedo == 1){
    analogWrite(IN1, 0);
  analogWrite(IN2, pwm1);
  }
}
void loop() {
 
 if(digitalRead(tat) == 0){
  pwm = 0;
  chay(i,pwm);
  j ="DUNG ";
 }
 if(digitalRead(cap1) == 0){
   pwm = 85;
  chay(i,pwm);
  j ="CAP 1";
  lcd.setCursor(0,0);
  lcd.print("TOC DO: 1000 rmp");
 }
 if(digitalRead(cap2) == 0){
  pwm = 170;
  chay(i,pwm);
  j ="CAP 2";
  lcd.setCursor(0,0);
  lcd.print("TOC DO: 2000 rmp");
 }
 if(digitalRead(cap3) == 0){
  pwm = 255;
  chay(i,pwm);
  j ="CAP 3";
  lcd.setCursor(0,0);
  lcd.print("TOC DO: 3000 rmp");
 }
 if(digitalRead(thuan) == 0){
  i =0;
  chay(i,pwm);
  h ="THUAN";
 }
 if(digitalRead(nguoc) == 0){
  i = 1;
  chay(i,pwm);
  h ="NGUOC";
 }
  

  lcd.setCursor(0,1);
  lcd.print(String(j) + "   " + String(h));
  delay(100);
}
