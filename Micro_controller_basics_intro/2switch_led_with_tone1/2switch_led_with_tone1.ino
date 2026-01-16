int info1;
int info2;
int ledpin=9;
int pwm=0;
int buzzpin=2;
void setup(){
Serial.begin(9600);
pinMode(buzzpin,OUTPUT);
}
void loop(){
  info1=digitalRead(6);
  info2=digitalRead(7);
  Serial.print("state for switch is: ");
  Serial.println(info1);
  Serial.print("pwm state is: ");
  Serial.println(pwm);
  delay(250);

  if(info1==1){pwm+=10;}
  if(pwm>249){digitalWrite(buzzpin,HIGH);
             delay(50);
             digitalWrite(buzzpin,LOW);
             pwm=249;
             Serial.println("maximum level reached.");}        
  if(info2==1){pwm-=10;}
  if (pwm<0){digitalWrite(buzzpin,HIGH);
             delay(50);
             digitalWrite(buzzpin,LOW);
            pwm=0;
            Serial.println("minimum level reached.");}

analogWrite(ledpin,pwm);
}
 




