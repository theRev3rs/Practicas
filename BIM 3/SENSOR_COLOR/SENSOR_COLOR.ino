/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: RICARDO ESTRADA
 * Carnet: 2019553
 * Proyecto: Sensor de Color con LDR
*/
//Librerias
#include <Stepper.h>
#include <Servo.h>

//Directivas del preprocesador
#define ch_LDR    A0  //pin A0 del arduino, a este conectaremos el punto medio del divisor de tension entre LDR y una resistencia de 33K
#define led_Azul  2   //led azul conectado al pin 3
#define led_Verde 3   //led verde conectado al pin 4
#define led_Rojo  4   //led rojo conectado al pin 5
#define pinA 15
#define pinB 16
#define pinC 17
#define pinD 18
#define objeto 12
#define valido 8
#define invalido 9

//Variables
//Valores analogicos de la intensidad de cada color
int resultado_azul, resultado_rojo, resultado_verde;
//Valores analogicos leidos por la LDR
int resultado;

//Valor de umbral para los colores
int tol = 8; //este valor lo podremos cambiar segun los valores leidos por nuestra LDR
//Constructor
Stepper Banda(2048,pinA,pinC,pinB,pinD);
Servo piston;

void setup() {
  //Comunicacion serial
  Serial.begin(9600);

  //Configuracion de I/O 
  pinMode(ch_LDR, INPUT); //pin A0 como entrada
  pinMode(led_Azul, OUTPUT); //pin 3 como salida
  pinMode(led_Verde, OUTPUT); //pin 4 como salida
  pinMode(led_Rojo, OUTPUT);  //pin 5 como salida
  pinMode(valido, OUTPUT);
  pinMode(invalido, OUTPUT);
  
  //Los leds inician en un estado de bajo
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);
  
  //Servo y Banda  
  Banda.setSpeed(15);
  piston.attach(6);
}

void loop() {
  if(digitalRead(objeto) == true){
    Banda.step(1);
    }
    if(digitalRead(objeto) == false){
    color();
    }
}
int color(){
  //Enciendo el led rojo
  digitalWrite(led_Rojo, HIGH);
  //espero 150 milisegundos
  delay(50);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_rojo = map(resultado, 0,1023,0,255);  //lo linealizo 
  digitalWrite(led_Rojo, LOW);
  delay(50);

  //Enciendo el led verde
  digitalWrite(led_Verde, HIGH);
  //espero 150 milisegundos
  delay(50);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_verde = map(resultado, 0,1023,0,255);  //lo linealizo 
  digitalWrite(led_Verde, LOW);
  delay(50);

   //Enciendo el led azul
  digitalWrite(led_Azul, HIGH);
  //espero 150 milisegundos
  delay(50);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_azul = map(resultado, 0,1023,0,255);  //lo linealizo 
  digitalWrite(led_Azul, LOW);
  delay(50);

  if(resultado_verde > resultado_azul && resultado_verde > resultado_rojo){
    digitalWrite(valido, HIGH);
    Serial.println("Verde OK");
    delay(100);
    Serial.println("Posicionando...");
    Banda.step(2048);
    delay(100);
    Serial.println("Posicionado");
    piston.write(180);
    Serial.println("Piston");
    delay(2000);
    piston.write(0);
    digitalWrite(valido, LOW);
    }
    else{
      Serial.println("No valido");
      for(int i = 0; i < 12; i++){
      digitalWrite(invalido, !digitalRead(invalido));
      delay(100);
      }
      Banda.step(2048);
      }
  }
