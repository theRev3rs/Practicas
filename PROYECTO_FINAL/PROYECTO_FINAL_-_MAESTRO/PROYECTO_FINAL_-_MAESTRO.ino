/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Ricardo Estrada, Wolf Salguero, Alexander Racanac, Javier Gonzales
 * Fecha: 23/05/2023
 * Proyecto: Silo de Granos
 */

 // ARDUINO PRINCIPAL
 
 //Librerias 
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#include <Keypad.h>
#include <Servo.h>

//Directivas de preprocesador
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trig 2
#define echo 4
#define cols 4
#define rows 4
#define pin_Servo 3
#define pin0 13
 #define pin1 14
 #define pin2 15
 #define pin3 16
#define BUZZER 17
 int a=135;
 int b=89;

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pines_filas[rows] = {5,6,7,8};
byte pines_columnas[cols] = {9,10,11,12};
//Constructores
LiquidCrystal_I2C PANTALLA_SILO(direccion_lcd, columnas, filas);
Keypad teclado_estrada = Keypad( makeKeymap(keys), pines_filas, pines_columnas, rows,cols);
Servo SERVO_SILO; 

//Variables
float d;
int  capacidad;


//Funciones
int medicion();
int lectura_teclado();
void envio_arduino_secundario();

void setup() {
  Serial.begin(9600); // Inicia comunicación con la consola
  Wire.begin(); // Iniciamos la libreria wire
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); // Configuramos los pines del Ultrasonico
  PANTALLA_SILO.init(); //Iniciamos el LCD
  PANTALLA_SILO.backlight();  //Encendemos la luz del LCD
  SERVO_SILO.attach(pin_Servo); // Inicia el Servo
  SERVO_SILO.write(b);
  pinMode(13, OUTPUT);     // Configuramos los pines para la informacion binaria del Arduino Secundario
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(20, OUTPUT);
}

