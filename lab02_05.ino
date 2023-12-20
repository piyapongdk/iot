int potPin = 0;

void setup() {
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue);
  delay(100);
}
