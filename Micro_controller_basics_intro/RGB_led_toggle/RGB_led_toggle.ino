int ledpins[]={8,9,11};
#define in_pin 7
String info1="0",info2="1",info3="2",val;
int countn=0;
int num=0,old_num=1;
void setup() {
  for(int i=0;i<=2;i++){
 pinMode(ledpins[i],OUTPUT);}
 pinMode(in_pin,INPUT_PULLUP);
 Serial.begin(9600);
}
String get_info(){
  if(countn==0){val=info1;}
  else if(countn==1){val=info2;}
  else if(countn==2){val=info3;}
  return val;
}
void loop() {
  num=analogRead(A0);
  int new_num=map(num,0,1023,1,12);
  if(new_num!=old_num){
    old_num=new_num;
    Serial.println("L"+String(new_num));
  }
  if(digitalRead(in_pin)==0){delay(200);countn++;
    countn>2? countn=0 :countn=countn;
    Serial.println(get_info());}
  for(int x=0;x<=2;x++){
    if(x==countn){digitalWrite(ledpins[countn],HIGH);}
    if(x==countn){continue;}
    digitalWrite(ledpins[x],LOW);
}
}