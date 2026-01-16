#include <LiquidCrystal.h>
int lcds[]={8,9,10,11,12,13};
int relays[]={5,6,7};
int phase[]={2,3,4};
byte red;
byte yellow;
byte blue;
int dt=500;
LiquidCrystal lcd(lcds[0],lcds[1],lcds[2],lcds[3],lcds[4],lcds[5]);

void setup() {
  lcd.begin(16,2);
  pinMode(relays[0],OUTPUT);
  pinMode(relays[1],OUTPUT);
  pinMode(relays[2],OUTPUT);
}
void loop() {
red=digitalRead(phase[0]);
yellow=digitalRead(phase[1]);
blue=digitalRead(phase[2]);

if(red==1 && yellow==1 && blue==1){
  digitalWrite(relays[0],HIGH);
  digitalWrite(relays[1],HIGH);
  digitalWrite(relays[2],HIGH);
  lcd.setCursor(0,0);
  lcd.print("ALL 3-PHASE ON");
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Red phase info=");
  lcd.print(red);
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Yellow phase info=");
  lcd.print(yellow);
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Blue phase info=");
  lcd.print(blue);
  delay(dt);}
else if(red==0 || yellow==0 || blue==0){
  digitalWrite(relays[0],LOW);
  digitalWrite(relays[1],LOW);
  digitalWrite(relays[2],LOW);
  lcd.setCursor(0,0);
  lcd.print("All 3-phase not ON.");
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Red phase info=");
  lcd.print(red);
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Yellow phase info=");
  lcd.print(yellow);
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Blue phase info=");
  lcd.print(blue);
  delay(dt);}
}
