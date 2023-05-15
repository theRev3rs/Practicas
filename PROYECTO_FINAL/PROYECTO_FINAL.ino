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

//Construccion del teclado matricial
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
Servo Puerta_Silo; 

//Variables
byte capacidad;
int maximo = 100;

//Funciones
float medicion();
int lectura_teclado();
void envio_arduino_secundario();

void setup() {
  Serial.begin(9600); // Inicia comunicación con la consola
  Wire.begin(); // Iniciamos la libreria wire
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); // Configuramos los pines del Ultrasonico
  PANTALLA_SILO.init(); //Iniciamos el LCD
  PANTALLA_SILO.backlight();  //Encendemos la luz del LCD
  Puerta_Silo.attach(pin_Servo); // Inicia el Servo
  Puerta_Silo.write(0);
}

void loop() {
   PANTALLA_SILO.setCursor(16,1);
   PANTALLA_SILO.print(".");
   lectura_teclado();   // Lee el telcado Matricial
   capacidad = maximo - medicion();   // Mide el contenido del silo
   envio_arduino_secundario();  // Envia los datos al Arduino secundario

   // Interfaz ( Por alguna razon dentro de una funcion no funciona )
  if (capacidad <= 100){  // Verifica que no se exeda la capacidad o se encuentre abierto
    PANTALLA_SILO.setCursor(0,0);   //Colocamos el cursor en la posicion (0,0)
     PANTALLA_SILO.print("Almacenado:");   //Imprimimos la palabra "Caracter"
   PANTALLA_SILO.setCursor(11,0);    // Imprime la interfaz
   PANTALLA_SILO.print(capacidad);
   PANTALLA_SILO.print("%  ");      //Imprime el porcentaje del silo
   PANTALLA_SILO.setCursor(0,1);
PANTALLA_SILO.print("     Listo      ");  // Indica que se puede servir
   }
   else { // Si detecta sobrecarga o apertura
    PANTALLA_SILO.setCursor(0,0);
    PANTALLA_SILO.print(" Cierre la Tapa ");
    PANTALLA_SILO.setCursor(0,1);
    PANTALLA_SILO.print("                ");
   }
   
}
float medicion(){
  long t;
  int d; 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(500);
  float porcentaje = (d/30)*100;
  return porcentaje;
}

int lectura_teclado(){
  char tecla = teclado_estrada.getKey();
  
  if(tecla){
switch(tecla){
  
   case '1': // Primera unidad de tamizaje
   if(capacidad >= 5){ // Ejemplo del porcentaje minimo para completar la solicitud
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Sirviendo: 1 lb ");
      Serial.println(capacidad);
      Puerta_Silo.write(90);
      delay(2000);
      Puerta_Silo.write(0);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
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
   PANTALLA_SILO.print("Sirviendo: 2.5lb ");
      Serial.println(capacidad);
      Puerta_Silo.write(90);
      delay(5000);
      Puerta_Silo.write(0);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
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
   PANTALLA_SILO.print("Sirviendo: 5 lb ");
      Serial.println(capacidad);
      Puerta_Silo.write(90);
      delay(10000);
      Puerta_Silo.write(0);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
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
   PANTALLA_SILO.print("Sirviendo: 10 lb ");
      Serial.println(capacidad);
      Puerta_Silo.write(90);
      delay(15000);
      Puerta_Silo.write(0);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
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
   PANTALLA_SILO.print("Sirviendo: 12 lb ");
      Serial.println(capacidad);
      Puerta_Silo.write(90);
      delay(20000);
      Puerta_Silo.write(0);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
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
   PANTALLA_SILO.print("Sirviendo: 16 lb ");
      Serial.println(capacidad);
      Puerta_Silo.write(90);
      delay(30000);
      Puerta_Silo.write(0);
      delay(500);
      envio_arduino_secundario(); // Envio de datos al Arduino secundario
      break;
   } else{    // En caso de que no sea suficiente para completar la solicitud
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
    Puerta_Silo.write(0);
   PANTALLA_SILO.print("Protocolo de vaciado");
   delay(500);
   PANTALLA_SILO.print("Cancelado");
   delay(500);
    break;
    case '#': // boton invalido
   PANTALLA_SILO.setCursor(0,1);
   PANTALLA_SILO.print("Protocolo de vaciado");
   Puerta_Silo.write(90);
    break;
  }
} // Final del Switch
  }

void envio_arduino_secundario(){
  
  if(capacidad <= 10){ // Menos del 10%
    Serial.println("0");//Porcentaje de granos dentro
    PANTALLA_SILO.setCursor(0,1);
    PANTALLA_SILO.print(" Rellenar Silo  ");
    delay(500);
    }
    else if(capacidad > 10 && capacidad <= 20){ // entre 10% y 20%
    Serial.println("10");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 20 && capacidad <= 30){  // entre 20% y 30%
    Serial.println("20");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 30 && capacidad <= 40){  // entre 30% y 40%
    Serial.println("30");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 40 && capacidad <= 50){  // entre 40% y 50%
    Serial.println("40");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 50 && capacidad <= 60){  // entre 50% y 60%
    Serial.println("50");//Porcentaje de granos dentro
    }
    else if(capacidad > 60 && capacidad <= 70){  // entre 60% y 70%
    Serial.println("60");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 70 && capacidad <= 80){  // entre 70% y 80%
    Serial.println("70");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 80 && capacidad <= 90){  // entre 80% y 90%
    Serial.println("80");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 90 && capacidad <= 99){   // entre 90% y 99%
    Serial.println("90");//Porcentaje de granos dentro
    delay(1000);
    }
    else if(capacidad > 99){   // 100%
    Serial.println("100");//Porcentaje de granos dentro
    delay(1000);
    
    }
    
}
