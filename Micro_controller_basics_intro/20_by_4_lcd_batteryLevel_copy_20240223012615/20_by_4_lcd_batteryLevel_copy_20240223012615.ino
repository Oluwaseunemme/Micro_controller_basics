#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
//3 by 5 battry bal
byte c1[]={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};
byte c2[]={
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte c3[]={
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte c4[]={
  0b11111,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte c5[]={
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b11111
};
byte c6[]={
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte c7[]={
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};
byte c8[]={
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b11111
};
byte c9[]={
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};
void setup() {
  lcd.createChar(1,c4);
  lcd.createChar(2,c1);
  lcd.createChar(3,c7);
  lcd.createChar(4,c9);
  lcd.createChar(5,c2);
  lcd.createChar(7,c5);
  lcd.createChar(8,c3);
  lcd.createChar(9,c6);
  lcd.createChar(6,c8);

  lcd.init();
  lcd.backlight();
}
void loop() {
  for( int j=7;j<=11;j++){
    lcd.setCursor(j,1);
    if(j==7){lcd.write((byte)1);}
    else if(j>7 && j<11){lcd.write(2);}
    if(j==11){lcd.write(3);}
}
lcd.setCursor(11,2);
lcd.write(4);
lcd.setCursor(11,3);
lcd.write(6);
lcd.setCursor(10,3);
lcd.write(2);
lcd.setCursor(9,3);
lcd.write(2);
lcd.setCursor(8,3);
lcd.write(2);
lcd.setCursor(7,3);
lcd.write(7);
lcd.setCursor(7,2);
lcd.write(9);


}
