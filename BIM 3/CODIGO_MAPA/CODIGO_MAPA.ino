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
int conteo = 1;

//Constructores
Adafruit_NeoPixel pixels(NUMPIXELS, pinNeo, NEO_GRB + NEO_KHZ800); 

//Funciones
int ruleta();  //Elije un numero de pregunta al azar (Nideah como se hace juas juas)
void responder();   //Muestra la pregunta en el BT espera respuesta y determina si es correcta o incorrecta
void correcta();  //La respuesta dada es correcta
void incorrecta(); //La respuesta es incorrecta

void setup() {
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println("¿Estas Listo?");
  if(Serial.available()>0){
      String empezar = Serial.readStringUntil('\n');
      if(empezar == String("Si")){
        pixels.clear();
        delay(50);
        num_pregunta = ruleta();
        responder();
      }
  else{
    if(conteo<22){
    conteo++;
      }
    if(conteo>22){
    conteo = 1;
      }    //patron de espera
    pixels.setPixelColor(conteo, pixels.Color(0, 255, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(i-1, pixels.Color(0, 0, 255));
    pixels.show();
    delay(50);
    pixels.setPixelColor(i+1, pixels.Color(255, 0, 0));
    pixels.show();
    delay(50);
    
    }
}
}

int ruleta(){
    int num_random;
//  num_random = random(1,preguntas); //Activar cuando ya esten las preguntas ajsjasjaj ( No Hate )
    num_random = random(1, 4); //Activar cuando no hayan preguntas juas juas
    return num_random; //Regresa el numero random
  }

void responder(){
  switch(num_pregunta){
    case 1:
    Serial.println("Y si sirve");
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
    Serial.println("Apoco tan bueno");
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
    Serial.println("Que pro que sos estrada");
    if(Serial.available()>0){
      String respondiendo = Serial.readStringUntil('\n');
      if(respondiendo == String("Tengo hambre")){
        correcta();
      }
      if(respondiendo == String("Ni deah")){
        incorrecta();
      }
      }
    case 4:
    Serial.println("Y si spider-man 2099 es Mephisto?");
    if(Serial.available()>0){
      String respondiendo = Serial.readStringUntil('\n');
      if(respondiendo == String("Se hizo canon")){
        correcta();
      }
      if(respondiendo == String("Eso no es parte del canon")){
        incorrecta();
      }
      }  
  }
  }
void correcta(){
  for(int i = 0; i < ciclos; i++ ){    //Patron de Neopixeles cuando se contesta bien
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
  tone(buzz, 440, 50);  //Aca iria la melodia si alguien la hubiera subido juas juas ( No Hate )
  delay(100);
  noTone(buzz);
  delay(1000);
}
