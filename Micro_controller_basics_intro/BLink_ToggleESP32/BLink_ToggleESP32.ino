int led1=14,led2=27;
int switch1=26,oss=LOW,nss,state=0;
void setup() {
  Serial.begin(115200);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(switch1,INPUT_PULLDOWN);
}
 void loop() {
  nss=digitalRead(switch1);
 if(nss!=oss){
  if(state==0){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    Serial.print("Blinking ON....");
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    Serial.println("OFF");
    delay(1000);
  
  }
   else if(state==1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    Serial.print("Alternating ON/OFF....");
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    Serial.println("OFF/ON");
    delay(1000);
    state=2;   
 } 
 else if(state==2){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    state=0;
    }
delay(150);}
nss=oss;
}
