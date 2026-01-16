#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int hour,minut,sec,index,buzzpin=7,buzzstate=0;
String days[]={"Sun","Mon","Tues","Wed","Thur","Fri","Sat"};
void setup() {
  pinMode(buzzpin,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();}
void loop() {
     lcd.clear();lcd.setCursor(0,0);
  Serial.print("Enter Current Hour:");
     while(Serial.available()==0){}
     hour=Serial.parseInt();
     Serial.println(hour);
     lcd.print("SET-HOUR=");
     lcd.print(hour);
 Serial.print("Enter Current Minute:");
    while(Serial.available()==0){}
    minut=Serial.parseInt();
    Serial.println(minut);
    lcd.clear();
    lcd.print("SET-MINUTE=");
    lcd.print(minut);
 Serial.print("Enter Current Day-Index:");
    while(Serial.available()==0){}
    index=Serial.parseInt();
    Serial.println(index);
    lcd.clear();
    lcd.print("SET-DAY=");
    lcd.print(days[index]);
    delay(1000);
    lcd.clear();
while(1){delay(1000);sec++;
  /*if(hour==15 && minut==40){Alarm option
    lcd.setCursor(0,1);
    lcd.print("Alarm ON....");
    if(buzzstate==0){buzzstate=1;}
    else if(buzzstate==1){buzzstate=0;}
    digitalWrite(buzzpin,buzzstate);}*/
 if(index>6){index=0;}
 if(sec==60){lcd.clear();sec=0;minut++;}
 if(minut==60){minut=0;hour++;}
 if(hour==24){hour=12;index++;}
 lcd.setCursor(0,0);
   lcd.print(days[index]);
   lcd.print("  ");
   lcd.print(hour);
   lcd.print("h");
   lcd.print(":");
   lcd.print(minut);
   lcd.print("m");
   lcd.print(":");
   lcd.print(sec);
   lcd.print("s");
}}