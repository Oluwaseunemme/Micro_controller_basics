#define pin1 12
#define pin2 13
#define pin3 14
#define pin4 27

int oldVal1, oldVal2, oldVal3, oldVal4;
int newVal1, newVal2, newVal3, newVal4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReadResolution(10);
}

void loop() {
   newVal1=analogRead(pin1)/10;
   newVal2=analogRead(pin2)/10;
   newVal3=analogRead(pin3)/10;
   newVal4=analogRead(pin4)/10;
   if(oldVal1 !=newVal1 || oldVal2 !=newVal2 || oldVal3 !=newVal3 || oldVal4 !=newVal4){
     oldVal1 =newVal1;
     oldVal2 =newVal2;
     oldVal3 =newVal3;
     oldVal4 =newVal4;
     Serial.println(String(newVal1)+':'+String(newVal2)+':'+String(newVal3)+':'+String(newVal4));
   }
   delay(300);
}
