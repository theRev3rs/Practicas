//Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador
#define direccion_lcd 0x3F //Direccion del I2C del LCD
#define filas 2
#define columnas 16
#define lectura_R A0    //Lectura de entrada

//Variables
int Ven = 5; //Voltaje de entrada
float Vsa;   //Voltaje de salida
float R_Ref = 10000;
float Medicion_R;
float ref;

//Funciones
int medicion_resistencia();

//Constructor
LiquidCrystal_I2C PANTALLA(direccion_lcd, columnas, filas); 

  void setup() {
    pinMode(lectura_R, INPUT);
     PANTALLA.init();
  PANTALLA.backlight();
  // put your setup code here, to run once:

}

void loop() {
  PANTALLA.setCursor(0,0);
  PANTALLA.print("  Resistencia   ");
  unsigned int ohms = medicion_resistencia();
  PANTALLA.setCursor(0,1);
  PANTALLA.print("    ");
  PANTALLA.print(ohms);
  PANTALLA.print("  ohms      ");
  
}
int medicion_resistencia(){
    ref = analogRead(lectura_R) * Ven;
    Vsa = (ref)/1024;
    ref = (Ven/Vsa)-1;
    Medicion_R = R_Ref  * ref;
    return Medicion_R;
    }
  
