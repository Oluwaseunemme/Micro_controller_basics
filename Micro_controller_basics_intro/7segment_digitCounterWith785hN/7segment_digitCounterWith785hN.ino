int latchpin=11,datapin=12,clockpin=9,countn=0;
byte data[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void setup() {
  // put your setup code here, to run once:
pinMode(latchpin,OUTPUT);
pinMode(datapin,OUTPUT);
pinMode(clockpin,OUTPUT);
 Serial.begin(9600);
}

void loop() { 
   digitalWrite(latchpin,LOW);
   shiftOut(datapin,clockpin,MSBFIRST,data[countn]);
   digitalWrite(latchpin,HIGH);
   countn++;
   delay(500);
if(countn>9){countn=0;}
}
