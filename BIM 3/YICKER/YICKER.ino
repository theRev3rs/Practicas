/*
*Fundacion Kinal
*Centro Educativo Tecnico Laboral Kinal
*Electronica
*Grado: Quinto
*Seccion: A
*Cuerso: Taller de Electronica Digital y Reparacion de Computadoras I
*Nombre: Ricardo Estrada
*Carnet: 2019553
*Proyecto: Uso de interrupciones externas
*/
//Librerias
#include <Ticker.h> //Esta libreria permite hacer uso del timer

//Directivas de preprocesador
#define led_arduino 13 //Led onboard del Arduino

//Variables
volatile static bool estado_led;

//Funciones de ISR
void ISR_led(void);

//Constructor
Ticker ISR_accion_led(ISR_led, 500); //Cada 3 segundos se encendera/apagara el Led del pin 3
void setup() {
Serial.begin(19200);
Serial.println("Uso del Timer");
pinMode(led_arduino, OUTPUT);
digitalWrite(led_arduino, LOW);
ISR_accion_led.start(); //Iciciando la interrupcion que se repetira cada N segundos
estado_led = LOW;
}
void loop() {
  ISR_accion_led.update();
}
void ISR_led(){
  estado_led = digitalRead(led_arduino);
digitalWrite(led_arduino, !estado_led);
 Serial.println("Interrupcion"); 
}
