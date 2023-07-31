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
#define pinServoPush 5     //Pin del Servo
#define pinServoPull 4
#define BTRXD 6   //Pines del Módulo BT
#define BTTXD 7   //Pines del Módulo BT
#define RELE_BANDA 14 //Pines del puente H
#define pinStep1 13 //Pines del Stepper
#define pinStep2 12 //Pines del Stepper
#define pinStep3 11 //Pines del Stepper
#define pinStep4 10 //Pines del Stepper
#define pos1 20     //Pasos para la Torre 1
#define pos2 650    //Pasos para la Torre 2
#define pos3 1300   //Pasos para la Torre 3
#define pos4 1920   //Pasos para la Torre 4
#define pos5 2590   //Pasos para la Torre 5

//Variables
String entrada_bluetooth;  //String que almacena el texto recibido por bluetooth
int cantidad;           //Variable para la cantidad de producto
int posproducto;
byte stock1 = 6;       //Cantidad de producto inicial
byte stock2 = 6;       //Cantidad de producto inicial
byte stock3 = 6;       //Cantidad de producto inicial
byte stock4 = 6;       //Cantidad de producto inicial
byte stock5 = 6;       //Cantidad de producto inicial
bool btconectado = false;  //Variable booleana que determina si esta conectado el bluetooth o no
int tiempoentrega;
int tiempo1 = 3800;
int tiempo2 = 2800;
int tiempo3 = 1800;
int tiempo4 = 800;
int tiempo5 = 100;


//Constructores
SoftwareSerial BT(BTRXD, BTTXD);  //Constructor Módulo Bluetooth
Stepper Act_lineal(2048, pinStep1, pinStep2, pinStep3 , pinStep4);

void setup() {
  Serial.begin(9600);   //Inicia la comunicacion Serial
  BT.begin(9600);    //Inicia la comunicacion Bluetooth
  Act_lineal.setSpeed(10);  //Velocidad del actuador lineal
  pinMode(RELE_BANDA, OUTPUT);           //Define el pin de entrada 1 del Puente H como salida
  pinMode(pinServoPush, OUTPUT); 
  pinMode(pinServoPull, OUTPUT);
  digitalWrite(pinServoPush, HIGH);
  digitalWrite(pinServoPull, HIGH); 
  digitalWrite(pinStep1, OUTPUT);   //Se deja fijo el pin necesario para que se mueve en una dirección
  digitalWrite(pinStep2, OUTPUT);   //Se deja fijo el pin necesario para que se mueve en una dirección
  digitalWrite(pinStep3, OUTPUT);   //Se deja fijo el pin necesario para que se mueve en una dirección
  digitalWrite(pinStep4, OUTPUT);   //Se deja fijo el pin necesario para que se mueve en una dirección
  Serial.println("Encendido");
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
      stock1 = 6;
      stock2 = 6;
      stock3 = 6;
      stock4 = 6;
      stock5 = 6;
      }
      if(entrada_bluetooth == String("Desconectado")){    //Si se desconecto la app
      Serial.println("Bluetooth Desconectado");
      btconectado == false;
      }
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
void actuador_lineal(){  
      {
      avanzar_banda();   //      Funcion de la banda
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
    }
    }      //Fin producto
void avanzar_banda(){
    digitalWrite(RELE_BANDA, HIGH);
    delay(500);
    }
void detener_banda(){
    delay(500);
    digitalWrite(RELE_BANDA, LOW);
    }
void piston(){
      digitalWrite(pinServoPush, LOW);
      delay(500);
      digitalWrite(pinServoPush, HIGH);
      delay(600);
      digitalWrite(pinServoPull, LOW);
      delay(500);
      digitalWrite(pinServoPull, HIGH);
      Serial.println("Producto Despachado");
      delay(1000);
    }
