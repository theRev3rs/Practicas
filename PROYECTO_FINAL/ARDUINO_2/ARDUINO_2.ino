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
 #define in0 14
 #define in1 15
 #define in2 16
 #define in3 17

 //Variables
 int D0;
 int D1;
 int D2;
 int D3;
 int porcentaje;
 
void setup() {
  pinMode(in0, INPUT);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);   // Definir las entradas del Arduino principal al secundario
  for(int i = 2; i < 13; i++){
    pinMode(i, OUTPUT);
    }
}

void loop() {
  lecturas();
 conversion_binaria();
}

bool lecturas(){
  D0 = digitalRead(in0);
  D1 = digitalRead(in1);
  D2 = digitalRead(in2);
  D3 = digitalRead(in3);
  }

int conversion_binaria(){
  if(D0 == LOW && D1 == LOW && D2 == LOW && D3 == LOW){ // entre 0 y 10%
    for(int i = 2; i < 13; i++){
    digitalWrite(i, HIGH);
    }
    delay(500);
    for(int i = 2; i < 13; i++){
    digitalWrite(i, LOW);
    }
    delay(500);
    }
  if(D0 == LOW && D1 == LOW && D2 == LOW && D3 == HIGH){    //entre 10 y 20%
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
    if(D0 == LOW && D1 == LOW && D2 == HIGH && D3 == LOW){    //entre 20 y 30%
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
    if(D0 == LOW && D1 == LOW && D2 == HIGH && D3 == HIGH){      //entre 30 y 40%
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
    if(D0 == LOW && D1 == HIGH && D2 == LOW && D3 == LOW){      //entre 40 y 50%
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
    if(D0 == LOW && D1 == HIGH && D2 == LOW && D3 == HIGH){      //entre 50 y 60%
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
    if(D0 == LOW && D1 == HIGH && D2 == HIGH && D3 == LOW){      //entre 60 y 70%
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
    if(D0 == LOW && D1 == HIGH && D2 == HIGH && D3 == HIGH){      //entre 70 y 80%
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
    if(D0 == HIGH && D1 == LOW && D2 == LOW && D3 == LOW){      //entre 80 y 90%
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
    if(D0 == HIGH && D1 == LOW && D2 == LOW && D3 == HIGH){      //entre 90 y 100%
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
    if(D0 == HIGH && D1 == LOW && D2 == HIGH && D3 == HIGH){      //100%
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
    }
