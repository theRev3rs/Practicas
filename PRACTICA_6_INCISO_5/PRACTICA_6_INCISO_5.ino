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
#include <OneWire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#include <DallasTemperature.h>

//Directivas de preprocesador
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
//Constructor
LiquidCrystal_I2C PANTALLA_ESTRADA(direccion_lcd, columnas, filas); 

//caracteres
byte customChar1[] = {
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};
byte customChar2[] = {
  B01000,
  B10100,
  B01000,
  B00111,
  B00100,
  B00110,
  B00100,
  B00100
};
void setup()
{
  
  Serial.begin(9600);
  PANTALLA_ESTRADA.init();
  PANTALLA_ESTRADA.backlight();
  PANTALLA_ESTRADA.createChar(1, customChar1);
  PANTALLA_ESTRADA.createChar(2, customChar2);
}


void loop()
{
  PANTALLA_ESTRADA.setCursor(0,0);
  PANTALLA_ESTRADA.print("   HOLA WAPA    ");
  delay(2000);
  PANTALLA_ESTRADA.setCursor(0,1);
  PANTALLA_ESTRADA.print("  COMO ESTAS?   ");
  delay(2000);
  PANTALLA_ESTRADA.setCursor(0,0);
  PANTALLA_ESTRADA.print("                ");
  PANTALLA_ESTRADA.setCursor(0,1);
  PANTALLA_ESTRADA.print("                ");
  PANTALLA_ESTRADA.setCursor(3,0);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  PANTALLA_ESTRADA.write(1);
  delay(2000);
}
