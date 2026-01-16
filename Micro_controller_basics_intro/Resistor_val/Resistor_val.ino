String colours[]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
int multi[]={0,1,2,3,4,5,6,7,8,9};
int band1,band2,band3;
String info="";
bool state;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void getinfo(){
    Serial.print("Input first band colour:");
    while(!Serial.available()){}
    info=Serial.readString();
    Serial.println(info);
    for(int i=0;i<=9;i++){
      if(info==colours[i]){
        band1=multi[i];
        Serial.println("band1:"+String(band1));
      }
     }
    Serial.print("Input second band colour:");
    while(!Serial.available()){}
    info=Serial.readString();
    Serial.println(info);
    for(int i=0;i<=9;i++){
      if(info==colours[i]){
        band2=multi[i];
        Serial.println("band2:"+String(band2));
      }
      }
    Serial.print("Input third band colour:");
    while(!Serial.available()){}
    info=Serial.readString();
    Serial.println(info);
    for(int i=0;i<=9;i++){
      if(info==colours[i]){
        band3=multi[i];
        Serial.println("band3:"+String(band3));
      }
      }
   String bind=String(band1)+String(band2);
   unsigned long resistance=(bind.toInt()*(pow(10,band3)))+1;
   Serial.println("Resistance value for resistor with the following data:"+String(resistance));
}
void loop() {
 getinfo();
}
