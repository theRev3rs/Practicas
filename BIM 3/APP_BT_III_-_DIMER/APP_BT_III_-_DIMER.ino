
/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: TICS
 * Nombres: RICARDO ESTRADA, CARLOS QUIM
 * CARNES: 2019553 , 2019172
 * Proyecto: APP BLUETOOTH III
 * 
 */

//Librerias
#include <Ticker.h>

//Directivas
#define dimerOut 3
#define dimerOn 6

//Variables
byte intensidad_foco;
bool btconectado = false;
String entradabt;
int luz_int = 6400; 
int mot_int=6450;
int time_int=0;
byte dimersignal = 0;

//Funciones
void potencia_foco();

//Constructores
 Ticker ISR_cero(potencia_foco, 16);

void setup() {
  Serial.begin(9600);
  pinMode(dimerOut, OUTPUT);
  ISR_cero.start();
}

void loop() {
  ISR_cero.update();
  if(Serial.available()>0 && btconectado == false){
    entradabt = Serial.readStringUntil('\n');
      if(entradabt == String("Conectado")){
        btconectado == true;
        }
    }
  if(Serial.available()>0 && btconectado == true){
    intensidad_foco = Serial.parseInt();
    dimersignal = map(intensidad_foco, 0, 255, 1, 8);
      if(intensidad_foco > 0){
        digitalWrite(dimerOn, HIGH);
        }
      if(intensidad_foco == 0){
        digitalWrite(dimerOn, LOW);
        }
        if(dimersignal == 1 ) luz_int = 6300;   // Los 8 saltos del Deslizador 1 (Dimmer)
        if(dimersignal == 2 ) luz_int = 6100;  
        if(dimersignal == 3 ) luz_int = 5200;  
        if(dimersignal == 4 ) luz_int = 4900;  
        if(dimersignal == 5 ) luz_int = 4500; 
        if(dimersignal == 6 ) luz_int = 4100; 
        if(dimersignal == 7 ) luz_int = 3500;  
        if(dimersignal == 8 ) luz_int = 3000; 
    }
}

void potencia_foco(){
  delayMicroseconds(luz_int); 
  digitalWrite(3,HIGH);
  delayMicroseconds(100);
  digitalWrite(3,LOW);
  }
