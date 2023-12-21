#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6O56q5Fbe"
#define BLYNK_TEMPLATE_NAME "DataV"
#define BLYNK_AUTH_TOKEN "F7vvzUdpkK_SxeIOrRsBlHn_Q3_LWmma"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT11.h>

DHT11 dht11(13);

char ssid[] = "KylieMinogue";
char pass[] = "abcdabcd";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  int temperature = dht11.readTemperature();
  Serial.println(temperature);
  Blynk.run();
  Blynk.virtualWrite(V1,temperature);
  delay(3000);
}

