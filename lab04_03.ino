#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESP8266-AP";
const char *password = "123456789";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>Welcome!!!</h1>");
}

void blinkLED(){
  server.send(200, "text/html", "<h1>Blink!!!</h1>");
  for(int i=0;i<5;i++){
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
  }
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/blink", blinkLED);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
