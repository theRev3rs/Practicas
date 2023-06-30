/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: RICARDO ESTRADA , CARLOS QUIM, CRISTIAN ORELLANA, WOLF SALGUERO
 * GRUPO: 1
 * Proyecto: SmartWarehouse
*/


//Librerias
#include <Stepper.h>
#include <Servo.h>
#include <SoftwareSerial.h>

//Directivas
#define pinServo 3     //Pin del Servo
#define pinStep1 9    //Pines del Stepper
#define pinStep2 10    //Pines del Stepper
#define pinStep3 11    //Pines del Stepper
#define pinStep4 12    //Pines del Stepper
#define RXBT 5    //Pin RX del Modulo BT
#define TXBT 6    //Pin TX del Modulo BT

//Variables
char item;
int cantidad = 1;
int pos1 = 2000;   //Pasos para llegar y volver de la posicion 1 al Origen
int pos2 = 3000;   //Pasos para llegar y volver de la posicion 2 al Origen
int pos3 = 5000;  //Pasos para llegar y volver de la posicion 3 al Origen
int pos4 = 6000;  //Pasos para llegar y volver de la posicion 4 al Origen
int pos5 = 7000;  //Pasos para llegar y volver de la posicion 5 al Origen
int hold = 0;      //Angulo donde el Piston no obstruye
int push = 180;    //Angulo donde el piston empuja

//Constructores
Stepper act_line(2048,pinStep1,pinStep3,pinStep2,pinStep4);   // Constructor del Stepper
Servo piston;      // Constructor del Servo
SoftwareSerial BT_HC06(RXBT, TXBT);     // Constructor del Modulo BT
void setup() {
Serial.begin(19200);
BT_HC06.begin(19200);
  act_line.setSpeed(5);     //Define la velocidad del Stepper
  piston.attach(pinServo);  //Define el pin del servo
  piston.write(hold);       //Coloca el servo en posicion de reposo
}

void loop() {
  lectura_bt();
}

int lectura_bt(){
  if( (BT_HC06.available())>0){  //  Si hay un caracter leible en el modulo BT
    item = BT_HC06.parseInt();      //Extrae el Primer Digito
    cantidad = BT_HC06.parseInt();  //Extrae el segundo digito
  //Aca se define la cantidad de productos y el tipo que se deben entregar
  delay(1000);
  posicion_empuje();
  }
}
void posicion_empuje(){
  if( item == 1 ){
    
    act_line.step(pos1); //Moverse a la posicion del item 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos items se necesiten
    piston.write(push); //Empuja
    delay(200);
    piston.write(hold); //Regresa
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    Serial.println("Producto 1 despachado");
    }
    act_line.step(-pos1); //Se mueve de regreso al origen
    }
  if( item == 2 ){
    act_line.step(pos2); //Moverse a la posicion del item 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos items se necesiten
    piston.write(push); //Empuja
    delay(200);
    piston.write(hold); //Regresa
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    Serial.println("Producto 2 despachado");
    }
    act_line.step(-pos2); //Se mueve de regreso al origen
    }
  if( item == 3 ){
    act_line.step(pos3); //Moverse a la posicion del item 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos items se necesiten
    piston.write(push); //Empuja
    delay(200);
    piston.write(hold); //Regresa
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    Serial.println("Producto 3 despachado");
    }
    act_line.step(-pos3); //Se mueve de regreso al origen
    }

  if( item == 4 ){
    act_line.step(pos4); //Moverse a la posicion del item 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos items se necesiten
    piston.write(push); //Empuja
    delay(200);
    piston.write(hold); //Regresa
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    Serial.println("Producto 4 despachado");
    }
    act_line.step(-pos4); //Se mueve de regreso al origen
    }
  if( item == 5 ){
    act_line.step(pos5); //Moverse a la posicion del item 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos items se necesiten
    piston.write(push); //Empuja
    delay(200);
    piston.write(hold); //Regresa
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    Serial.println("Producto 5 despachado");
    }
    act_line.step(-pos5); //Se mueve de regreso al origen
    }
    else{
      Serial.println("Invalido");
      }
  }
