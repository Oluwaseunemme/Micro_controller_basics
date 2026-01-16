#include <LiquidCrystal_I2C.h>
#define key1 5
#define key2 6
#define key3 7
#define ledpin 4
  String gates[]={"NOT","AND","OR","XOR"};
  int countn=-1;
LiquidCrystal_I2C lcd(0x27,16,2);
int info1,info2;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}
void keystate(){
   info1=digitalRead(key2);
   info2=digitalRead(key3);
  lcd.setCursor(0,1);
  lcd.print("IN1:");
  lcd.print(info1);
  lcd.print(" , ");
  lcd.print("IN2:");
  lcd.print(info2);
}
void mode(){
 while(1){
  lcd.setCursor(0,0);
  lcd.print("press key2:");
  if(digitalRead(key2)==HIGH){delay(200);lcd.clear();//use key2 to change gate mode
    countn+=1;
   if(countn>3){countn=-1;}
    lcd.setCursor(0,0);
    lcd.print("Enter mode:");
    lcd.setCursor(0,1);
    lcd.print("GATE:"+gates[countn]);  
    }
  if(digitalRead(key1)==HIGH){delay(200); //use key1 to break 
  break;}
}}
void notGate(){
  while(1){
    info1=digitalRead(key2);
   lcd.setCursor(0,0);
   lcd.print("NOT gate");
  lcd.setCursor(0,1);
  lcd.print("INPUT:");
  lcd.print(info1);
  if(digitalRead(key2)==HIGH){
    digitalWrite(ledpin,LOW);
  }
  else{digitalWrite(ledpin,HIGH);}
 if(digitalRead(key1)==HIGH){break; lcd.clear();}
}}
void orGate(){
  while(1){
  lcd.setCursor(0,0);
  lcd.print("OR gate");
 keystate();
 if(digitalRead(key2)==LOW && digitalRead(key3)==LOW){
  digitalWrite(ledpin,LOW);
  
 }
  else{digitalWrite(ledpin,HIGH);}
  if(digitalRead(key1)==HIGH){break; lcd.clear();}
}}
void andGate(){
  while(1){
    info1=digitalRead(key2);
    info2=digitalRead(key3);
  lcd.setCursor(0,0);
  lcd.print("AND gate");
  keystate();
  if(digitalRead(key2)==HIGH && digitalRead(key3)==HIGH){
    digitalWrite(ledpin,HIGH);
  }
  else{digitalWrite(ledpin,LOW);}
  if(digitalRead(key1)==HIGH){break; lcd.clear();}
}}
void xorGate(){
  while(1){
   info1=digitalRead(key2);
   info2=digitalRead(key3);
  lcd.setCursor(0,0);
  lcd.print("XOR gate");
  keystate();
  if(digitalRead(key2)!=digitalRead(key3)){
    digitalWrite(ledpin,HIGH);
  }
   else{digitalWrite(ledpin,LOW);}
   if(digitalRead(key1)==HIGH){break; lcd.clear();}
}}
void loop() {
  mode();
 while(1){
  if(digitalRead(key1)==HIGH){lcd.clear();
    delay(250);
    mode();}
  if(countn==0){
  lcd.clear();
  notGate();
}  
  else if(countn==1){
    lcd.clear();
    andGate();
  }
  else if(countn==2){
    lcd.clear();
    orGate();
  }
  else if(countn==3){
    lcd.clear();
    xorGate();
  }   
}}
