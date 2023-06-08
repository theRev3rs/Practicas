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

//lIBRERIAS
#include <Ticker.h>

//Directivas de preprocesador
#define pot A0
#define G 6
#define B 3
#define R 5

//Variables
int intensidad;
int posicion;
int intervalo;

//Funciones
int tiempo();
void secuencia();
void ISR_lectura(void);

//Constructor
Ticker ISR_obtener_intervalo(ISR_lectura, 1); //Cada 1ms obtiene el valor del potenciometro

void setup() {
  ISR_obtener_intervalo.start();
  Serial.begin(9600);
 pinMode(R, OUTPUT);
 pinMode(G, OUTPUT);
 pinMode(B, OUTPUT);
 pinMode(pot, INPUT);
}

void loop() {
  secuencia();
  ISR_obtener_intervalo.update();
}
int tiempo(){
  intensidad = analogRead(pot);
  posicion = map(intensidad, 0, 1023, 100, 1000);
  return posicion;
  }
 void ISR_lectura(){
    intervalo = tiempo();
    Serial.println(intervalo);
    }
    
  void secuencia(){
//    R: 174 G: 92 B: 230
    analogWrite(R, 174);
    analogWrite(G, 92);
    analogWrite(B, 230);
    delay(intervalo);
    //    R: 255 G: 255 B: 255
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
    delay(intervalo);
     //    R: 0 G: 255 B: 255
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 255);
    delay(intervalo);
//     R: 189 G: 174 B: 20
    analogWrite(R, 189);
    analogWrite(G, 174);
    analogWrite(B, 20);
    delay(intervalo);
    //R: 225 G: 87 B: 35
    analogWrite(R, 255);
    analogWrite(G, 87);
    analogWrite(B, 35);
    delay(intervalo);
    }
