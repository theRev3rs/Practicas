
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: LCD Con ARDUINO
   Dev: Ricardo Estrada
*/         
#include <LiquidCrystal.h>
#define RS 2
#define E 7
#define D4 6
#define D5 5
#define D6 4
#define D7 3
#define echo 8
#define trigger 9
#define alarma 12
int gente = 0;
int d;
int i;
LiquidCrystal Pantalla_Estrada (RS,E,D4,D5,D6,D7);

byte customChar1[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010
};
byte customChar2[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010
};
byte customChar3[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B01110,
  B11111,
  B11111,
  B11111
};

void setup() {
  Pantalla_Estrada.begin(16, 2);
  Pantalla_Estrada.clear();
  Pantalla_Estrada.createChar(1, customChar1);
  Pantalla_Estrada.createChar(2, customChar2);
    Pantalla_Estrada.createChar(3, customChar3);
   Serial.begin(9600);
   pinMode(alarma, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Pantalla_Estrada.setCursor(0,0);
   Pantalla_Estrada.print("PERSONAS DENTRO:");
   digitalWrite(alarma, LOW);
}
void loop(){
  Serial.println(d);
  medicion();
  personas();
  
}
int medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(500);
  return d;
}
 void personas(){
    if((d >= 6) && (d < 10)){
      if(gente <= 15){
    gente++;
    int avance = gente -1;
    Pantalla_Estrada.setCursor(avance, 1);
    Pantalla_Estrada.write(1);
    delay(10);
    Pantalla_Estrada.write(2);
    Serial.print("Cantidad de personas: ");
    Serial.println(gente);
    delay(500);}
    if( gente >= 16){
    exceso();
      }
    }
    }
void exceso(){
      digitalWrite(alarma, HIGH);
      Pantalla_Estrada.setCursor(0,1);
      Pantalla_Estrada.print("CAPACIDAD MAXIMA");
      delay(1200);
      Pantalla_Estrada.setCursor(0,1);
      Pantalla_Estrada.print("   ALCANZADA ");
      Pantalla_Estrada.write(3);
      Pantalla_Estrada.write(3);
      Pantalla_Estrada.write(3);
      digitalWrite(alarma, LOW);
      delay(700);
      }
  
