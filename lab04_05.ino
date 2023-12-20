#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "ESP8266-AP";
const char *password = "123456789";

ESP8266WebServer server(80);

void handleRoot() {
  String s = "<h1>Welcome</h1>";
  s = s + "<a href='/on'>Turn on </a>";
  s = s + "<br>";
  s = s + "<a href='/off'>Turn off </a>";
  server.send(200, "text/html", s);
}

void onLED(){
  server.send(200, "text/html", "<h1>Turn On!!!</h1>");
  digitalWrite(LED_BUILTIN,LOW);
}

void offLED(){
  server.send(200, "text/html", "<h1>Turn Off!!!</h1>");
  digitalWrite(LED_BUILTIN,HIGH);
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
  server.on("/on", onLED);
  server.on("/off", offLED);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
