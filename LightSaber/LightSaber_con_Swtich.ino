#include <Adafruit_NeoPixel.h>
#define pwr 13
#define colr 3
#define sound 2
#define pwr2 5
#define NUMPIXELS 5
int estado = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, colr, NEO_GRB + NEO_KHZ800);
void setup() {
pixels.begin();
pinMode(pwr, INPUT);
pinMode(pwr2, INPUT);
}
void loop() {
  if(digitalRead(pwr)==1){
    estado = 1;
    }
  if(digitalRead(pwr)==0){
    estado = 2;
    }
  if(digitalRead(pwr2)==1){
    tone(sound, 60, 10);
    } 
  switch(estado){
 case 1:
  for(int i=0; i<=NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  pixels.show();
  if(digitalRead(pwr2)==1){
    tone(sound, 60, 10);
    }
  delay(50);
  }
  
  break;
 case 2:
  for(int i=60; i>=0; i--) {
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
  delay(50);
  }
  break;
 }
}
