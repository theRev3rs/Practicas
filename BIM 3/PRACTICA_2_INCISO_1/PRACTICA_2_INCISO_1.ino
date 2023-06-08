/*
*Fundacion Kinal
*Centro Educativo Tecnico Laboral Kinal
*Electronica
*Grado: Quinto
*Seccion: A
*Cuerso: Taller de Electronica Digital y Reparacion de Computadoras I
*Nombre: Ricardo Estrada
*Carnet: 2019553
*Proyecto: Regular brillo de un led con potenciometro
*/

//Directivas de preprocesador
#define pot A2
#define led 3

//Variables
int intensidad;
int posicion;
  

void setup() {
 pinMode(led, OUTPUT);
 pinMode(pot, INPUT);
}

void loop() {
  intensidad = analogRead(pot);
  posicion = map(intensidad, 0, 1023, 0, 255);
  analogWrite(led, posicion);
}
