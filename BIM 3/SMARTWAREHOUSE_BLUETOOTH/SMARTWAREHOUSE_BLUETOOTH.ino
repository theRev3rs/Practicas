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
#define BTRXD 6   //Pines del Módulo BT
#define BTTXD 7   //Pines del Módulo BT
#define IN1 8 //Pines del puente H
#define IN2 9 //Pines del puente H
#define pinStepdir 10    //Pines del Stepper
#define pinStep 11 //Pines del Stepper
#define ENA A0  //Pin Analogico para regular la velocidad del Puente H
#define pos1 440    //Pasos para la Torre 1
#define pos2 880    //Pasos para la Torre 2
#define pos3 1320   //Pasos para la Torre 3
#define pos4 1760   //Pasos para la Torre 4
#define pos5 2200   //Pasos para la Torre 5

//Variables
String entrada_bluetooth;  //String que almacena el texto recibido por bluetooth
int cantidad;           //Variable para la cantidad de producto
const int push = 180;    //Angulo donde el piston empuja
byte stock1 = 10;       //Cantidad de producto inicial
byte stock2 = 10;       //Cantidad de producto inicial
byte stock3 = 10;       //Cantidad de producto inicial
byte stock4 = 10;       //Cantidad de producto inicial
byte stock5 = 10;       //Cantidad de producto inicial
bool btconectado = false;  //Variable booleana que determina si esta conectado el bluetooth o no

//Constructores
Servo piston;      // Constructor del Servo
SoftwareSerial BT(BTRXD, BTTXD);  //Constructor Módulo Bluetooth

void setup() {
  Serial.begin(9600);   //Inicia la comunicacion Serial
  BT.begin(9600);    //Inicia la comunicacion Bluetooth
  piston.attach(pinServo);  //Define el pin del servo
  piston.write(0);       //Coloca el servo en posicion de reposo
  pinMode(pinStepdir, OUTPUT);    //Define el pin de dirección del Stepper como salida
  pinMode(pinStep, OUTPUT);       //Define el pin de paso del Stepper como salida
  pinMode(IN1, OUTPUT);           //Define el pin de entrada 1 del Puente H como salida
  pinMode(IN2, OUTPUT);           //Define el pin de entrada 2 del Puente H como salida
  pinMode(ENA, OUTPUT);           //Define el pin de Potencia del Puente H como salida
  digitalWrite(IN2, LOW);   //Se deja fijo el pin necesario para que se mueve en una dirección
  analogWrite(ENA ,255);    //Se coloca la potencia del Puente H ( 100% )
}

