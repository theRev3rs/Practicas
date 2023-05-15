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

// ARDUINO SECUNDARIO

//Directivas de preprocesador

 //Variables
 int porcentaje;
 
void setup() {
  Serial.begin(9600);
  for(int i = 2; i < 13; i++){
    pinMode(i, OUTPUT);
    
  }
}

void loop() {
  if (Serial.available() > 0) {
    // Leer el Monitor Serial
    String dato = Serial.readString();

    // Convertir el dato a un entero
    porcentaje = dato.toInt();
    // Llamar a funcion que interpreta la informacion
    display_barra();
  }
   else {
    for(int i = 2; i < 13; i++){
    digitalWrite(i, HIGH);
    }
    delay(100);
    for(int i = 2; i < 13; i++){
    digitalWrite(i, LOW);
    }
    delay(100);
    }
   
}


int display_barra(){
  
  if(porcentaje == 0){ // entre 0 y 10%
    for(int i = 2; i < 13; i++){
    digitalWrite(i, HIGH);
    delay(100);
    }
    for(int i = 2; i < 13; i++){
    digitalWrite(i, LOW);
    delay(100);
    }
    }
  if(porcentaje == 10){    //entre 10 y 20%
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 20){    //entre 20 y 30%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 30){      //entre 30 y 40%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    } 
    if(porcentaje == 40){      //entre 40 y 50%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 50){      //entre 50 y 60%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 60){      //entre 60 y 70%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 70){      //entre 70 y 80%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 80 ){      //entre 80 y 90%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 90){      //entre 90 y 100%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    }
    if(porcentaje == 100){      //100%
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    }
    else{
      for(int i = 2; i < 13; i++){
    digitalWrite(i, HIGH);
    }
    delay(100);
    for(int i = 2; i < 13; i++){
    digitalWrite(i, LOW);
    }
    delay(100);
    }
      }
    
