#include <SPI.h>
#include <SD.h>


int datapin=A0,countn,countn2=0;
const int chipSelect = 4;
unsigned long newtime,lastime=0,interval=1;
unsigned long sec=0,hour=12,minute=30,sum=0,info;
int maxold=0,minold=1023,maxval,minval;
String hr,mi,se;

void compare(){
   if(info>maxold){
    maxval=info;
    maxold=info;}
   if(info<minold){
    minval=info;
    minold=info;}
}
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
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

void loop() {
    Serial.println("Enter total record time in seconds.....");
  while(!Serial.available()){}
    countn=Serial.parseInt();
    Serial.print("Entered time is:");
    Serial.println(countn);
  while(1){
   info=analogRead(datapin);
    newtime=millis()/1000;
  if(newtime-lastime>=interval){countn--;
    Serial.print("Time left is:");
    Serial.println(countn);
     sec++;
     lastime=newtime;}
        if(countn==0){Serial.println("Logging done successfully");break;}
   if(sec==60){minute++; sec=0;}
   if(minute==60){hour++;minute=0; if(hour==23){hour=0;}}
//Converting time integers into string for logging onto SD card.
 hr=String(hour);
 mi=String(minute);
 se=String(sec);

compare();


String dataString =String(info);

   // open the file. note that only one file can be open at a time,
   // so you have to close this one before opening another.
  File dataFile = SD.open("datl.txt", FILE_WRITE);

  if (dataFile) {sum+=info; countn2++;
    dataFile.print("Time::");
    dataFile.print(hr);
    dataFile.print(":");
    dataFile.print(mi);
    dataFile.print(":");
    dataFile.print(sec);
    dataFile.print("     ");
    dataFile.print("Data::");
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.print("Time::");
    Serial.print(hour);
    Serial.print("h");
    Serial.print(":");
    Serial.print(minute);
    Serial.print("m");
    Serial.print(":");
    Serial.print(sec);
    Serial.print("s");
    Serial.print("    ");
    Serial.print("Data::");
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {Serial.println("error opening dataloge.txt");}
    }
     
      Serial.println("Do you want to analize the logged file? ");
       Serial.println("INPUT YES/NO.");
    while(!Serial.available()){}
     if(Serial.readString()=="yes"){
      Serial.print("Total operation:");
      Serial.println(countn2);
      Serial.print("Total sum:");
      Serial.println(sum);
        float avg=sum/countn2;
        Serial.print("Average reading of logged data is:");
        Serial.println(avg);
        Serial.print("maximum reading of logged data is:");
        Serial.println(maxval);
        Serial.print("minimum reading of logged data is:");
        Serial.println(minval);
        Serial.println("Enter reset pin to restart...");
        while(1){}
     }
      else if(Serial.readString()=="no"){
        Serial.println("Enter reset pin to restart...");
        while(1){}
      }
}