/* 
* Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Profe Alejandro Lopez
 * Fecha: 27/04/2023
 * Proyecto: LCD por medio de I2C
 */


//Librerias 
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C


//Directivas de preprocesador
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger 16
#define echo 15
#define alarma 13
int d;
//Constructor
LiquidCrystal_I2C PANTALLA_ESTRADA(direccion_lcd, columnas, filas);


void setup()
{
  Serial.begin(9600);
  for(int i=2; i<=11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(alarma ,OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  PANTALLA_ESTRADA.init();
  PANTALLA_ESTRADA.backlight();
}


void loop()
{
  Serial.println(d);
  medicion();
  alerta();
}
int medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(50);
  return d;
}
void alerta(){
   if( d > 45){
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print("FUERA DE ALCANCE");
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("ESPACIO PRIVADO ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(alarma, LOW);
  }
  if( d < 45 && d > 30){
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print(" ACERCANDOSE A  ");
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("ESPACIO PRIVADO ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(alarma, LOW);
  }
  if( d < 30 && d > 15){
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print("   PRECAUCION   ");
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("ESPACIO PRIVADO ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(alarma, HIGH);
    delay(5000);
    digitalWrite(alarma, LOW);
  }
    
    
  if( d < 15 && d > 0){
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print("   INVADIENDO   ");
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("ESPACIO PRIVADO ");
    digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    digitalWrite(alarma, HIGH);
    delay(10000);
    digitalWrite(alarma, LOW);
      }
      else {
        digitalWrite(alarma, LOW);
        }
  }
