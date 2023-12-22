#include <TridentTD_LineNotify.h>
#include <DHT11.h>

#define SSID        "KylieMinogue"
#define PASSWORD    "abcdabcd"
#define LINE_TOKEN  "1Kg86Xcj090auv8bcBBvdxXlnCiIIBosMMOoaKb9"

DHT11 dht11(13);

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  int temperature = dht11.readTemperature();
  if(temperature > 25){
    String s = "อุณหภูมิ " + String(temperature) + "° เกินที่กำหนดไว้";
    LINE.notify(s);
  }
  delay(10000);
}
