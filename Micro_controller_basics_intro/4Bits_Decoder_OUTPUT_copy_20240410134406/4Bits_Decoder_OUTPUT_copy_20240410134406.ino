int led1=5,led2=6,led3=7,led4=8,state;
byte data=0b0001;
String info;
void setup() {
 Serial.begin(9600);
 for(int i=5;i<=8;i++){
  pinMode(i,OUTPUT);
 }
}
void loop() {
 info=String(data,BIN);
  while(info.length()<4){
    info="0"+info;
  }
 Serial.print("Current byte:");
  Serial.println(info);
   for(int j=0;j<=3;j++){
    char c=info.charAt(j);
    state=byte(c)-48;
   if(j==0){
    digitalWrite(led1,state);}
    else if(j==1){
    digitalWrite(led2,state);}
    else if(j==2){
    digitalWrite(led3,state);}
    else if(j==3){
    digitalWrite(led4,state);}
   }
  data+=1;
if(info=="1111"){data=0b0000;}
delay(700);
}

