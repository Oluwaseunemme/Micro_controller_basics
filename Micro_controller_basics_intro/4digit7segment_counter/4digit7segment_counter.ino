int latchpin=11,datapin=12,clockpin=9,countn=0,countn2=0;
int d[]={4,5,6,7};
byte data[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void setup() {
  // put your setup code here, to run once:
pinMode(latchpin,OUTPUT);
pinMode(datapin,OUTPUT);
pinMode(clockpin,OUTPUT);
  for(int j=3;j<=7;j++){pinMode(j,OUTPUT);}
 Serial.begin(9600);
}

void loop() {
    for(int i=0;i<=3;i++){
      if(i==countn2){digitalWrite(d[countn2],LOW);}
        else{digitalWrite(d[i],HIGH);}
    }
   digitalWrite(latchpin,LOW);
   shiftOut(datapin,clockpin,MSBFIRST,data[countn]);
   digitalWrite(latchpin,HIGH);
   countn++;
   countn2++;
   delay(500);
    if(countn2>3){countn2=0;}
    if(countn>9){countn=0;}
}