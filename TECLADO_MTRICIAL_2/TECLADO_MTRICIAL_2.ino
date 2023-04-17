/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: TECLADO MATRICIAL
   Dev: Ricardo Estrada
*/
#include <Keypad.h>
#define cols 4
#define rows 4
#define pina 19
#define pinb 11
#define pinc 14
#define pind 15
#define pine 16
#define pinf 17
#define ping 18
#define pindot 13
char holdkey;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte pines_filas[rows] = {2,3,4,5};
byte pines_columnas[cols] = {6,7,8,9};

Keypad teclado_estrada = Keypad( makeKeymap(keys), pines_filas, pines_columnas, rows,cols);

void setup() {
Serial.begin(9600);
pinMode(pina, OUTPUT);
pinMode(pinb, OUTPUT);
pinMode(pinc, OUTPUT);
pinMode(pind, OUTPUT);
pinMode(pine, OUTPUT);
pinMode(pinf, OUTPUT);
pinMode(ping, OUTPUT);
pinMode(pindot, OUTPUT);
}

void loop() 
{
 char tecla = teclado_estrada.getKey();
  switch(tecla)
  {
    case '0':
      Serial.println("0");
      
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, LOW);
    delay(1000);
      break;
    case '1':
      Serial.println(tecla);
      digitalWrite(pina, LOW);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, LOW);
    digitalWrite(pine, LOW);
    digitalWrite(pinf, LOW);
    digitalWrite(ping, LOW);
    delay(1000);
    break;
    case '2':
      Serial.println(tecla);   
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, LOW);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, LOW);
    digitalWrite(ping, HIGH);
      delay(1000);
      break;
    case '3':
      Serial.println(tecla);
      
     digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, LOW);
    digitalWrite(pinf, LOW);
    digitalWrite(ping, HIGH);
  delay(1000);
  break;
    case '4':
      Serial.println(tecla);
      digitalWrite(pina, LOW);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, LOW);
    digitalWrite(pine, LOW);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
     delay(1000);
     break;
    case '5':
    Serial.println(tecla);
    
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, LOW);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, LOW);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
     break;
    case '6':
    Serial.println(tecla);
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, LOW);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    break;
    case '7':
    Serial.println(tecla);
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, LOW);
    digitalWrite(pine, LOW);
    digitalWrite(pinf, LOW);
    digitalWrite(ping, LOW);
    delay(1000);
    break;
    case '8':
    Serial.println(tecla);
    
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    break;
    case '9':
    Serial.println(tecla);
    
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, LOW);
    digitalWrite(pine, LOW);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    break;
     
    case 'A':
    Serial.println(tecla);
    
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, LOW);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    break;
     
    case 'B':
    Serial.println(tecla);
    
     digitalWrite(pina, LOW);
    digitalWrite(pinb, LOW);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    break;
    case 'C':
    Serial.println(tecla);
    
     digitalWrite(pina, LOW);
    digitalWrite(pinb, LOW);
    digitalWrite(pinc, LOW);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, LOW);
    digitalWrite(ping, HIGH);
    delay(1000);
    break;
     
    case 'D':
    Serial.println(tecla);
    
      digitalWrite(pina, LOW);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, LOW);
    digitalWrite(ping, HIGH);
    delay(1000);
  
     break;
    case '*':
    Serial.println(tecla);
    
      digitalWrite(pina, HIGH);
    digitalWrite(pinb, LOW);
    digitalWrite(pinc, LOW);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    
    
   break;
    case '#':
    Serial.println(tecla);
    
     digitalWrite(pina, HIGH);
    digitalWrite(pinb, LOW);
    digitalWrite(pinc, LOW);
    digitalWrite(pind, LOW);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, HIGH);
    delay(1000);
    
     break;
     
    case NO_KEY:
    digitalWrite(pina, HIGH);
    digitalWrite(pinb, HIGH);
    digitalWrite(pinc, HIGH);
    digitalWrite(pind, HIGH);
    digitalWrite(pine, HIGH);
    digitalWrite(pinf, HIGH);
    digitalWrite(ping, LOW);    
    digitalWrite(pindot, HIGH);
    break;
}
}
