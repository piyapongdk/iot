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
}
