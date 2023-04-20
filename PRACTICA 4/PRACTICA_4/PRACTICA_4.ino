/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: CONTADOR CON SUPERSONICO
   Dev: Ricardo Estrada
*/
#define trigger 9 //PIN digital 10 para el triggerGER 
#define echo 11 //PIN digital 11 para el echo
#define foco 12
long d; //Variable de distancia en cm
int gente = -1;
  
void setup() {
  Serial.begin(9600);
  for(int i = 2; i <=8; i++){
    pinMode(i,OUTPUT);
  } 
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(foco, OUTPUT);
  digitalWrite(trigger, LOW);
}
void loop(){
  Medicion();
  personas_maximas();
}
int Medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/58; 
  delay(600);
  return d;
}
void personas_maximas(){
  if(d >= 6 && d <=10){
    gente = gente + 1;
    Serial.println(gente);
        switch(gente){
        case 0:
        digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    delay(500);
    
      break;
    case 1:
    digitalWrite(foco, LOW);
      digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
    break;
    case 2:   
    digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
      delay(500);
      break;
    case 3: 
    digitalWrite(foco, LOW);
     digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  delay(500);
  break;
    case 4:
    digitalWrite(foco, LOW);
      digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
     delay(500);
     break;
    case 5:
    
    digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
     break;
    case 6:
    digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
    break;
    case 7:
    digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
    break;
    case 8:
    
    digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
    break;
    
    case 9:
    digitalWrite(foco, LOW);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
    break;
    case 10:
    Serial.println("Cantidad de personas maxima alcanzada");
    digitalWrite(foco, HIGH);
    delay(500);
    delay(500);
    gente = -1;
    break;   
        }
}
}