void loop() {
   lectura_teclado(); // Lee el telcado Matricial
   capacidad = 122 - medicion(); // Mide el contenedor
   envio_arduino_secundario(); // Envio de datos al Arduino secundario
   Serial.println(capacidad);
   if (capacidad <= 100 && capacidad >=0){
    PANTALLA_SILO.setCursor(0,0); //Colocamos el cursor en la posicion (0,0)
     PANTALLA_SILO.print("Almacenado:");  //Imprimimos la palabra "Caracter"
   PANTALLA_SILO.setCursor(11,0);  // Imprime la interfaz
   PANTALLA_SILO.print(capacidad);
   PANTALLA_SILO.print("%  ");
   }
   else if( capacidad < 0){
    PANTALLA_SILO.setCursor(0,0);
    PANTALLA_SILO.print(" Cierre la Tapa ");
    PANTALLA_SILO.setCursor(0,1);
    PANTALLA_SILO.print("                ");
   }
}
int medicion(void){
  long t; 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  PANTALLA_SILO.setCursor(0,1);
  PANTALLA_SILO.print(d);
  PANTALLA_SILO.print("     cm        ");
  delay(500);
  int porcentaje = ((d)/22.26)*100;
  delay(100);
  return porcentaje;
}
int lectura_teclado(){
  char tecla = teclado_estrada.getKey();
  
  if(tecla){
switch(tecla){
  
   case '1': // Primera unidad de tamizaje
   if(capacidad >= 5){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo: 1onz");
      Serial.println(capacidad);
      SERVO_SILO.write(a);
      delay(1400);
      SERVO_SILO.write(b);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
    tone(BUZZER, 1760);
    delay(100);
    noTone(BUZZER);
    for(int i = 0; i < 5; i++){
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("      Error     ");
     delay(500);
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("  Insuficiente  ");
     delay(500);
    }
    break;
  }

  case '2': // Segunda unidad de tamizaje
   if(capacidad >= 10){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo: 2onz");
      Serial.println(capacidad);
      SERVO_SILO.write(a);
      delay(2350);
      SERVO_SILO.write(b);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
    tone(BUZZER, 1760);
    delay(100);
    noTone(BUZZER);
    for(int i = 0; i < 5; i++){
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("      Error     ");
     delay(500);
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("  Insuficiente  ");
     delay(500);
    }
    break;
  }

  case '3': // Tercera unidad de tamizaje
   if(capacidad >= 15){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo: 4onz");
      Serial.println(capacidad);
      SERVO_SILO.write(a);
      delay(3000);
      SERVO_SILO.write(b);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
    tone(BUZZER, 1760);
    delay(100);
    noTone(BUZZER);
    for(int i = 0; i < 5; i++){
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("      Error     ");
     delay(500);
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("  Insuficiente  ");
     delay(500);
    }
    break;
  }

  case '4': // Cuarta unidad de tamizaje
   if(capacidad >= 20){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo: 8onz");
      Serial.println(capacidad);
      SERVO_SILO.write(a);
      delay(7600);
      SERVO_SILO.write(b);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
    tone(BUZZER, 1760);
    delay(100);
    noTone(BUZZER);
    for(int i = 0; i < 5; i++){
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("      Error     ");
     delay(500);
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("  Insuficiente  ");
     delay(500);
    }
    break;
  }
  case '5': // Quinta unidad de tamizaje
   if(capacidad >= 30){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo:12onz");
      Serial.println(capacidad);
      SERVO_SILO.write(a);
      delay(11750);
      SERVO_SILO.write(b);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
    tone(BUZZER, 1760);
    delay(100);
    noTone(BUZZER);
    for(int i = 0; i < 5; i++){
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("      Error     ");
     delay(500);
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("  Insuficiente  ");
     delay(500);
    }
    break;
  }

  case '6': // Sexta unidad de tamizaje
   if(capacidad >= 45){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo:16onz");
      Serial.println(capacidad);
      SERVO_SILO.write(a);
      delay(30000);
      SERVO_SILO.write(b);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
    tone(BUZZER, 1760);
    delay(100);
    noTone(BUZZER);
    for(int i = 0; i < 5; i++){
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("      Error     ");
     delay(500);
     PANTALLA_SILO.setCursor(0,1);
     PANTALLA_SILO.print("  Insuficiente  ");
     delay(500);
    }
    break;
  }
  case '7': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case '8': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case '9': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case '0': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case 'A': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case 'B': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case 'C': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case 'D': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case '*': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
    case '#': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Entrada Invalida");
   delay(900);
    break;
  }
} // Final del Switch
  }

void envio_arduino_secundario(){
  
  if(capacidad < 10){ // Menos del 10%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin0, LOW);
    }
    else if(capacidad >= 10 && capacidad < 20){ // entre 10 y 20%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin0, HIGH);
    
    }
    else if(capacidad >= 20 && capacidad < 30){  // entre 20 y 30%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin0, LOW);
//    delay(200);
    }
    else if(capacidad >= 30 && capacidad < 40){  // entre 30 y 40%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin0, HIGH);
//    delay(200);
    }
    else if(capacidad >= 40 && capacidad < 50){  // entre 40 y 50%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, LOW);
    digitalWrite(pin0, LOW);
//    delay(200);
    }
    else if(capacidad >= 50 && capacidad < 60){  // entre 50 y 60%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, LOW);
    digitalWrite(pin0, HIGH);
    }
    else if(capacidad >= 60 && capacidad < 70){  // entre 60 y 70%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin0, LOW);
//    delay(200);
    }
    else if(capacidad >= 70 && capacidad < 80){  // entre 70 y 80%
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin0, HIGH);
//    delay(200);
    }
    else if(capacidad >= 80 && capacidad < 90){  // entre 80 y 90%
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin0, LOW);
//    delay(200);
    }
    else if(capacidad >= 90 && capacidad < 100){   // entre 90 y 100%
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin0, HIGH);
//    delay(200);
    }
    else if(capacidad >= 100){   // 100%
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin0, LOW);
//    delay(200);
    }
    
}
