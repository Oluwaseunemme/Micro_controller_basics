#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include  <math.h>
// Canvas size
const uint8_t x = 128;
const uint8_t y = 64;
const uint8_t reset = -1;
float old_num=0,num=0;
// Create display
Adafruit_SSD1306 display(x, y, &Wire, reset);      

void setup() {
  Serial.begin(115200);
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
  display.setTextColor(WHITE);  // Draw white text
  display.setCursor(x, y);      // Start at top-left corner
  display.println(text);
  display.display();
}
float map_it(float val,float val_min,float val_max,float out_min,float out_max){
   float result=(val-val_min)*(out_max-out_min)/(val_max-val_min)+out_min;
   return result;
}
void draw_line(int x1,int y1,float x2,float y2){
  //drawText("circular_movement..",2,2);
  display.drawCircle(30,32,23,WHITE);
  display.drawLine(x1,y1,x2,y2,WHITE);
  display.display();
  display.clearDisplay();
}
void loop(){
    float angle=map_it(analogRead(A0),0,1023,360,0);
   if(old_num!=angle){
      Serial.println("Angle:"+String(angle)+"°");
    float x=map_it(analogRead(A0),0,1023,0,TWO_PI);
    draw_line(30,32,30+20*cos(x),32+20*sin(x));
    old_num=angle;
    }
}
