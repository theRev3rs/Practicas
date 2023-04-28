/* 
* Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Profe Alejandro Lopez
 * Fecha: 27/04/2023
 * Proyecto: SENSOR DE PARQUEO
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

//caracteres
byte bloque[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
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
  PANTALLA_ESTRADA.createChar(1, bloque);
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
   if( d == 50){
    
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print("                ");
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.setCursor(7,0);
    PANTALLA_ESTRADA.print("50");
    PANTALLA_ESTRADA.setCursor(13,0);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("     LIBRE      ");
  }
  if( d == 30){
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print("                ");
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.setCursor(7,0);
    PANTALLA_ESTRADA.print("30");
    PANTALLA_ESTRADA.setCursor(11,0);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("     CUIDADO    ");
  }
  if( d == 10){
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.print("                ");
    PANTALLA_ESTRADA.setCursor(0,0);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.setCursor(7,0);
    PANTALLA_ESTRADA.print("10");
    PANTALLA_ESTRADA.setCursor(9,0);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.write(1);
    PANTALLA_ESTRADA.setCursor(0,1);
    PANTALLA_ESTRADA.print("      ALTO      ");
  }
  }
