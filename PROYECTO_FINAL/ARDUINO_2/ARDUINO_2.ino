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
 #define pin0 13
 #define pin1 14
 #define pin2 15
 #define pin3 16
 bool D0;
 bool D1;
 bool D2;
 bool D3;
 
void setup() {
  Serial.begin(9600);
  for(int i = 3; i < 13; i++){
    pinMode(i, OUTPUT);
  }
   pinMode(13, INPUT);
    pinMode(14, INPUT);
    pinMode(15, INPUT);
    pinMode(16, INPUT);
    delay(2000);
}

void loop() {
   D0 = digitalRead(pin0);
   D1 = digitalRead(pin1);
   D2 = digitalRead(pin2);
   D3 = digitalRead(pin3);
   Serial.print(D3);
   Serial.print(D2);
   Serial.print(D1);
   Serial.println(D0);
   display_barra();
}


int display_barra(){
  if( D3 == 0 && D2 == 0 && D1 == 0 && D0 == 0 ){ // entre 0 y 10%
    for(int i = 3; i < 13; i++){
    digitalWrite(i, HIGH);
    }
    delay(50);
    for(int i = 3; i < 13; i++){
    digitalWrite(i, LOW);
    }
    delay(50);
    }
  if(D3 == 0 && D2 == 0 && D1 == 0 && D0 == 1){    //entre 10 y 20%
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 0 && D2 == 0 && D1 == 1 && D0 == 0){    //entre 20 y 30%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 0 && D2 == 0 && D1 == 1 && D0 == 1){      //entre 30 y 40%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    } 
    if(D3 == 0 && D2 == 1 && D1 == 0 && D0 == 0){      //entre 40 y 50%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 0 && D2 == 1 && D1 == 0 && D0 == 1){      //entre 50 y 60%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 0 && D2 == 1 && D1 == 1 && D0 == 0){      //entre 60 y 70%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 0 && D2 == 1 && D1 == 1 && D0 == 1){      //entre 70 y 80%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 1 && D2 == 0 && D1 == 0 && D0 == 0){      //entre 80 y 90%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
    if(D3 == 1 && D2 == 0 && D1 == 0 && D0 == 1){      //entre 90 y 100%
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    }
    if(D3 == 1 && D2 == 0 && D1 == 1 && D0 == 0){      // Excede al capacidad recomendada
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
    delay(100);
    }
    }
      
    
