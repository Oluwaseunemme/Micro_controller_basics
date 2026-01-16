#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <DHT.h>

const char *ssid = "Emmes S10+";
const char *password = "Oluwaseunemme";

WebServer server(80);
DHT dht(5, DHT11);

void handleRoot() {
  char msg[1500];

  snprintf(msg, 1500,
           <html>
 <head>
   <meta charset="utf-8">
   <meta http-equiv="refresh" content="3">
 </head>
 <body>
  <h1 style="background-color:yellow; color:blue; text-"><div style="text-align:center">ESP32 and DHT11 WEB sensor!</div></h1><br/><br/>
 <p><h4><div style="text-align:center"> <img width="50"src="temp.png"/>  <b><span style="color:red">TEMPERATURE VALUE:</span></b><span>t</span></div></h4></p><br/>
 <p><h4><div style="text-align:center"> <img width="50"src="hum.png"/>  <b><span style="color:green">HUMIDITY VALUE:</span></b>h</div></h4></p>
 </body>
</htm>
  
           readDHTTemperature(), readDHTHumidity()                                
          );    
  server.send(200, "text/html", msg);
}

void setup(void) {

  Serial.begin(115200);
  dht.begin();
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}


float readDHTTemperature() {
  // Sensor readings may also be up to 2 seconds
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  else {
    Serial.println(t);
    return t;
  }
}

float readDHTHumidity() {
  // Sensor readings may also be up to 2 seconds
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  else {
    Serial.println(h);
    return h;
  }
}