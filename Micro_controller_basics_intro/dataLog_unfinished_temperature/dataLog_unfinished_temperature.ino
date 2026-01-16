#include <DHT.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
#define type DHT11
#define pin 3
#define s1 5
int countn=0;
float T,H,maxT=0,miniT=100,maxH=0,miniH=200;
unsigned long newtime,ptime=0,interval=1000,ptime2=0;
int sec=0,minn=30,hr=2;
String maxTime,maxHime,times;
DHT dht(pin,type);
void setup() {
  // put your setup code here, to run once:
dht.begin();
Serial.begin(9600);
pinMode(s1,INPUT_PULLUP);

while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void time(){
  newtime=millis();
  if(newtime-ptime>=interval){
     sec++;
     ptime=newtime;
  }
  if(sec>59){minn++;sec=1;}
  if(minn>59){hr++;minn=1;}
  if(hr==23 && minn==59){hr=0;}
  times=String(hr)+"hr:"+String(minn)+"min:"+String(sec)+"sec";
}
void logdata(){
  time();
  analys();
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
   T =dht.readTemperature();
   H =dht.readHumidity();
  String dataString1="Temp data:"+String(T)+"c";
  String dataString2="Hum data:"+String(H)+"%";
  if(isnan(T) || isnan(H)){
      Serial.println("Error getting valid readings!!!");
  }
  else{
  // Serial.println("Temperature value:"+String(T)+"c  Humidity value:"+String(H)+"%" );
        if (dataFile) {
          dataFile.println("Time:"+times+"::"+dataString1+" "+dataString2);
          dataFile.close();
          // print to the serial port too:
          //if(newtime-ptime2>=1000){
          Serial.println("Time:"+times+"::"+dataString1+"  , "+dataString2);
          //ptime2=newtime;
        }
        // if the file isn't open, pop up an error:
        else {
          Serial.println("error opening datalog.txt");
        
}}}
void dumps(){
  File dataFile = SD.open("datalog.txt");
  analys();
  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      if(newtime-ptime2>=1000){
     Serial.write(dataFile.read());
     ptime2=newtime;
    }}
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
void analys(){
  if(T>maxT){maxT=T;maxTime=times;}
  if(T<miniT){miniT=T;}
  if(H>maxH){maxH=H;maxHime=times;}
  if(H<miniH){miniH=H;}
}
void loop() {
  Serial.println("Option page!!!");
  Serial.println("Enter 1 to record,2 to analys,3 to read logged data:");
  while(!Serial.available()){}
  int inf=Serial.parseInt();
  if(inf==1){
    Serial.println("Data logging activated...");
    while(digitalRead(s1)==HIGH){newtime=millis();
   logdata();}
  }
  else if(inf==2){
    while(digitalRead(s1)==HIGH){newtime=millis();
    if(newtime-ptime2>=1000){
    Serial.println("Maximum temperature is:"+String(maxT)+"c  and minimum is:"+String(miniT)+" Time::"+maxTime);
    Serial.println("Maximum Humidity is:"+String(maxH)+"%  and minimum is:"+String(miniH)+" Time::"+maxTime);}
    ptime2=newtime;
    }
  }
  else if(inf==3){
    Serial.println("Data dumping activated..");
    while(digitalRead(s1)==HIGH){newtime=millis();
      dumps();}
  }
  }
