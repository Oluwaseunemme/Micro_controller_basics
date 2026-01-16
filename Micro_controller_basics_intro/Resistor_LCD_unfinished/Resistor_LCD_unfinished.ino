//#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Canvas size
const int x = 128;
const int y = 64;
const int reset = -1;
String band1="Enter band1 colour",band2="Enter band2 colour",band3="Enter band3 colour";
// Create display
Adafruit_SSD1306 display(x, y, &Wire, reset);
#define up_pin 6
#define down_pin 7
#define enter_pin 8
int y_axix[]={4,15,29,43,57,71,85,99,113,127,141};
//int val[]={0,1,2,3,4,5,6,7,8,9};
int countn=1,num1,num2,num3,num=0,counterr=0;
String ret;
void setup() {
  Serial.begin(115200);
  pinMode(up_pin,INPUT_PULLUP);
  pinMode(down_pin,INPUT_PULLUP);
  pinMode(enter_pin,INPUT_PULLUP);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  //Don't proceed,loop forever
  }
  display.display();
  delay(500);
  display.clearDisplay();
}
String bandd(){
  if(countn==1){
    ret=band1;
  }
  else if(countn==2){
    ret=band2;
  }
  else if(countn==3){
    ret=band3;
  }
  return ret;
}
/*void Rect(int a,int b,int width,int height){
  display.drawRect(a,b,width,height,WHITE);
  display.display();
}*/
void drawText(String text, int x, int y) {
  if(digitalRead(up_pin)==0 && num>3){delay(100);
    for(int i=0;i<=10;i++){
      y_axix[i]-=4;
    }
    //Serial.println("up_pin state="+String(digitalRead(up_pin)));
    display.clearDisplay();
  }
  else if(digitalRead(down_pin)==0 && num<3){delay(100);
    for(int i=0;i<=10;i++){
      y_axix[i]+=4;
      display.clearDisplay();
    } }
  display.setTextSize(1);       // Normal 1:1 pixel scale
  display.setTextColor(WHITE);  // Draw white text
  display.setCursor(x, y);      // Start at top-left corner
  display.println(text);
  display.display();
}
void sel_band(){
  drawText("Val:"+String(num),67,32);
  if(digitalRead(up_pin)==0 && num!=9){delay(200);
    num++;
    display.clearDisplay();
  }
  else if(digitalRead(down_pin)==0 && num!=0){delay(200);
    num--;
    display.clearDisplay();
    }
  if(digitalRead(enter_pin)==0 && countn==1){delay(200);
    countn++;num1=num;
  }
  else if(digitalRead(enter_pin)==0 && countn==2){delay(200);
    countn++;num2=num;
  }
  else if(digitalRead(enter_pin)==0 && countn==3){delay(200);
    countn++;num3=num;
  }
}
void dis(){
  drawText(bandd(),3,y_axix[0]);
  drawText("Black:0",3,y_axix[1]);
  drawText("Brown:1",3,y_axix[2]);
  drawText("Red:2",3,y_axix[3]);
  drawText("Orange:3",3,y_axix[4]);
  drawText("Yellow:4",3,y_axix[5]);
  drawText("Green:5",3,y_axix[6]);
  drawText("Blue:6",3,y_axix[7]);
  drawText("violet:7",3,y_axix[8]);
  drawText("grey:8",3,y_axix[9]);
  drawText("WHITE:9",3,y_axix[10]);
}
float ans(){
  String join=String(num1)+String(num2);
  float result=join.toInt()*(pow(10,num3));
  return result;
}
void loop() {
  Serial.println("enter_pin val:"+String(digitalRead(enter_pin)));
  Serial.println("up_pin val:"+String(digitalRead(up_pin)));
  Serial.println("down_pin val:"+String(digitalRead(down_pin)));
 delay(300);
 dis();
 if(digitalRead(enter_pin)==0){delay(100);counterr++;
  while(digitalRead(enter_pin)==HIGH && countn<=3){
       dis();
       sel_band();
        }
 }
 if(countn>3){display.clearDisplay();
  while(1){
     drawText("Resistance value:"+String(ans()),5,6);
  }
 }
}
