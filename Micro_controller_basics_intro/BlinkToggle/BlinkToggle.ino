int led1=6,led2=7;
int switch1=5,oss=LOW,nss,state=0,ledstate=0;
unsigned long previoustime=0,newtime,interval=2000;
int ledstate1=0,ledstate2=1;
void setup() {
  Serial.begin(9600);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(switch1,INPUT);
}
void loop() {
  newtime=millis();
  nss=digitalRead(switch1);
 if(nss!=oss){
  if(state==0){
    if(newtime-previoustime>=interval){                                             
      previoustime=newtime;
      if(ledstate==0){ledstate==1;Serial.print("Blinking ON....");}
      else if(ledstate==1){ledstate==0;Serial.println("OFF");}
    digitalWrite(led1,ledstate);
    digitalWrite(led2,ledstate);
    }}
  else if(state==1){state=2;
    if(newtime-previoustime>=interval){
      previoustime=newtime;
     if(ledstate1==0 && ledstate2==1){ledstate1=1;ledstate2=0;Serial.print("Alternating ON/OFF....");}
     else if(ledstate1==1 && ledstate2==0){ledstate1=0;ledstate2=1;Serial.println("OFF/ON");}
    digitalWrite(led1,ledstate1);
    digitalWrite(led2,ledstate2);
    }}
 else if(state==2){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    state=0;
    }}
//delay(150);
nss=oss;
}
