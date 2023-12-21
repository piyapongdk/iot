#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DHT11.h>

DHT11 dht11(13);
const char *ssid = "ESP8266-AP";
const char *password = "123456789";

ESP8266WebServer server(80);

void handleRoot() {
  String s = "<h1>Welcome</h1>";
  s = s + "<a href='/readHumid'>Read Humidity</a>";
  server.send(200, "text/html", s);
}

void readHumid(){
  int humidity = dht11.readHumidity();
  String t = "Humidity: " + String(humidity) + "%";
  server.send(200, "text/html", t);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/readHumid", readHumid);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
