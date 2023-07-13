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
#include <Servo.h>
#include <SoftwareSerial.h>

//Directivas
#define pinServo 3     //Pin del Servo
#define pinStepdir 10    //Pines del Stepper
#define pinStep 11 //Pines del Stepper
#define BTRXD 6
#define BTTXD 7

//Variables
String entrada_BT;
int cantidad = 1;
int pos1 = 440;   //Pasos para llegar y volver de la posicion 1 al Origen
int pos2 = 880;   //Pasos para llegar y volver de la posicion 2 al Origen
int pos3 = 1320;  //Pasos para llegar y volver de la posicion 3 al Origen
int pos4 = 1760;  //Pasos para llegar y volver de la posicion 4 al Origen
int pos5 = 2200;  //Pasos para llegar y volver de la posicion 5 al Origen
int push = 180;    //Angulo donde el piston empuja
byte stock1 = 10;
byte stock2 = 10;
byte stock3 = 10;
bool btconectado = false;
bool pedido = false;

//Constructores
Servo piston;      // Constructor del Servo
SoftwareSerial BTESTRADA(BTRXD, BTTXD);
void setup() {
//  Seral.begin(9600);
  Serial.begin(9600);
  piston.attach(pinServo);  //Define el pin del servo
  piston.write(0);       //Coloca el servo en posicion de reposo
  pinMode(pinStepdir, OUTPUT);
  pinMode(pinStep, OUTPUT);
}

void loop() {
  if((Serial.available()>0) && (btconectado == false)){
    String inicio = Serial.readStringUntil('\n'); 
  if(inicio== String("Conectado")){
    Serial.println("BT Conectado");
    btconectado = true;
    }
    }
    while((Serial.available()>0) && (btconectado == true)){
    entrada_BT = Serial.readStringUntil('\n'); 
    Serial.println(entrada_BT);
    delay(300);
    cantidad = Serial.parseInt();
    
    if(entrada_BT == String("Refrescar")){
      stock1 = 10;
      stock1 = 10;
      stock1 = 10;
      }
      if(entrada_BT == String("Desconectado")){
      Serial.println("Desconectado");
      btconectado == false;
      }
    actuador_lineal();
    }
    }
  void actuador_lineal(){
    if(entrada_BT == String("Producto1")){
    if(cantidad <= stock1){
      pedido = true;
//      Funcion de la banda
      Serial.println("Despachando");
      digitalWrite(pinStepdir, HIGH);
      for(int i = 0 ; i < pos1; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        }
//    act_line.step(pos1); //Moverse a la posicion del entrada_BT 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos entrada_BTs se necesiten
    
    for(int a = 0; a < push; a++){
    piston.write(a); //Empuja
    delay(10);
    }
    for(int a = push; a > 0; a--){
    piston.write(a); //Empuja
    delay(10);
    }
    Serial.println("Producto 1 despachado");
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    
    }
//    act_line.step(-pos1); //Se mueve de regreso al origen
 digitalWrite(pinStepdir, LOW);
      for(int i = 0 ; i < pos1; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        }
    stock1= stock1 - cantidad;
    delay(1000); //depende cuanto tarda cada paquete en llegar al final
    pedido = false;
//    Funcion para apagar la banda
    }
    }

    if(entrada_BT == String("Producto2")){
      
    if(cantidad <= stock2){
      Serial.println("Despachando");
//    act_line.step(pos2); //Moverse a la posicion del entrada_BT 1
    delay(100);
    for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos entrada_BTs se necesiten
    
    for(int a = 0; a < push; a++){
    piston.write(a); //Empuja
    delay(10);
    }
    for(int a = push; a > 0; a--){
    piston.write(a); //Empuja
    delay(10);
    }
    Serial.println("Producto 2 despachado");
    delay(500);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
    
    }
//    act_line.step(-pos2); //Se mueve de regreso al origen
    stock1= stock1 - cantidad;
    }
    }
  }

    
