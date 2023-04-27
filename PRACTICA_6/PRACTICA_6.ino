/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: LCD Con ARDUINO
   Dev: Ricardo Estrada
*/
#include <LiquidCrystal.h>
#define RS 2
#define E 7
#define D4 6
#define D5 5
#define D6 4
#define D7 3

LiquidCrystal Pantalla_Estrada (RS,E,D4,D5,D6,D7);

void setup() {
Pantalla_Estrada.begin(16,2);
Pantalla_Estrada.setCursor(0,0);
Pantalla_Estrada.print("RICARDO ESTRADA");
Pantalla_Estrada.setCursor(0,1);
Pantalla_Estrada.print("2019553");
}

void loop(){
}
