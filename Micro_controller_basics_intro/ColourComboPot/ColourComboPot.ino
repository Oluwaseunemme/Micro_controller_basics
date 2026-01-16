int Rpin=3;
int Gpin=9;
int Bpin=6;
int myled(int potvalue1,int potvalue2,int Ranalogvalue,int Ganalogvalue,int Banalogvalue){

if(analogRead(A0)>potvalue1 && analogRead(A0)<potvalue2){
  analogWrite(Rpin,Ranalogvalue);
  analogWrite(Gpin,Ganalogvalue);
  analogWrite(Bpin,Banalogvalue); 
}
}

void setup() {
  Serial.begin(9600);
pinMode(Rpin,OUTPUT);
pinMode(Gpin,OUTPUT);
pinMode(Bpin,OUTPUT);
  // put your setup code here, to run once:

}
void loop() {
  Serial.println(analogRead(A0));
  // put your main code here, to run repeatedly:
myled(100,150,255,0,0);//pure red
myled(150,250,0,255,0);//pure green
myled(250,350,0,0,255);//pure blue
myled(350,450,255,255,0);//yellow
myled(450,550,255,128,0);//orange
myled(550,650,255,0,128);//rose
myled(650,750,255,0,255);//magenta
myled(750,850,128,0,255);//violet
myled(850,950,0,255,255);//cyan
myled(950,1023,0,128,255);//azure
}
