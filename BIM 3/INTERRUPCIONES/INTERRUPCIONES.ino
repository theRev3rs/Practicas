/*
*Fundacion Kinal
*Centro Educativo Tecnico Laboral Kinal
*Electronica
*Grado: Quinto
*Seccion: A
*Cuerso: Taller de Electronica Digital y Reparacion de Computadoras I
*Nombre: Ricardo Estrada
*Carnet: 2019553
*Proyecto: Uso de interrupciones externas
*/

//Directivas de preprocesador
#define btn_rising 2 //Pin 2 para interrupcion externa por rising
#define btn_falling 3 //Pin 3 para interrupcion externa por falling
//display X1
#define a1 4
#define b1  5
#define c1 6
#define d1 7
#define e1 8
#define f1 9
#define g1 10
//display 1X
#define a2 11
#define b2 12
#define c2 13
#define d2 14
#define e2 15
#define f2 16
#define g2 17
#define builtinled 13

//Funciones ISR
/*
 * ISR - Interrupt Services Routine
 * Estas son las funciones que van a ser llamadas al dispararse una interrupcion externa
 * 
 * Nota: Las Funciones deben ser sin retorno y sin parametros
*/
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);
int suma_unidad();
int resta_unidad();

//Funciones
int contador();
void display_izq();
void display_der();

//Variables
volatile static bool f_print = false; // Variable que me permite imprimir un texto en el loop
volatile static bool r_print = false; // Variable que me permite imprimir un texto en el loop
volatile static byte i = 0;
int unidad = 0;
int decena = 0;
int num = 0;
bool estado; 
void setup() {
Serial.begin(19200);
pinMode(btn_rising, INPUT); //Pin 2 como entrada
pinMode(btn_falling, INPUT); //Pin 3 como entrada
attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING); //Anclar la interrupcion del pin 2 a una Funcion ISR disparada por el flanco ascendente
attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupcion del pin 3 a una Funcion ISR disparada por el flanco descendente
pinMode(a1, OUTPUT);
pinMode(b1, OUTPUT);
pinMode(c1, OUTPUT);
pinMode(d1, OUTPUT);
pinMode(e1, OUTPUT);
pinMode(f1, OUTPUT);
pinMode(g1, OUTPUT);
pinMode(a2, OUTPUT);
pinMode(b2, OUTPUT);
pinMode(c2, OUTPUT);
pinMode(d2, OUTPUT);
pinMode(e2, OUTPUT);
pinMode(f2, OUTPUT);
pinMode(g2, OUTPUT);
}

void loop() {
     if( unidad > 50){
      unidad = 0;
      }
      if( unidad < 0){
      unidad = 50;
      }
   display_izq();
   display_der();
  //Limpio la Variable
  
  r_print = false;
  f_print = false;
}
void funcion_ISR_rising(){
  //Cuando se dispara la interrupcion por Rising
    suma_unidad();
}
void funcion_ISR_falling(){
    //Cuando se dispara la interrupcion por Falling
  resta_unidad();
}
int suma_unidad(){ // Suma un numero
  unidad++;
  Serial.println(unidad);
}
int resta_unidad(){ // Resta un numero
  unidad--;
  Serial.println(unidad); 
  }
  
 void display_der(){ // Despliega las unidades
   if(unidad == 0 ||unidad == 10||unidad == 20||unidad == 30||unidad == 40||unidad == 50){  //Unidades a 0
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, LOW);
   }
   if( unidad == 1||unidad == 11||unidad == 21||unidad == 31||unidad == 41){   //Unidades a 1
      digitalWrite(a1, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(e1, LOW);
      digitalWrite(f1, LOW);
      digitalWrite(g1, LOW);
   }
   if( unidad == 2||unidad == 12||unidad == 22||unidad == 32||unidad == 42){    //Unidades a 2
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, LOW);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, LOW);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 3||unidad == 13||unidad == 23||unidad == 33||unidad == 43){   //Unidades a 3
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, LOW);
      digitalWrite(f1, LOW);
      digitalWrite(g1, HIGH);
   }
    if( unidad == 4||unidad == 14||unidad == 24||unidad == 34||unidad == 44){ //Unidades a 4
      digitalWrite(a1, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(e1, LOW);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 5||unidad == 15||unidad == 25||unidad == 35||unidad == 45){   //Unidades a 5
      digitalWrite(a1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, LOW);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 6||unidad == 16||unidad == 26||unidad == 36||unidad == 46){   //Unidades a 6
      digitalWrite(a1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 7||unidad == 17||unidad == 27||unidad == 37||unidad == 47){    //Unidades a 7
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(e1, LOW);
      digitalWrite(f1, LOW);
      digitalWrite(g1, LOW);
   }
   if( unidad == 8||unidad == 18||unidad == 28||unidad == 38||unidad == 48){    //Unidades a 8
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 9||unidad == 19||unidad == 29||unidad == 39||unidad == 49){     //Unidades a 9
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, LOW);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
 }

    void display_izq(){  //Despliega las decenas
   if(unidad == 0 || unidad == 9){ //Decenas a Cero
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(e2, HIGH);
      digitalWrite(f2, HIGH);
      digitalWrite(g2, LOW);
    }
      if(unidad == 10 || unidad == 19){ //Decenas a Diez
      digitalWrite(a2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(e2, LOW);
      digitalWrite(f2, LOW);
      digitalWrite(g2, LOW);
    }
    if(unidad == 20 || unidad == 29){ //Decenas a veinte
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(e2, HIGH);
      digitalWrite(f2, LOW);
      digitalWrite(g2, HIGH);
    }
    if(unidad == 30 || unidad == 39){ //Decenas a treinta
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(e2, LOW);
      digitalWrite(f2, LOW);
      digitalWrite(g2, HIGH);
    }
    if(unidad == 40 || unidad == 49){ //Decenas a cuarenta
      digitalWrite(a2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(e2, LOW);
      digitalWrite(f2, HIGH);
      digitalWrite(g2, HIGH);
    }
    if(unidad == 50){   // Decenas a cincuenta
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(e2, LOW);
      digitalWrite(f2, HIGH);
      digitalWrite(g2, HIGH);
      }
    }
