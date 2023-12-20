int buttonPin = 13;
void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  int button = digitalRead(buttonPin);
  if(button==HIGH){
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
  }
}