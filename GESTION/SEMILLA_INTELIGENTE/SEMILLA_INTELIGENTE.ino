
/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: ELABORACIÓN Y GESTION DE PROYECTOS
 * Nombres: RICARDO ESTRADA
 * CARNES: 2019553
 * Proyecto: SEMILLA INTELIGENTE
 * 
 */

//Librerias
#include <SHT1x.h>
#include <Ticker.h>

//Directivas
#define humedad_suelo A0 //Sensor Higrometro
#define led_on 4
#define SHT_data A4
#define SHT_sck A5

//Variables y declaraciones
int med_humedad_suelo = 0;
float tempC = 0;   //Valor de la temperatura ambiente
float humidity = 0;   //Valor de la humedad ambiente
bool BT_state = false;
String entrada_BT;

//Funciones
void BT_desconectado();
void BT_conectado();

void Temp_humedad(void);

//Constructores
SHT1x sht15(SHT_data, SHT_sck);
Ticker ISR_obtener_temp(Temp_humedad, 1000); //Cada 1 segundos obtiene la temperatura si el sistema esta activo

void setup() {
  Serial.begin(9600);
  pinMode(led_on, OUTPUT);
  pinMode(humedad_suelo, INPUT);
  ISR_obtener_temp.start(); //Iniciciando la interrupcion que se repetira cada N segundos
}

void loop() {
  ISR_obtener_temp.update();
  
//Indicador BT desconectado
  if(BT_state = false){
  digitalWrite(led_on, !digitalRead(led_on));
  }
  
//  Conectar BT / Activar Sistema
if((Serial.available()>0) && BT_state == false){
    entrada_BT = Serial.readStringUntil('\n');
    if( entrada_BT = String("conectado")){
    BT_state = true;
    digitalWrite(led_on, HIGH);
    }
  }
  

//  Desconectar BT / Desactivar Sistema
if((Serial.available()>0) && BT_state == true){
    entrada_BT = Serial.readStringUntil('\n');
    if( entrada_BT = String("desconectado")){
    BT_state = false;
    }
  }
}

void Temp_humedad(){
  if(BT_state == true){
  tempC = sht15.readTemperatureC();
  humidity = sht15.readHumidity(); 
  med_humedad_suelo = map(analogRead(humedad_suelo), 0, 1023, 0, 100);

  Serial.println("A");
  Serial.println(tempC);
  delay(500);
  Serial.println("B");
  Serial.println(humidity);
  delay(500);
  Serial.println("C");
  Serial.println(med_humedad_suelo);
  delay(500);
  
}
}
