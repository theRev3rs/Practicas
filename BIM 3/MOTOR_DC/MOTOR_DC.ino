//Directivas de Preprocesador
#define pinA 6
#define pinB 5
#define ledR 10
#define ledV 9
#define ledA 11
#define clockwise 2
#define anticlockwise 3
#define duplicar_rpm 8
//variables
int rpm_final;
int rpm_fijo = 120;
bool clockwiselock;
bool anticlockwiselock;

//FUNCIONES
void funcion_ISR_clockwise(void);
void funcion_ISR_anticlockwise(void);

void setup() {
  Serial.begin(9600);
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(ledA, OUTPUT);
pinMode(ledV, OUTPUT);
pinMode(ledR, OUTPUT);
pinMode(clockwise, INPUT);
pinMode(anticlockwise, INPUT);
pinMode(duplicar_rpm, INPUT);
attachInterrupt(digitalPinToInterrupt(clockwise),funcion_ISR_clockwise,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
attachInterrupt(digitalPinToInterrupt(anticlockwise),funcion_ISR_anticlockwise,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
}

void loop() {
   if(digitalRead(duplicar_rpm) == HIGH){
     rpm_final = 255;
     digitalWrite(ledR, HIGH);
   }
   else{
     rpm_final = rpm_fijo;
     digitalWrite(ledR, LOW);
   }
   
  if(clockwiselock == HIGH && anticlockwiselock == LOW){
    analogWrite(pinA, rpm_final);
    digitalWrite(pinB, LOW);
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, LOW);
    }
  if(clockwiselock == LOW && anticlockwiselock == HIGH){
    digitalWrite(pinA, LOW);
    analogWrite(pinB, rpm_final);
    digitalWrite(ledV, LOW);
    digitalWrite(ledA, HIGH);
    }
}
  void funcion_ISR_clockwise(){  //Cuando se dispara la interrupcion por Rising
    Serial.println("movimiento horario");
   clockwiselock=HIGH;
   anticlockwiselock=LOW;
   
}
  void funcion_ISR_anticlockwise(){  //Cuando se dispara la interrupcion por Rising
    Serial.println("movimiento antihorario");
   clockwiselock=LOW;
   anticlockwiselock=HIGH;
}
