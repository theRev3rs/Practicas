int pin=2;
#define bar
void setup() {
for(pin;pin<=12;pin++){
  {
    pinMode(pin, OUTPUT);
  }
}
}
void loop() {
  pin=2;
  for(bar;pin<=11;pin++){
    digitalWrite(pin, HIGH);
    delay(50);
    digitalWrite(pin, LOW);
    }
   pin=11;
  for(bar;pin>=2;pin--){
    digitalWrite(pin, HIGH);
    delay(50);
    digitalWrite(pin, LOW);
}
}
