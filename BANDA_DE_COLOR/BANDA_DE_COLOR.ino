  //Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador
#define direccion_lcd 0x3F //Direccion del I2C del LCD
#define filas 2
#define columnas 16
#define retorno_luz A0    //Lectura de entrada
#define R 4
#define G 3
#define B 2


//Variables
byte luz_R;
byte luz_G;
byte luz_B;

//Funciones
int medicion_color();
void comparacion();

//Constructor
LiquidCrystal_I2C PANTALLA(direccion_lcd, columnas, filas); 

  void setup() {
    Serial.begin(9600);
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(retorno_luz, INPUT);
     PANTALLA.init();
  PANTALLA.backlight();
PANTALLA.setCursor(0,0);
  PANTALLA.print("     COLOR:     ");
}

void loop() {
  
  medicion_color();
  comparacion();
}

 int medicion_color(){
  digitalWrite(R, HIGH);
  luz_R = map(analogRead(retorno_luz),0,1024,0,255);
  delay(100);
  digitalWrite(R, LOW);
  delay(200);
  digitalWrite(G, HIGH);
  luz_G = map(analogRead(retorno_luz),0,1024,0,255);
  delay(100);
  digitalWrite(G, LOW);
  delay(200);
  digitalWrite(B, HIGH);
  luz_B = map(analogRead(retorno_luz),0,1024,0,255);
  delay(100);
  digitalWrite(B, LOW);
  delay(200);
  }
  void comparacion(){
    if(luz_R > luz_G && luz_R > luz_B){
      PANTALLA.setCursor(0,1);
  PANTALLA.print("      ROJO      ");
  delay(500);
      } 
    if(luz_G > luz_R && luz_G > luz_B){
      PANTALLA.setCursor(0,1);
  PANTALLA.print("      VERDE     ");
  delay(500);
      }
      if(luz_B > luz_R && luz_B > luz_G){
      PANTALLA.setCursor(0,1);
  PANTALLA.print("      AZUL      ");
  delay(500);
      }
      if(luz_G < 50 && luz_R < 50 && luz_B < 50){
      PANTALLA.setCursor(0,1);
  PANTALLA.print("      NEGRO     ");
  delay(500);
      }
      if(luz_G > 140 && luz_R > 140 && luz_B > 140){
      PANTALLA.setCursor(0,1);
  PANTALLA.print("      BLANCO     ");
  delay(500);
      }
    }
