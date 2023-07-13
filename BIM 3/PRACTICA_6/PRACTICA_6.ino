/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: José Ricardo Estrada Guay
 * CARNE: 2019553
 * Proyecto: SmartWarehouse
*/
//Librerias
#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>

//Directivas
#define ancho_matriz 8 
#define alto_matriz 8
#define DATO_PIN 12
#define CLK_PIN 11
#define CS_PIN 10

//Variables
int inclinacion_x;
int inclinacion_y;
int promx;
int promy;

//Constructor
LedControl ledMatrix = LedControl(DATO_PIN,CLK_PIN,CS_PIN,1);

const byte desnivelmenos5[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11000001,
  B11000001,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmenos4[8] = {
  B00000000,
  B00000000,
  B11111111,
  B11100001,
  B11100001,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmenos3[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10100001,
  B10100001,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmenos2[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10110001,
  B10110001,
  B11111111,
  B00000000,
  B00000000
  };

const byte desnivelmenos1[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10010001,
  B10010001,
  B11111111,
  B00000000,
  B00000000
  };

const byte centrado[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10011001,
  B10011001,
  B11111111,
  B00000000,
  B00000000};

const byte desnivelmas1[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10001001,
  B10001001,
  B11111111,
  B00000000,
  B00000000};

const byte desnivelmas2[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10001101,
  B10001101,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmas3[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10000101,
  B10000101,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmas4[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10000111,
  B10000111,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelmas5[8] = {
  B00000000,
  B00000000,
  B11111111,
  B10000011,
  B10000011,
  B11111111,
  B00000000,
  B00000000
};

//Constructores
ADXL345 NIVEL = ADXL345();
void setup() {
   Serial.begin(9600);            
   NIVEL.powerOn();           
   NIVEL.setRangeSetting(4);       //Definir el rango

}

void loop() {
   nivelacion();
   animacion();
   
}

void nivelacion(){
  int sumax = 0;
//  int sumay = 0;
  int x, y, z;
  NIVEL.readAccel(&x, &y, &z);
    inclinacion_x = x;
//    inclinacion_y = y;
}

void animacion(){
  if((inclinacion_x < -8) && (inclinacion_x >= -10 )){  //Ya se cayo la casa
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmenos4[i]);
      }
  }
  
  if((inclinacion_x < -6) && (inclinacion_x >= -8 )){  //Demasiado Inclinado hacia la izquierda
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmenos4[i]);
      }
  }
  if((inclinacion_x < -4) && (inclinacion_x >= -6 )){  //Muy Inclinado hacia la izquierda
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmenos3[i]);
      }
  }

  if((inclinacion_x < -2) && (inclinacion_x >= -4 )){  //Poco Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmenos2[i]);
      }
  }
  
  if((inclinacion_x < 0) && (inclinacion_x >= -2 )){  //Muy poco Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmenos1[i]);
      }
  }
  
  if(inclinacion_x == 0){  //Correctamente Nivelado
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, centrado[i]);
      }
  }

  if((inclinacion_x > 0) && (inclinacion_x <= 2 )){  //Muy poco inclinado hacia la derecha
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmas1[i]);
      }
  }
  
  if((inclinacion_x > 2) && (inclinacion_x <= 4 )){  //Poco Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmas2[i]);
      }
  }

  if((inclinacion_x > 4) && (inclinacion_x <= 6 )){  //Muy Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmas3[i]);
      }
  }
  
  if((inclinacion_x > 6) && (inclinacion_x <= 8 )){  //Demasiado Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmas4[i]);
      }
  }
  if((inclinacion_x > 8) && (inclinacion_x <= 10 )){  //Demasiado Inclinado hacia la izquierda
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelmas4[i]);
      }
  }
}
