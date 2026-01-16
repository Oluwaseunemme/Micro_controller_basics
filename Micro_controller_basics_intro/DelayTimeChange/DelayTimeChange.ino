int ledpin=6;
int delayt=100;
void setup(){
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}
void ledf(){Serial.println(delayt);
  digitalWrite(ledpin,HIGH);
  delay(delayt);
  digitalWrite(ledpin,LOW);
  delay(delayt);}
void delay(){
  while(true){
    Serial.println("Delay time is rising.");break;}
  while(true){delay(delayt);
      ledf();
    delayt+=100;if(delayt==1000){break;}}
   if(delayt==1000){
    while(true){
      Serial.println("Delay time is falling.");break;}
    while(true){delay(delayt);
      ledf();
      delayt-=100;if(delayt==100){break;}}}
   
}
void loop(){  
ledf();
delay();
}