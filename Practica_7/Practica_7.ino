/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Jose Ricardo Estrada Guay
*/

//Librerias
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h> 
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
//Directivas
#define btn1 8
#define btn2 9
#define btn3 7
#define luminaria1 14
#define luminaria2 15
#define Cantidad_Leds 7
#define pin_Led 6
#define RadarPin 16
#define pin_Servo 5
#define buzzer 13
int personacerca =0;
int value;
int estado1 = 0;
int estado2 = 0;
// Constructor
Adafruit_NeoPixel rueda(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
//Caracteres
byte puerta_cerrada[] = {
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B11111,
  B11111
};
byte puerta_entreabierta[] = {
  B11000,
  B11100,
  B11110,
  B11010,
  B11110,
  B11110,
  B11100,
  B11000
};
byte puerta_media[] = {
  B11000,
  B11100,
  B11110,
  B11010,
  B11110,
  B11110,
  B11100,
  B11000
};
byte puerta_abierta[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte luz_off[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110,
  B01110
};
byte luz_on[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110
};
byte Centigrados[] = {
  B01000,
  B10100,
  B01000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00011
};
byte persona_detectada[] = {
  B01000,
  B11100,
  B00000,
  B01110,
  B01110,
  B01110,
  B00100,
  B11111
};
byte persona_nodetec[] = {
  B10100,
  B01000,
  B10100,
  B01110,
  B01110,
  B01110,
  B00100,
  B11111
};
float medicion();
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensor(&ourWire); //Se declara una objeto para nuestro sensor
LiquidCrystal_I2C LCD_ESTRADA(0x27, 16, 2);
Servo Servo_Estrada; 
float temperatura;


void setup() {
  
  Servo_Estrada.attach(pin_Servo);
  pinMode(RadarPin, INPUT);
  rueda.begin();
  pinMode(luminaria1, OUTPUT);
  pinMode(luminaria2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);
sensor.begin(); 
LCD_ESTRADA.init(); 
LCD_ESTRADA.backlight(); 
 LCD_ESTRADA.createChar(1, puerta_abierta);
 LCD_ESTRADA.createChar(2, puerta_media);
 LCD_ESTRADA.createChar(3, puerta_cerrada);
 LCD_ESTRADA.createChar(4, luz_off);
 LCD_ESTRADA.createChar(5, luz_on);
 LCD_ESTRADA.createChar(6, Centigrados);
 LCD_ESTRADA.createChar(7, persona_detectada);
 LCD_ESTRADA.createChar(8, persona_nodetec);
 LCD_ESTRADA.setCursor(0,1);
  LCD_ESTRADA.print("Puerta:");
  LCD_ESTRADA.setCursor(9,1);
    LCD_ESTRADA.print("Luz 2");
    LCD_ESTRADA.write(5);
    LCD_ESTRADA.setCursor(9,0);
    LCD_ESTRADA.print("Luz 1");
    LCD_ESTRADA.write(4);
    Servo_Estrada.write(0);
 }
 
void loop() {
  value = digitalRead(RadarPin);
  luminarias();
  puerta();
  temperatura = medicion();
  luminarias();
  puerta();
LCD_ESTRADA.setCursor(0,0);
LCD_ESTRADA.print(temperatura);
LCD_ESTRADA.write(6);
luminarias();
puerta();
proximidad();
luminarias();
puerta();
}

float medicion(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print("Temperatura= ");
  Serial.print(temp);
  Serial.println(" C");
  delay(100);  
  return temp;
  }
void proximidad(){  
  if( value == LOW){
    LCD_ESTRADA.setCursor(7,0);
    LCD_ESTRADA.write(8);
     for(int i = 0; i < 7; i++){
      rueda.setPixelColor(i,rueda.Color(0,255,0));
          rueda.show();
          delay(1);
          rueda.setPixelColor(i,rueda.Color(0,50,0));
          rueda.show();
          delay(1);
      }
    }   
  if(value == HIGH){
    LCD_ESTRADA.setCursor(7,0);
    LCD_ESTRADA.write(7);
    digitalWrite(buzzer, HIGH);
    for(int i = 0; i < 7; i++){
      rueda.setPixelColor(i,rueda.Color(255,0,0));
          rueda.show();
          delay(1);
          rueda.setPixelColor(i,rueda.Color(50,0,0));
          rueda.show();
          delay(1); 
    }
    digitalWrite(buzzer, LOW);
    }if(personacerca == 0){
     
}
}
void luminarias(){
if(digitalRead(btn1) && estado1==0){  // si pulsador presionado y led apagado
    digitalWrite(luminaria1, LOW);          // se enciende el led 
    
    LCD_ESTRADA.setCursor(9,0);
    LCD_ESTRADA.print("Luz 1");
    LCD_ESTRADA.write(5);
    delay(300);
    estado1=1;                       // guardamos el estado encendido   
  } 
  if(digitalRead(btn1) && estado1==1){  // si pulsador presionado y led encendido

    digitalWrite(luminaria1, HIGH);           // se apaga el led 
    
    LCD_ESTRADA.setCursor(9,0);
    LCD_ESTRADA.print("Luz 1");
    LCD_ESTRADA.write(4);
    delay(300); 
    estado1=0;                       // guardamos el estado apagado   
  }
  if(digitalRead(btn2) && estado2==0){  // si pulsador presionado y led apagado
    digitalWrite(luminaria2, LOW);          // se enciende el led 
    
    LCD_ESTRADA.setCursor(9,1);
    LCD_ESTRADA.print("Luz 2");
    LCD_ESTRADA.write(5); 
    delay(300);
    estado2=1;                       // guardamos el estado encendido   
  } 
  if(digitalRead(btn2) && estado2==1){  // si pulsador presionado y led encendido

    digitalWrite(luminaria2, HIGH);           // se apaga el led 
    
    LCD_ESTRADA.setCursor(9,1);
    LCD_ESTRADA.print("Luz 2");
    LCD_ESTRADA.write(4); 
    delay(300);
    estado2=0;                       // guardamos el estado apagado   
  }
}
void puerta(){
  if(digitalRead(btn3)==HIGH){
  Servo_Estrada.write(90);
    LCD_ESTRADA.setCursor(0,1);
    LCD_ESTRADA.print("Puerta:");
    LCD_ESTRADA.write(3);
    delay(100);
    LCD_ESTRADA.setCursor(0,1);
    LCD_ESTRADA.print("Puerta:");
    LCD_ESTRADA.write(2);
    delay(100);
    LCD_ESTRADA.setCursor(0,1);
    LCD_ESTRADA.print("Puerta:");
    LCD_ESTRADA.write(1); 
    delay(2000);
    Servo_Estrada.write(0);
    LCD_ESTRADA.setCursor(0,1);
    LCD_ESTRADA.print("Puerta:");
    LCD_ESTRADA.write(1);
    delay(100);
    LCD_ESTRADA.setCursor(0,1);
    LCD_ESTRADA.print("Puerta:");
    LCD_ESTRADA.write(2);
    delay(100);
    LCD_ESTRADA.setCursor(0,1);
    LCD_ESTRADA.print("Puerta:");
    LCD_ESTRADA.write(3);
    delay(1000); 
    Servo_Estrada.write(0);
  } else{
    Servo_Estrada.write(0);
    }
}
