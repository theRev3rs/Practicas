/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Seccion: A
 * Curso: Taller de electronica digital y reparacion de computadoras I
 * Nombres:
 *  Ricardo Estrada
 *  Diego Revolorio 
 *  Edgar Gálvez 
 *  Javier Vivar 
 *  Sebastian Bocaletti
 * Proyecto: ILUMINACION MAQUETA KINAL
*/

//Variables 
String entradaBT;

//Pulsadores
#define pushA 2
#define pushB 3
#define pushC 4
#define pushD 5
#define pushF 6
#define pushG 7
#define pushH 8
#define pushI 9

//Luminarias
#define EdificioA 10
#define EdificioB 11
#define EdificioC 12
#define EdificioD 13
#define EdificioF 14  //A0
#define EdificioG 15  //A1
#define EdificioH 16  //A2
#define EdificioI 17  //A3

void setup() {
  for(int i = 2; i < 9; i++){  //Pines del 2 al 8 como Entrada
    pinMode(i, INPUT);
    }
  for(int i = 9; i < 18; i++){  //Pines del 9 al 17 como Salida
    pinMode(i, INPUT);
    }
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    entradaBT = Serial.readStringUntil('\n');
  }
  luminarias();
}

void luminarias(){
    if((digitalRead(pushA) == HIGH) || (entradaBT == String("EdificioA"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioA, !digitalRead(EdificioA));  // Coloca las luminarias en el estado opuesto
    }
    
    if((digitalRead(pushB) == HIGH) || (entradaBT == String("EdificioB"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioB, !digitalRead(EdificioB));  // Coloca las luminarias en el estado opuesto
    }

    if((digitalRead(pushC) == HIGH) || (entradaBT == String("EdificioC"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioC, !digitalRead(EdificioC));  // Coloca las luminarias en el estado opuesto
    }

    if((digitalRead(pushD) == HIGH) || (entradaBT == String("EdificioD"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioD, !digitalRead(EdificioD));  // Coloca las luminarias en el estado opuesto
    }

    if((digitalRead(pushF) == HIGH) || (entradaBT == String("EdificioF"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioF, !digitalRead(EdificioF));  // Coloca las luminarias en el estado opuesto
    }

    if((digitalRead(pushG) == HIGH) || (entradaBT == String("EdificioG"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioG, !digitalRead(EdificioG));  // Coloca las luminarias en el estado opuesto
    }

    if((digitalRead(pushH) == HIGH) || (entradaBT == String("EdificioH"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioH, !digitalRead(EdificioH));  // Coloca las luminarias en el estado opuesto
    }

    if((digitalRead(pushI) == HIGH) || (entradaBT == String("EdificioI"))){   //Si el pulsador o la app se activan
    digitalWrite(EdificioI, !digitalRead(EdificioI));  // Coloca las luminarias en el estado opuesto
    }
  }
