//Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador
#define direccion_lcd 0x3F //Direccion del I2C del LCD
#define filas 2
#define columnas 16
#define divisor_v A0    //Lectura de entrada

//Variables


//Funciones
int medicion_resistencia();

//Constructor
LiquidCrystal_I2C PANTALLA(direccion_lcd, columnas, filas); 

  void setup() {
    Serial.begin(9600);
    pinMode(divisor_v, INPUT);
     PANTALLA.init();
  PANTALLA.backlight();
  // put your setup code here, to run once:

}

void loop() {
  PANTALLA.setCursor(0,0);
  PANTALLA.print("  Resistencia   ");
  unsigned long int ohms = medicion_resistencia();
  PANTALLA.setCursor(0,1);
  PANTALLA.print(ohms);
  PANTALLA.print(" ohms          ");
}

 int medicion_resistencia(){
    int lectura = 0;   //Valor de voltaje en el divisor de voltaje
    int Ve = 5;   // Voltaje de entrada
    float VR2 = 0;    //Voltaje en la R2
    float R1 = 10000;     // Valor de la Resistencia de referencia
    float R2 = 0;         // Variable de la resistencia a encontrar
    float relacion = 0;

     lectura = analogRead(divisor_v);
   if(lectura) //Si detecta una resistencia
  {
    relacion = lectura * Ve;  // Opera el valor de la lectura del divisor por el voltaje de alimentacion
    VR2 = (relacion)/1024.0;  //Convierte la relacion a una escala de 0-1023 RAW para calcular el voltaje
  relacion = (Ve/VR2) -1;    // La Operacion deja un entero 1 parasito que se elimina con el -1 para obtener el valor real
    R2= (R1 * relacion)-20;  //Para una mejor precision en la medicion se le resta 20
    Serial.print("Resistancia: ");
    Serial.println(R2);
    return R2;
  } else {   //Si no detecta una resistencia
    Serial.println("Conecta una resistencia");
    return 0;
    }
  }
  
