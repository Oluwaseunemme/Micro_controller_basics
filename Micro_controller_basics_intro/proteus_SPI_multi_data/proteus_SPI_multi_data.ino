#include <SPI.h>

int slaves[]={2,3,4,5};
byte info[]={0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111};
int data[]={22,16,7,10,13,4,20,9};
int delayTime = 1000,maxnum,maxbit=8,oldnum=0;
uint8_t countn=0,countn2=0,countn3=0;
unsigned long newtime,lastime=0,interval=3000;
void setup() {
  for(int j=0;j<=3;j++){
  pinMode(slaves[j],OUTPUT);}
  SPI.begin();
  Serial.begin(9600);
  SPI.setBitOrder(LSBFIRST);   
}

void loop() {
  if(oldnum!=data[countn3]){
    while(data[countn3]>maxbit){
      maxbit+=8;
      maxnum++;}
      oldnum=data[countn3];
  }
  if(data[countn3]>=8){countn2=7;
    if((data[countn3]-8)>=1){data[countn3]=(data[countn3]-8);}}
  else if(data[countn3]<8){
    countn2=data[countn3]-1;
  }
    digitalWrite(slaves[countn], LOW);            //Write our Slave select low to enable the SHift register to begin listening for data
    SPI.transfer(info[countn2]);                     //Transfer the 8-bit value of data to shift register, remembering that the least significant bit goes first
    digitalWrite(slaves[countn], HIGH);           //Once the transfer is complete, set the latch back to high to stop the shift register listening for data
    delay(delayTime);                   //Delay
  countn++;
  if(countn>maxnum){countn=0; while(1){}}
    countn3++;
  if(countn3>7){countn3=0;}
}
  