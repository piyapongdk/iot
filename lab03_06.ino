#include <DHT11.h>
DHT11 dht11(13);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int humidity = dht11.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("  %");
  delay(1000);
}
