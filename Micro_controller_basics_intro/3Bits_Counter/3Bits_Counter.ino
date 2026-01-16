int led1=5,led2=6,led3=7,state;
byte data=0b000;
String info;
void setup() {
 Serial.begin(9600);
 for(int i=5;i<=7;i++){
  pinMode(i,OUTPUT);
 }
}
void loop() {
 info=String(data,BIN);
  while(info.length()<3){
    info="0"+info;
  }
 Serial.print("Current byte:");
  Serial.println(info);
   for(int j=0;j<=2;j++){
    char c=info.charAt(j);
    state=byte(c)-48;
   if(j==0){
    digitalWrite(led1,state);}
    else if(j==1){
    digitalWrite(led2,state);}
    else if(j==2){
    digitalWrite(led3,state);}
   }
  data+=1;
if(info=="111"){data=0b000;}
delay(1000);
}