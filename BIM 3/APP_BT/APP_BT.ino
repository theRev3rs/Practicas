
/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: TICS
 * Nombre: RICARDO ESTRADA
 * CARNE: 2019553
 * Proyecto: Comunicacion BT
 * 
  */
#include <SoftwareSerial.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <OneWire.h>

//Directivas
#define pinTXD_BT 10
#define pinRXD_BT 11
#define pinLed 5
#define pinTemp 6

//Variables
int est_led;
String request;

//Funciones
void Temperature_medition(void);

//Constructores
SoftwareSerial BT_HC06(pinTXD_BT,pinRXD_BT);  //Define los pines del modulo HC-06
OneWire ourWire(pinTemp);  //Pin 5 para el sensor de temperatura
DallasTemperature sensor(&ourWire);

void setup() {
  BT_HC06.begin(9600);
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT),
  sensor.begin(); 
}

void loop() {
  if(BT_HC06.available()){
    est_led = BT_HC06.parseInt();
    
    if(est_led == 1){
      digitalWrite(pinLed, HIGH);
      }
    if(est_led == 0){
      digitalWrite(pinLed, LOW);
      }
    }

    
   if(BT_HC06.available()){
    request = BT_HC06.readStringUntil('\n');
    }

    if(request == String("temp")){
      Temperature_medition();
      }
}

void Temperature_medition(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  BT_HC06.println(temp);
  }
