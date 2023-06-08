//Directivas de Preprocesador
#define pinA 4
#define pinB 5
#define pinC 6
#define pinD 7
#define clockwise 2
#define anticlockwise 3
#define duplicar_rpm 8
//variables
int rpm_final = 150;
int rpm_fijo = 300;
volatile static bool clockwiselock;
volatile static bool anticlockwiselock;


//FUNCIONES
void funcion_ISR_clockwise(void);
void funcion_ISR_anticlockwise(void);
void Stepper_clockwise();
void Stepper_anticlockwise();

void setup() {
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
attachInterrupt(digitalPinToInterrupt(clockwise),funcion_ISR_clockwise,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
attachInterrupt(digitalPinToInterrupt(anticlockwise),funcion_ISR_anticlockwise,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
}

void loop() {

}

  void funcion_ISR_clockwise(){
  //Cuando se dispara la interrupcion por Rising
    Serial.println("movimiento horario");
    clockwiselock = HIGH;
    anticlockwiselock = LOW;
    if(duplicar_rpm){
  rpm_final = rpm_fijo/2;
  }
  else{
   rpm_final = rpm_fijo;
   }
   Stepper_clockwise();
}

  void funcion_ISR_anticlockwise(){
  //Cuando se dispara la interrupcion por Rising
    Serial.println("movimiento antihorario");
    anticlockwiselock = LOW;
    clockwiselock = HIGH;
    if(duplicar_rpm){
  rpm_final = rpm_fijo/2;
  }
  else{
   rpm_final = rpm_fijo;
   }
   Stepper_anticlockwise();
}
void Stepper_anticlockwise(){
  for(int ciclos = 0;ciclos < 4;ciclos++){
  if(ciclos == 0){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  delay(rpm_final);
  }
  if(ciclos == 1){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }
  if(ciclos == 2){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }
  if(ciclos == 3){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }
  }
}
void Stepper_clockwise(){
  for(int ciclos = 0;ciclos < 4;ciclos++){
  if(ciclos == 0){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }
  if(ciclos == 1){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }
  if(ciclos == 2){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }
  if(ciclos == 3){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  delay(rpm_final);
  }
  }
}
