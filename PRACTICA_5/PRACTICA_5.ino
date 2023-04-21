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
float Do = 261.626;
float DoSos = 277.163;
float Re = 293.665;
float ReSos = 311.127;
float Mi = 329.628;
float Fa = 349.228;
float FaSos = 369.994;
float Sol = 391.995;
float SolSos = 415.305;
float La = 440;
float LaSos = 446.164;
float Si = 494.883;
#define echo 11
#define trigger 9
#define octup 5
#define octdown6
#define buzz 2
long d;
void setup()    
{    
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  Serial.println(d);
  medicion();
  notas();
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
  void notas(){
    if(d == 4){
    tone(buzz, 262);
    //delay(10);         //Do
    //noTone(buzz);
    }
    if(d == 7){
    tone(buzz, 277);
    //delay(10);        //Do Sostenido
    //noTone(buzz);
    }
    if(d == 10){
    tone(buzz, 294);
    //delay(10);         //Re
    //noTone(buzz);
    }
    if(d == 13){
    tone(buzz, 311);
    //delay(10);         //Re Sostenido
    //noTone(buzz);
    }
    if(d == 16){
    tone(buzz, 330);
    //delay(10);         //Mi
    //noTone(buzz);
    }
    if(d == 19){
    tone(buzz, 349);
    //delay(10);         //Fa
    //noTone(buzz);
    }
    if(d == 22){
    tone(buzz, 370);
    //delay(10);         //Fa Sostenido
    //noTone(buzz);
    }
    if(d == 25){
    tone(buzz, 392);
    //delay(10);         //Sol
    //noTone(buzz);
    }
    if(d == 28){
    tone(buzz, 415);
    //delay(10);         //Sol Sostenido
    //noTone(buzz);
    }
    if(d == 31){
    tone(buzz, 440);
    //delay(10);         //La
    //noTone(buzz);
    }
    if(d == 34){
    tone(buzz, 446);
    //delay(10);         //La Sostenido
    //noTone(buzz);
    }
    if(d == 37){
    tone(buzz, 494);
    //delay(10);         //Sol
    //noTone(buzz);
    }
    else{
      delay(400);
    noTone(buzz);
    }
    }
  
  