void loop() {
  if((BT.available()>0) && (btconectado == false)){   //Determinamos si la app esta conectada 
    String inicio = BT.readStringUntil('\n'); 
  if(inicio== String("Conectado")){   //Texto que la app envia cuando se conecta al Modulo HC-06
    Serial.println("Bluetooth Conectado");
    btconectado = true;
    }
    }
    while((BT.available()>0) && (btconectado == true)){    //Leemos la entrada del módulo bluetooth
    entrada_bluetooth = BT.readStringUntil('\n'); 
    Serial.println(entrada_bluetooth);
    delay(500);
    cantidad = BT.parseInt();
    
    if(entrada_bluetooth == String("Refrescar")){     //Si se rellenaron las estanterias
      stock1 = 10;
      stock1 = 10;
      stock1 = 10;
      }
      if(entrada_bluetooth == String("Desconectado")){    //Si se desconecto la app
      Serial.println("Desconectado");
      btconectado == false;
      }
    actuador_lineal();   //Proceso de lectura de la entrada para definir el producto y la cantidad cuando no se detectan instrucciones del menu
    }
    }
  void actuador_lineal(){

      //Para Producto 1
    
    if(entrada_bluetooth == String("Producto1")){     
    if(cantidad <= stock1){
      avanzar_banda();   //      Funcion de la banda
      Serial.println("Despachando");


                        //      Actuador Lineal ( Posicion )
      digitalWrite(pinStepdir, HIGH);
      for(int i = 0 ; i < pos1; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        delay(100);
        }
      delay(100);
                       //      Movimiento del Piston
       for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos productos se necesiten
    
           for(int a = 0; a < push; a++){
           piston.write(a); //Empuja
            delay(10);
            }
           for(int a = push; a > 0; a--){
           piston.write(a); //Regresa
           delay(10);
            }
           Serial.println("Producto 1 despachado");
           delay(700);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
          }
    
          //        Se mueve de regreso al origen
      digitalWrite(pinStepdir, LOW);
      for(int i = 0 ; i < pos1; i++){
         digitalWrite(pinStep, HIGH);
         delay(10);
         digitalWrite(pinStep, LOW);
         delay(10);
        }
        
        stock1 = stock1 - cantidad;
      delay(1000); //depende cuanto tarda cada paquete en llegar al final
      detener_banda();    //    Funcion para apagar la banda
    }
    }      //Fin producto 1

     //Para Producto 2
    
    if(entrada_bluetooth == String("Producto2")){     
    if(cantidad <= stock2){
      avanzar_banda();   //      Funcion de la banda
      Serial.println("Despachando");


                        //      Actuador Lineal ( Posicion )
      digitalWrite(pinStepdir, HIGH);
      for(int i = 0 ; i < pos2; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        delay(100);
        }
      delay(100);
                       //      Movimiento del Piston
       for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos productos se necesiten
    
           for(int a = 0; a < push; a++){
           piston.write(a); //Empuja
            delay(10);
            }
           for(int a = push; a > 0; a--){
           piston.write(a); //Regresa
           delay(10);
            }
           Serial.println("Producto 2 despachado");
           delay(700);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
          }
    
          //        Se mueve de regreso al origen
      digitalWrite(pinStepdir, LOW);
      for(int i = 0 ; i < pos2; i++){
         digitalWrite(pinStep, HIGH);
         delay(10);
         digitalWrite(pinStep, LOW);
         delay(10);
        }
        
        stock2 = stock2 - cantidad;
      delay(2000); //depende cuanto tarda cada paquete en llegar al final
      detener_banda();    //    Funcion para apagar la banda
    }
    }      //Fin producto 2


         //Para Producto 3
    
    if(entrada_bluetooth == String("Producto3")){     
    if(cantidad <= stock3){
      avanzar_banda();   //      Funcion de la banda
      Serial.println("Despachando");


                        //      Actuador Lineal ( Posicion )
      digitalWrite(pinStepdir, HIGH);
      for(int i = 0 ; i < pos3; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        delay(100);
        }
      delay(100);
                       //      Movimiento del Piston
       for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos productos se necesiten
    
           for(int a = 0; a < push; a++){
           piston.write(a); //Empuja
            delay(10);
            }
           for(int a = push; a > 0; a--){
           piston.write(a); //Regresa
           delay(10);
            }
           Serial.println("Producto 1 despachado");
           delay(700);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
          }
    
          //        Se mueve de regreso al origen
      digitalWrite(pinStepdir, LOW);
      for(int i = 0 ; i < pos3; i++){
         digitalWrite(pinStep, HIGH);
         delay(10);
         digitalWrite(pinStep, LOW);
         delay(10);
        }
        
        stock3 = stock3 - cantidad;
      delay(3000); //depende cuanto tarda cada paquete en llegar al final
      detener_banda();    //    Funcion para apagar la banda
    }
    }      //Fin producto 3

    //Para Producto 4
    
    if(entrada_bluetooth == String("Producto4")){     
    if(cantidad <= stock4){
      avanzar_banda();   //      Funcion de la banda
      Serial.println("Despachando");


                        //      Actuador Lineal ( Posicion )
      digitalWrite(pinStepdir, HIGH);
      for(int i = 0 ; i < pos4; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        delay(100);
        }
      delay(100);
                       //      Movimiento del Piston
       for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos productos se necesiten
    
           for(int a = 0; a < push; a++){
           piston.write(a); //Empuja
            delay(10);
            }
           for(int a = push; a > 0; a--){
           piston.write(a); //Regresa
           delay(10);
            }
           Serial.println("Producto 1 despachado");
           delay(700);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
          }
    
          //        Se mueve de regreso al origen
      digitalWrite(pinStepdir, LOW);
      for(int i = 0 ; i < pos4; i++){
         digitalWrite(pinStep, HIGH);
         delay(10);
         digitalWrite(pinStep, LOW);
         delay(10);
        }
        
        stock4 = stock4 - cantidad;
      delay(4000); //depende cuanto tarda cada paquete en llegar al final
      detener_banda();    //    Funcion para apagar la banda
    }
    }      //Fin producto 4

           //Para Producto 5
    
    if(entrada_bluetooth == String("Producto5")){     
    if(cantidad <= stock5){
      avanzar_banda();   //      Funcion de la banda
      Serial.println("Despachando");


                        //      Actuador Lineal ( Posicion )
      digitalWrite(pinStepdir, HIGH);
      for(int i = 0 ; i < pos5; i++){
        digitalWrite(pinStep, HIGH);
        delay(10);
        digitalWrite(pinStep, LOW);
        delay(10);
        delay(100);
        }
      delay(100);
                       //      Movimiento del Piston
       for(int i = 0; i < cantidad; i++){  //Realiza el empuje segun cuantos productos se necesiten
    
           for(int a = 0; a < push; a++){
           piston.write(a); //Empuja
            delay(10);
            }
           for(int a = push; a > 0; a--){
           piston.write(a); //Regresa
           delay(10);
            }
           Serial.println("Producto 1 despachado");
           delay(700);   //Tiempo para que otro producto este en posicion para empujarlo de ser necesario
          }
    
          //        Se mueve de regreso al origen
      digitalWrite(pinStepdir, LOW);
      for(int i = 0 ; i < pos5; i++){
         digitalWrite(pinStep, HIGH);
         delay(10);
         digitalWrite(pinStep, LOW);
         delay(10);
        }
        
        stock5 = stock5 - cantidad;
      delay(5000); //depende cuanto tarda cada paquete en llegar al final
      detener_banda();    //    Funcion para apagar la banda
    }
    }      //Fin producto 5

    }
  void avanzar_banda(){
    digitalWrite(IN1, HIGH);
    delay(500);
    }
   void detener_banda(){
    delay(500);
    digitalWrite(IN1, LOW);
    }
    
