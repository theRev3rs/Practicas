#include <Adafruit_NeoPixel.h>
#define pwr 13
#define colr 3
#define sound 2
#define NUMPIXELS 5
Adafruit_NeoPixel pixels(NUMPIXELS, colr, NEO_GRB + NEO_KHZ800);
void setup() {
pixels.begin();
pinMode(pwr, INPUT);
}
void loop() {
  pixels.begin();
 if (digitalRead(pwr)==1)
 {
  for(int i=0; i<=NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  pixels.show();
  tone(sound, 60, 5);
  delay(50);
  }
 }else if(digitalRead(pwr)==0){
  for(int i=60; i>=0; i--) {
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
  tone(sound, 50, 10);
  delay(50);
  }
 }
}
