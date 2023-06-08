//Directivas de Preprocesador
#define pinA 4
#define pinB 5
#define pinC 6
#define pinD 7
#define ledV 9
#define ledA 10
#define ledR 11
#define clockwise 2
#define anticlockwise 3
#define duplicar_rpm 8

//variables
int rpm_final;
int rpm_fijo = 500;
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
pinMode(ledV, OUTPUT);
pinMode(ledA, OUTPUT);
pinMode(ledR, OUTPUT);
attachInterrupt(digitalPinToInterrupt(clockwise),funcion_ISR_clockwise,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
attachInterrupt(digitalPinToInterrupt(anticlockwise),funcion_ISR_anticlockwise,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
}

void loop() {
     if(digitalRead(duplicar_rpm)==HIGH){
  rpm_final = rpm_fijo/2;
  digitalWrite(ledR, HIGH);
  }
  else{
   rpm_final = rpm_fijo;
   digitalWrite(ledR, LOW);
   }
if ((clockwiselock == HIGH)&&(anticlockwiselock == LOW)){
  Stepper_clockwise();
  }
  if ((clockwiselock == LOW)&&(anticlockwiselock == HIGH)){
  Stepper_anticlockwise();
  }
}

  void funcion_ISR_clockwise(){
  //Cuando se dispara la interrupcion por Rising
    Serial.println("movimiento horario");
    clockwiselock = HIGH;
    anticlockwiselock = LOW;
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, LOW);
  }
  void funcion_ISR_anticlockwise(){
  //Cuando se dispara la interrupcion por Rising
   Serial.println("movimiento antihorario");
   clockwiselock = LOW;
   anticlockwiselock = HIGH;
   Stepper_anticlockwise();
   digitalWrite(ledV, LOW);
   digitalWrite(ledA, HIGH);
}
void Stepper_anticlockwise(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  delay(rpm_final);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  }

void Stepper_clockwise(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  delay(rpm_final);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  delay(rpm_final);
}
