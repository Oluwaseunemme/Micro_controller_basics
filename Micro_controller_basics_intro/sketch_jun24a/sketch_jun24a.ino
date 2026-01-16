#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
//Canvas size
const int a = 128;
const int b = 64;
const int reset = -1;
int info,old_size=0;
String dots=".";
String infos;
// Create display
Adafruit_SSD1306 display(a, b, &Wire, reset);
#define ledpin 4
//Put your WiFi Credentials here
const char* ssid = "Emmes pixel";
const char* password = "Emmanuel282003#";
String led_state="0";

//URL Endpoint for the API
String url_get= "https://api.telegram.org/bot7607920516:AAFRCranzKa6kVmbQ_9MeKDG6CVOD3vCOFs/getUpdates?chat_id=?707252389";

// Replace with your location Credentials
void display_text(String text, int x, int y) {
  display.setTextSize(1);       // Normal 1:1 pixel scale
  display.setTextColor(WHITE);  // Draw white text
  display.setCursor(x, y);      // Start at top-left corner
  display.println(text);
  display.display();
}
HTTPClient http;

String get_update(){
      String JSON_Data = http.getString();
      //Serial.println(JSON_Data);
      //Retrieve some information about the weather from the JSON format
      DynamicJsonDocument doc(2048); //helps create storage for incoming json document
      deserializeJson(doc, JSON_Data);//helps deserialize the incoming string into json format for breadown and accesing
      JsonObject obj = doc.as<JsonObject>();

      int update=obj["result"].size();//this helps get the current size of the incoming list..
      if(update>old_size){ 
        display.clearDisplay();
        old_size=update;
        infos =obj["result"][update-1]["message"]["text"].as<const char*>();
        display_text("Data:"+String(infos) ,0 ,1);
        display_text("Size:"+String(update) ,0 ,15);
        action();
        return infos;
      }
}
void post_update(String text){
   Serial.println("Post_info:"+text);
   display.clearDisplay();
   display_text("Info:"+text, 1, 1 );
   DynamicJsonDocument doc2(2048); //doc2 object
   doc2["info1"]="";//your infomation to send 
   doc2["info2"]= ;//second info to post
   String jsonString;//string to store text for post
   serializeJson(doc2, jsonString);//converting the stored json format info stored in doc2 to string for post
   http.begin("your post link here");
   http.addHeader("Content-Type", "application/json"); 

  // Send the request without specifying headers
  int httpResponseCode = http.POST(jsonString);
  if (httpResponseCode > 0) {
    Serial.print("HTTP request sent.....Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  }
}
void action(){
    
}
void setup() {
  Serial.begin(115200);
  pinMode(ledpin ,OUTPUT);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.display();
  delay(500);
  display.clearDisplay();
  delay(200);
  Serial.begin(115200);

  // Setup LCD with backlight and initialize
  // We start by connecting to a WiFi network
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display_text("Connecting"+dots,1,1);
    dots+=".";
    display.clearDisplay();
  }
   display_text("Connected to:"+String(ssid),1,1);
   delay(1000);
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    //Set HTTP Request Final URL with Location and API key information
    http.begin(url_get);

    // start connection and send HTTP Request
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      //Read Data as a JSON string
      get_update();      
    }
     else {
      Serial.println("Error!");
    }
    http.end();
  }  
  //Wait for 30 seconds
  delay(5000);
}