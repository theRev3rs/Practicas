//Librerias
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <OneWire.h>

//Directivas
#define buzz 6
#define pinNeo 3     //Pin al que esta el NeoPixel
#define NUMPIXELS 22 //Cantidad de Neopixeles en la cadena
#define preguntas 22 //Cantidad de preguntas
#define ciclos 5
//Variables
bool respuesta; //Si la respuesta de la pregunta es correcta o incorrecta
int num_pregunta;


//Constructores
Adafruit_NeoPixel pixels(NUMPIXELS, pinNeo, NEO_GRB + NEO_KHZ800); 

//Funciones
int ruleta();  //Elije un numero de pregunta al azar (Nideah como se hace juas juas)
void respoder();   //Muestra la pregunta en el BT espera respuesta y determina si es correcta o incorrecta
void correcta();  //La respuesta dada es correcta
void incorrecta(); //La respuesta es incorrecta

void setup() {
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  num_pregunta = ruleta();
  responder();
}

int ruleta(){
    int num_random;
//  num_random = random(1,preguntas); //Activar cuando ya esten las preguntas ajsjasjaj
    num_random = 1; //Desactivar cuando no hayan preguntas juas juas
    return num_random; //Regresa el numero random
  }

void responder(){
  switch(num_pregunta){
    case 1:
    Serial.print("Y si sirve");
    if(Serial.available()>0){
      String respondiendo = Serial.readStringUntil('\n');
      if(respondiendo == String("Si")){
        correcta();
      }
      if(respondiendo == String("No")){
        incorrecta();
      }
      }
    case 2:
    Serial.print("Apoco tan bueno");
    if(Serial.available()>0){
      String respondiendo = Serial.readStringUntil('\n');
      if(respondiendo == String("Mextraña araña")){
        correcta();
      }
      if(respondiendo == String("Lo saque de gugul")){
        incorrecta();
      }
      }
    case 3:
    Serial.print("Que pro que sos estrada");
    if(Serial.available()>0){
      String respondiendo = Serial.readStringUntil('\n');
      if(respondiendo == String("Tengo hambre")){
        correcta();
      }
      if(respondiendo == String("Ni deah")){
        incorrecta();
      }
      }
  }
  }
void correcta(){
  for(int i = 0; i < ciclos; i++ ){    //Patron de Neopixeles 
    pixels.setPixelColor(num_pregunta, pixels.Color(0, 255, 0));
  pixels.show();
  delay(100);
  pixels.setPixelColor(num_pregunta, pixels.Color(0, 127, 0));
  pixels.show();
  delay(100);
    }
  pixels.setPixelColor(num_pregunta, pixels.Color(0, 0, 0));
  pixels.show();
  delay(100);
  }
void incorrecta(){
  tone(buzz, 440, 50);  //Aca iria la melodia si alguien la hubiera subido juas juas
  delay(100);
  noTone(buzz);
  delay(1000);
}
