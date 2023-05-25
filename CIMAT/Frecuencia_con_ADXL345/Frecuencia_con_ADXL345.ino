/*
 * SAIS V1.0.1
 * PRUEBA PARA OBTENER FRECUENCIA DE UN SISMO
 * 25/05/23
 * MAIN CODER: RICARDO ESTRADA
 */
 // librerias
#include <SPI.h>
#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <LiquidCrystal_I2C.h>

//Directivas
#define activado 4
#define direccion_lcd 0x3F
#define filas 2
#define columnas 16

//Variables
float mov;
int freq;
byte sismo1 = 0;
byte sismo2 = 1;
byte sismo3 = 8;
byte sismo4 = 14;
byte sismo5 = 30;


//Constructor
ADXL345 adxl = ADXL345();
LiquidCrystal_I2C PANTALLA(direccion_lcd, columnas, filas); 

//Funciones
float frecuencia_sismo();
int escala_sismica();
void setup() {
  analogReference(EXTERNAL);
   Serial.begin(9600);            
   Serial.println("Iniciar");
   Serial.println();
   adxl.powerOn();           
   adxl.setRangeSetting(16);
   pinMode(activado, OUTPUT);
   digitalWrite(activado, HIGH);
   PANTALLA.init();
  PANTALLA.backlight();
  
}

void loop() {
  PANTALLA.setCursor(0,0);
  PANTALLA.print("  Frecuencia:  ");
  freq = frecuencia_sismo();
  Serial.println(freq);
  PANTALLA.setCursor(5,1);
  PANTALLA.print(freq);
  PANTALLA.print(" Hz  ");
  delay(1000);
  escala_sismica();
}

float frecuencia_sismo(){
  mov = 0;
  int x,y,z;
  float suma_x=0;
  float suma_y=0;
  float suma_z=0;
  adxl.readAccel(&x, &y, &z);
   if( abs(x) < 25 && abs(y) < 25 && abs(z) > 25){ // SAIS EN PLANO X,Y HORIZONTAL
    PANTALLA.setCursor(14,0);
   PANTALLA.print("XY");
    for(int t=0; t<1000; t++){
      adxl.readAccel(&x, &y, &z);
   suma_x = suma_x+abs(x);
   suma_y = suma_y+abs(y);
   delay(1);
   }
   }
   if( abs(x) > 25 && abs(y) < 25 && abs(z) < 25){  // SAIS EN PLANO Y,Z HORIZONTAL
    PANTALLA.setCursor(14,0);
   PANTALLA.print("YZ");
    for(int t=0; t<1000; t++){
      adxl.readAccel(&x, &y, &z);
   suma_x = suma_z+abs(z);
   suma_y = suma_y+abs(y);
   delay(1);
    }
   }
   if( abs(x) < 25 && abs(y) > 25 && abs(z) < 25){  // SAIS EN PLANO X,Z HORIZONTAL
    PANTALLA.setCursor(14,0);
   PANTALLA.print("XZ");
    for(int t=0; t<1000; t++){
      adxl.readAccel(&x, &y, &z);
   suma_x = suma_x+abs(x);
   suma_y = suma_z+abs(z);
   delay(1);
    }
   }
  mov = abs(suma_x+suma_y+suma_z)/1000;
  Serial.print(x);Serial.print(",");Serial.print(y);Serial.print(",");Serial.println(z);
  return mov; 
  }
  
int escala_sismica(){
  if(freq == sismo1){
  Serial.println("Sin Sismo");
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  }
  if(freq >= sismo2 && freq <= sismo3){
  Serial.println("Sismo Categoria 2");
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  }
  if(freq >= sismo3 && freq <= sismo4){
  Serial.println("Sismo Categoria 2");
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  }
  if(freq >= sismo4 && freq <= sismo5){
  Serial.println("Sismo Categoria 2");
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  delay(100);
  digitalWrite(activado, LOW);
  delay(100);
  digitalWrite(activado, HIGH);
  }
  }
