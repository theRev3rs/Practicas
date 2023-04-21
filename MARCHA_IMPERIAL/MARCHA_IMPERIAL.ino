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
#define timer 3
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
  notas();;
}
int medicion(){
  long t; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  t = pulseIn(echo, HIGH);
  d = t/59;
  delay(250);
  return d;
}
  void notas(){
    if(d == 4){
    tone(buzz, Do*2);
    delay(250);         //1
    noTone(buzz);
    }
    if(d == 6){
    tone(buzz, DoSos*2);
    delay(250);        //2
    noTone(buzz);
    }
    if(d ==8){
    tone(buzz, Re*2);
    delay(250);         //3
    noTone(buzz);
    }
    if(d ==10){
    tone(buzz, ReSos*2);
    delay(250);         //4
    noTone(buzz);
    }
    if((d ==12)){
    tone(buzz, Mi*2);
    delay(250);         //5
    noTone(buzz);
    }
    if(d == 14){
    tone(buzz, Fa*2);
    delay(250);         //6
    noTone(buzz);
    }
    if(d == 16){
    tone(buzz, FaSos*2);
    delay(250);         //7
    noTone(buzz);
    }
    if(d == 18){
    tone(buzz, Sol*2);
    delay(250);         //8
    noTone(buzz);
    }
    if(d == 20){
    tone(buzz, SolSos*2);
    delay(250);         //9
    noTone(buzz);
    }
    if(d == 22){
    tone(buzz, La*2);
    delay(250);         //10
    noTone(buzz);
    }
    if(d == 24){
    tone(buzz, LaSos*2);
    delay(250);         //11
    noTone(buzz);
    }
    if(d == 26){
    tone(buzz, Si*2);
    delay(250);         //12
    noTone(buzz);
    }
     if(d == 28){
    tone(buzz, Do*3);
    delay(250);         //13
    noTone(buzz);
    }
    /*  
     if(d == 42){
    tone(buzz, Sol);
    delay(250);         //14
    noTone(buzz);
    }
     if(d == 45){
    tone(buzz, Mi);
    delay(250);         //15
    noTone(buzz);
    }
     if(d == 48){
    tone(buzz, Do);
    delay(250);         //16
    noTone(buzz);
    }
     if(d == 51){
    tone(buzz, Sol);
    delay(250);         //17
    noTone(buzz);
    }
     if(d == 54){
    tone(buzz, Mi);
    delay(150);         //18
    noTone(buzz);
    }
    */
  }
  
