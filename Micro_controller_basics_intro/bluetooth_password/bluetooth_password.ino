#include <BTAddress.h>
#include <BTAdvertisedDevice.h>
#include <BTScan.h>
#include <BluetoothSerial.h>

#define ledpin 14
#define ledpin2 26
const char master[]="12345";
char data[]="";
BluetoothSerial blt;
void setup() {
  Serial.begin(115200);
  blt.begin("Emmes esp32");
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin2,OUTPUT);}
void loop() {
  if(blt.available()){
  while(blt.available()){
    char c=blt.read();
    data[5]+=c;}
  Serial.println(data);
   if(!strcmp(data,master)){Serial.println("Access granted..");
                    digitalWrite(ledpin,HIGH);
                       delay(3000);
                    digitalWrite(ledpin,LOW);}                    
             else{Serial.println("Access denied..");
                   digitalWrite(ledpin2,HIGH);
                       delay(3000);
                   digitalWrite(ledpin2,LOW);}}
data[5]+="";
}
