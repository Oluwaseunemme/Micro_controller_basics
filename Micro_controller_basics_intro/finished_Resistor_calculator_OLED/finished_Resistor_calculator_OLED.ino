#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define up_pin 5
#define down_pin 6
#define select_pin 7

const char color0[] PROGMEM="Black";
const char color1[] PROGMEM="Brown";
const char color2[] PROGMEM="Red";
const char color3[] PROGMEM="Orange";
const char color4[] PROGMEM="Yellow";
const char color5[] PROGMEM="Green";
const char color6[] PROGMEM="Blue";
const char color7[] PROGMEM="Violet";
const char color8[] PROGMEM="Grey";
const char color9[] PROGMEM="White";

const char band1[] PROGMEM="Select band1 color..";
const char band2[] PROGMEM="Select band2 color..";
const char band3[] PROGMEM="Select band3 color..";
char buffer[30];
uint8_t countn=0,banda,bandb,bandc,countn3;
// Canvas size
const uint8_t x = 128;
const uint8_t y = 64;
const uint8_t reset = -1;
uint8_t old_info=0,nums=0;
// Create display
Adafruit_SSD1306 display(x, y, &Wire, reset);      

void setup() {
  Serial.begin(115200);
  pinMode(up_pin,INPUT_PULLUP);
  pinMode(down_pin,INPUT_PULLUP);
  pinMode(select_pin,INPUT_PULLUP);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
  delay(500);
}
void drawText(String text, int x, int y) {
  display.setTextSize(1);       // Normal 1:1 pixel scale
  display.setTextColor(BLACK);  // Draw white text
  display.setCursor(x, y);      // Start at top-left corner
  display.fillRect(10,10,95,15,WHITE);
  display.println(text);
  display.display();
}
void draw_Text(String text,int x,int y){
  display.setTextSize(1);       // Normal 1:1 pixel scale
  display.setTextColor(WHITE);  // Draw white text
  display.setCursor(x, y);      // Start at top-left corner
  display.println(text);
  display.display();
}
void display_const(){
 drawText("Resistor Value...",12,12);
 display.drawRect(40,47,80,12,WHITE);
 draw_Text("COLOR:",2,50);
}
void calc_val(){
 drawText("Resistor Value...",12,12);
 int value1=(String(banda)+String(bandb)).toInt();
 float ans=value1*(pow(10,bandc));
 draw_Text("Values:"+String(banda)+","+String(bandb)+","+String(bandc),2,30);
 draw_Text("ANS:"+String(ans)+"ohm",2,50);
}
void color_sel(){
  switch(countn){
    case 0:draw_Text(strcpy_P(buffer,color0),42,48); break;
    case 1:draw_Text(strcpy_P(buffer,color1),42,48); break;
    case 2:draw_Text(strcpy_P(buffer,color2),42,48); break;
    case 3:draw_Text(strcpy_P(buffer,color3),42,48); break;
    case 4:draw_Text(strcpy_P(buffer,color4),42,48); break;
    case 5:draw_Text(strcpy_P(buffer,color5),42,48); break;
    case 6:draw_Text(strcpy_P(buffer,color6),42,48); break;
    case 7:draw_Text(strcpy_P(buffer,color7),42,48); break;
    case 8:draw_Text(strcpy_P(buffer,color8),42,48); break;
    case 9:draw_Text(strcpy_P(buffer,color9),42,48);
  }
}
void loop(){
  while(countn3<=2){
    if(countn3==0){
      draw_Text(strcpy_P(buffer,band1),2,30);}
    else if(countn3==1){
      draw_Text(strcpy_P(buffer,band2),2,30);}
    else if(countn3==2){
      draw_Text(strcpy_P(buffer,band3),2,30);}
    display_const();
    color_sel();                         
    if(digitalRead(up_pin)==0 && countn!=9){delay(200);display.clearDisplay();
       countn++;
       color_sel();
       }
    else if(digitalRead(down_pin)==0 && countn!=0){delay(200);display.clearDisplay();
       countn--;
       color_sel();
       }
    if(digitalRead(select_pin)==0){delay(200);display.clearDisplay();countn3++;
    while(digitalRead(select_pin)!=0){
        draw_Text("Press sel_pin to cont...",2,20);
      if(countn3==1){banda=countn;
         draw_Text("BAND1 value:"+String(banda),2,5);}
      else if(countn3==2){bandb=countn;
         draw_Text("BAND2 value:"+String(bandb),2,5);}
      else if(countn3==3){bandc=countn;
         draw_Text("BAND3 value:"+String(bandc),2,5);}
        if(digitalRead(select_pin)==0){display.clearDisplay();}
         }
         countn=0;
      }
    }
    calc_val();
    if(digitalRead(select_pin)==0){delay(200);display.clearDisplay();countn3=0;}
 }
 