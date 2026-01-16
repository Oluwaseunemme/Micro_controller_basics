#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define data A0
int info;
byte c1[]={
  0b00100,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};
byte c2[]={
  0b00100,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111
};
byte c3[]={
  0b00100,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111
};
byte c4[]={
  0b00100,
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte c5[]={
  0b00100,
  0b11111,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte c6[]={
  0b00100,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
void setup() {
  lcd.init();
  lcd.backlight();
lcd.createChar(1,c1);
lcd.createChar(2,c2);
lcd.createChar(3,c3);
lcd.createChar(4,c4);
lcd.createChar(5,c5);
lcd.createChar(6,c6);
}

void loop() {
 info=analogRead(data);
 int mymap=map(info,1,1010,1,6);

 lcd.setCursor(0,0);
 lcd.print("Battery Bal:");
 if(mymap==1){lcd.write((byte)mymap);}
 else{lcd.write(mymap);} 
}
