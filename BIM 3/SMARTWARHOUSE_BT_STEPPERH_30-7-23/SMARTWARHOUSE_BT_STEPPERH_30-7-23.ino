/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: RICARDO ESTRADA , WOLF SALGUERO, CARLOS QUIM, CRISTIAN ORELLANA
 * GRUPO: 1
 * Proyecto: SmartWarehouse
 */

//Librerias
#include <SoftwareSerial.h>
#include <Stepper.h>

//Directivas
#define pinServoPush 15     //Pin del piston
#define pinServoPull 14     //Pin del piston 

#define BTRXD 6   //Pines del Módulo BT
#define BTTXD 7   //Pines del Módulo BT

#define RELE_BANDA 12 //Pines del puente H

#define pinStep1 5 //Pines del Stepper
#define pinStep2 4 //Pines del Stepper
#define pinStep3 3 //Pines del Stepper
#define pinStep4 2 //Pines del Stepper

#define pos1 35     //Pasos para la Torre 1
#define pos2 650    //Pasos para la Torre 2
#define pos3 1300   //Pasos para la Torre 3
#define pos4 1920   //Pasos para la Torre 4
#define pos5 2590   //Pasos para la Torre 5

//Variables
String entrada_bluetooth;  //String que almacena el texto recibido por bluetooth
int cantidad;           //Variable para la cantidad de producto
int posproducto;       //Variable con valor cambiante para la posicion de los pedidos

byte stock1 = 6;       //Cantidad de producto inicial 1
byte stock2 = 6;       //Cantidad de producto inicial 2
byte stock3 = 6;       //Cantidad de producto inicial 3
byte stock4 = 6;       //Cantidad de producto inicial 4
byte stock5 = 6;       //Cantidad de producto inicial 5

bool btconectado = false;  //Variable booleana que determina si esta conectado el bluetooth o no

int tiempoentrega;  //Variable cambiante del tiempo para que el producto llegue al final de la banda

int tiempo1 = 3800; //Tiempo del producto 1
int tiempo2 = 2800; //Tiempo del producto 2
int tiempo3 = 1800; //Tiempo del producto 3
int tiempo4 = 800;  //Tiempo del producto 4
int tiempo5 = 100;  //Tiempo del producto 5

//Constructores
SoftwareSerial BT(BTRXD, BTTXD);  //Constructor Módulo Bluetooth
Stepper Act_lineal(2048, pinStep1, pinStep2, pinStep3 , pinStep4);  //Constructor del stepper

void setup() {
  Serial.begin(9600);   //Inicia la comunicacion Serial
  BT.begin(9600);    //Inicia la comunicacion Bluetooth
  Act_lineal.setSpeed(10);  //Velocidad del actuador lineal
  pinMode(RELE_BANDA, OUTPUT);      //Define el pin de entrada 1 del Puente H como salida
  pinMode(pinServoPush, OUTPUT);    //Define el pin para empujar del piston
  pinMode(pinServoPull, OUTPUT);    //Define el pin para empujar del piston
  digitalWrite(pinServoPush, HIGH); //El rele usa logica negada por lo que para estar apagados se escribe en "HIGH"
  digitalWrite(pinServoPull, HIGH); //
  digitalWrite(pinStep1, OUTPUT);   //PIN del Stepper
  digitalWrite(pinStep2, OUTPUT);   //PIN del Stepper
  digitalWrite(pinStep3, OUTPUT);   //PIN del Stepper
  digitalWrite(pinStep4, OUTPUT);   //PIN del Stepper
  Serial.println("Sistema Encendido... Esperando Conexion Bluetooth");
}

void loop() {
  if((BT.available()>0) && (btconectado == false)){   //Determinamos si la app esta conectada 
    String inicio = BT.readStringUntil('\n'); 
  if(inicio== String("Conectado")){   //Texto que la app envia cuando se conecta al Modulo HC-06
    Serial.println("Bluetooth Conectado");
    btconectado = true;  //El bluetooth esta conectado y listo
    }
    }
    while((BT.available()>0) && (btconectado == true)){    //Leemos la entrada del módulo bluetooth
    entrada_bluetooth = BT.readStringUntil('\n'); //Lee instrucciones en texto
    Serial.println(entrada_bluetooth);
    delay(500);
    cantidad = BT.parseInt();   //Lee los enteros por separado
    
    if(entrada_bluetooth == String("Refrescar")){     //Si se rellenaron las estanterias reestablece el stock
      stock1 = 6;
      stock2 = 6;
      stock3 = 6;
      stock4 = 6;
      stock5 = 6;
      }
      if(entrada_bluetooth == String("Desconectado")){    //Si se desconecto desde la app
      Serial.println("Bluetooth Desconectado");
      btconectado == false;
      }

      //Opciones de producto para aplicar los valores necesarios para la entrega
    if(entrada_bluetooth == String("Producto1")){
      if(cantidad <= stock1){
    stock1 = stock1 - cantidad;
    posproducto = pos1;
    tiempoentrega = tiempo1;
    actuador_lineal();
    }
    else{
      Serial.println("Cantidad no disponible");
      }
    }
    if(entrada_bluetooth == String("Producto2")){
      if(cantidad <= stock2){
    stock2 = stock2 - cantidad;
    posproducto = pos2;
    tiempoentrega = tiempo2;
    actuador_lineal();
    }
    else{
      Serial.println("Cantidad no disponible");
      }
    }
    if(entrada_bluetooth == String("Producto3")){
      if(cantidad <= stock3){
    stock3 = stock3 - cantidad;
    posproducto = pos3;
    tiempoentrega = tiempo3;
    actuador_lineal();
    }
    else{
      Serial.println("Cantidad no disponible");
      }
    }
    if(entrada_bluetooth == String("Producto4")){
      if(cantidad <= stock4){
    stock4 = stock4 - cantidad;
    posproducto = pos4;
    tiempoentrega = tiempo4;
    actuador_lineal();
    }
    else{
      Serial.println("Cantidad no disponible");
      }
    }
    if(entrada_bluetooth == String("Producto5")){
      if(cantidad <= stock1){
    stock5 = stock5 - cantidad;
    posproducto = pos5;
    tiempoentrega = tiempo5;
    actuador_lineal();
    }
    else{
      Serial.println("Cantidad no disponible");
      }
    }
    }
    }
    
void actuador_lineal(){    //Funcion para la posicion y despacho del producto
      {
      avanzar_banda();   //      Funcion para activar la banda
      Serial.print("Despachando: ");
      Serial.println(cantidad);
                        //      Actuador Lineal ( Posicion )
        Act_lineal.step(posproducto);
      delay(100);
      for(int i = 0; i < cantidad; i++){
      piston();
      }
        Act_lineal.step(-posproducto);
      delay(tiempoentrega); //depende cuanto tarda cada paquete en llegar al final
      detener_banda();    //    Funcion para apagar la banda
    }     //Fin producto
    }      

    
void avanzar_banda(){
    digitalWrite(RELE_BANDA, HIGH);  //Activa el rele de la banda
    delay(500);
    }
void detener_banda(){
    delay(500);
    digitalWrite(RELE_BANDA, LOW);  //Desactiva el rele de la banda
    }
void piston(){
      digitalWrite(pinServoPush, LOW);   //Empuja
      delay(650);
      digitalWrite(pinServoPush, HIGH);  //Se detiene
      delay(250);
      digitalWrite(pinServoPull, LOW);   //regresa
      delay(650);
      digitalWrite(pinServoPull, HIGH);  //Se detiene
      Serial.println("Producto Despachado");
      delay(1000);  //Tiempo para que otro producto este listo para ser entregado
    }
