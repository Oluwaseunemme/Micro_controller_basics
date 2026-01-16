#include <Servo.h>
Servo myser;
unsigned long interval=1000,newtime,previoustime=0;
unsigned long intervalservo=20,previousservo=0,intervalgreen=500,previousgreen=0;
int spin=10,sinm,servopin=11,ledpin=12,redpin=13,ledstate=0;
int j=9,servoangle=0;
int segment[10][7]= {
                {1,1,1,1,1,1,0},//0
                {0,1,1,0,0,0,0},//1
                {1,1,0,1,1,0,1},//2
                {1,1,1,1,0,0,1},//3
                {0,1,1,0,0,1,1},//4
                {1,0,1,1,0,1,1},//5
                {1,0,1,1,1,1,1},//6
                {1,1,1,0,0,0,0},//7
                {1,1,1,1,1,1,1},//8
                {1,1,1,1,0,1,1},//9
                };
void setup() {
  for(int i=2;i<=8;i++)
    pinMode(i,OUTPUT);
    pinMode(ledpin,OUTPUT);
    pinMode(redpin,OUTPUT);
    myser.attach(servopin);
}
void loop() {
  sinm=digitalRead(spin);
  newtime=millis(); 
  if(newtime-previousgreen>=intervalgreen){
    if(ledstate==0){ledstate=1;}
    else if(ledstate==1){ledstate=0;}
    digitalWrite(ledpin,ledstate);
    previousgreen=newtime;}
  if(newtime-previoustime>=interval){
  for(int i=2;i<=8;i++){
    digitalWrite(i,segment[j][i-2]);}
     j--;
     previoustime=newtime;}
  if(j==0){j=9;}
  if(sinm==HIGH){j=9; servoangle=0;
   digitalWrite(redpin,HIGH);
   digitalWrite(ledpin,LOW);}
   else{digitalWrite(redpin,LOW);}
  if(newtime-previousservo>=intervalservo){
    myser.write(servoangle);
    servoangle ++;
    previousservo=newtime;
    if(servoangle==180){servoangle=0;}
   }
  }
   
