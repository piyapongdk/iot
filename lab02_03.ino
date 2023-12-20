int potPin = 0;

void setup() {
  pinMode(potPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);
  int newValue = map(sensorValue,0,1023,500,5000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(newValue);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(newValue);
}
