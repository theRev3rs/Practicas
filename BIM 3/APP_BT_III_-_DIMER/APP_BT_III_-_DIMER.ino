
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


//Directivas
#define dimerOut 5
#define cruce_cero 2

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
 

void setup() {
  attachInterrupt(digitalPinToInterrupt(cruce_cero),potencia_foco,RISING);
  Serial.begin(9600);
  pinMode(dimerOut, OUTPUT);
  pinMode(cruce_cero, INPUT);
}

void loop() {
  if(Serial.available()>0 && btconectado == false){
    entradabt = Serial.readStringUntil('\n');
      if(entradabt == String("Conectado")){
        btconectado == true;
        }
    }
  if(Serial.available()>0 && btconectado == true){
    intensidad_foco = Serial.parseInt();
    dimersignal = map(intensidad_foco, 0, 255, 0, 8);
        if(dimersignal == 0 ) luz_int = 7600; 
        if(dimersignal == 1 ) luz_int = 6900;
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
  digitalWrite(dimerOut,HIGH);
  delayMicroseconds(100);
  digitalWrite(dimerOut,LOW);
  }
