#include <DHT11.h>
DHT11 dht11(13);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int temperature = dht11.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);
  
  int humidity = dht11.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("  %");
  delay(1000);
}
