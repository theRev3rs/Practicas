/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
 * Nombre: RICARDO ESTRADA 
 * CARNE: 2019553
 * Proyecto: Proyecto Final - Multimetro BT
 * 
 */
  
//Librerias

//Directivas
#define pinV A0
#define pinI A3

//Variables
String Entrada;
float Sensibilidad = 0.185;
float voltaje = 0;
float med_I = 0;
float corriente = 0;
float W = 0;  //Potencia
int R;   //Resistencia

//Funciones
void mediciones(int x); //Funcion de medicion y envio de datos

void setup() {
  Serial.begin(9600);
  pinMode(pinV, INPUT);
  pinMode(pinI, INPUT);
}

void loop() {
 if(Serial.available() > 0){
  Entrada = Serial.readStringUntil("\n");
 }
 if(Entrada == String("Potencia")){
  mediciones(1);
  }
 if(Entrada == String("Voltaje")){
  mediciones(2);
  }
 if(Entrada == String("Corriente")){
  mediciones(3);
  }
 if(Entrada == String("Resistencia")){
  mediciones(4);
  }
}
void mediciones(int x){
 voltaje =  (float)25*analogRead(pinV)/1023;
 delay(100);
 med_I = analogRead(pinI)*(5.0/1023.0);
 corriente = abs((2.5 - med_I)/Sensibilidad);
 delay(100);
  switch(x){
  case 1:
  W = voltaje * corriente;
  Serial.println(W,3);
  break;

  case 2:
  Serial.println(voltaje);
  break;

  case 3:
  Serial.println(corriente);
  break;

  case 4:
  R = voltaje / corriente;
  Serial.println(R);
  break;
}
}
