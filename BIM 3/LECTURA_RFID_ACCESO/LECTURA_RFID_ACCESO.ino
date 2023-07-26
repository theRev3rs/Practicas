//Librerias
#include <SPI.h>
#include <Wire.h>
#include <MFRC522.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#define direccion_lcd 0x3F
#define filas 2
#define columnas 16

//Directivas
#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
#define pinvoltaje A0   //Pin Sensor de voltaje
#define corriente A7 //Pin sensor de corriente
#define configRTC 6  //Pin para activar la configuracion del RTC

//Variables
float Sensibilidad = 0.185;

byte Year ;
byte Month ;
byte Date ;
byte DoW ;
byte Hour ;
byte Minute ;
byte Second ;
bool Century  = false;
bool h12 ;
bool PM ;

byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0xC3, 0xF7, 0x35, 0xAD} ; //código del usuario 1
byte Usuario2[4]= {0x22, 0xB9, 0xC9, 0x34} ; //código del usuario 2

//Constructores
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522
DS3231 Clock;
LiquidCrystal_I2C PANTALLA_MEDIDOR(direccion_lcd, columnas, filas);

void setup() {
  Wire.begin();
  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("EEGSA - KINAL");
  pinMode(pinvoltaje, INPUT);
  pinMode(corriente, INPUT);
  pinMode(configRTC, INPUT);
  PANTALLA_MEDIDOR.init();
  PANTALLA_MEDIDOR.backlight();

  if(digitalRead(configRTC) == HIGH){
    setDate();
    }

    PANTALLA_MEDIDOR.setCursor(0,0);
    PANTALLA_MEDIDOR.print(" EEGSA - KINAL  ");
    PANTALLA_MEDIDOR.setCursor(0,1);
    PANTALLA_MEDIDOR.print("                ");
}


void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  } 
                  Serial.print("     ");                 
                  //comparamos los UID para determinar si es uno de nuestros usuarios  
                  if(compareArray(ActualUID,Usuario1)){
                    Serial.println("Verificado: Estrada");
                      Serial.print("Fecha de acceso: ");
                      Serial.print(Clock.getDate(), DEC);
                      Serial.print("/");
                      Serial.print(Clock.getMonth(Century), DEC);
                      Serial.print(" ");
                      Serial.print(Clock.getHour(h12, PM), DEC); //24-hr
                      Serial.print(":");
                      Serial.print(Clock.getMinute(), DEC);
                      Serial.print(":");
                      Serial.println(Clock.getSecond(), DEC);
                    calculos();
                    }
                  else if(compareArray(ActualUID,Usuario2)){
                    Serial.println("Verificado: Quim");
                      Serial.print("Fecha de acceso: ");
                      Serial.print(Clock.getDate(), DEC);
                      Serial.print("/");
                      Serial.print(Clock.getMonth(Century), DEC);
                      Serial.print(" ");
                      Serial.print(Clock.getHour(h12, PM), DEC); //24-hr
                      Serial.print(":");
                      Serial.print(Clock.getMinute(), DEC);
                      Serial.print(":");
                      Serial.println(Clock.getSecond(), DEC);
                    calculos();
                    }
                  else{
                    Serial.println("Acceso denegado...");
                    PANTALLA_MEDIDOR.setCursor(0,1);
                    PANTALLA_MEDIDOR.print("USUARIO INVALIDO");
                    Serial.print("Fecha de intento de acceso: ");
                      Serial.print(Clock.getDate(), DEC);
                      Serial.print("/");
                      Serial.print(Clock.getMonth(Century), DEC);
                      Serial.print(" ");
                      Serial.print(Clock.getHour(h12, PM), DEC); //24-hr
                      Serial.print(":");
                      Serial.print(Clock.getMinute(), DEC);
                      Serial.print(":");
                      Serial.println(Clock.getSecond(), DEC);
                    delay(2000);
                  }
                  // Terminamos la lectura de la tarjeta tarjeta  actual
                  mfrc522.PICC_HaltA();
          
            }
            
  }
  else{
              PANTALLA_MEDIDOR.setCursor(0,0);
              PANTALLA_MEDIDOR.print(" EEGSA - KINAL  ");
              PANTALLA_MEDIDOR.setCursor(0,1);
              PANTALLA_MEDIDOR.print("MEDIDOR ENERGIA ");
              
              }
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}

void calculos(){
//  Voltaje
  PANTALLA_MEDIDOR.setCursor(0,1);
  PANTALLA_MEDIDOR.print("                ");
  PANTALLA_MEDIDOR.setCursor(2,1);
  PANTALLA_MEDIDOR.print("V: ");
  float voltaje =  (float)25*analogRead(pinvoltaje)/1023;
  PANTALLA_MEDIDOR.print(voltaje);
  PANTALLA_MEDIDOR.print(" V   ");
  delay(5000); 
//  Corriente
  PANTALLA_MEDIDOR.setCursor(2,1);
  PANTALLA_MEDIDOR.print("I: ");
  float med = analogRead(corriente)*(5.0/1023.0);
  float I = abs((2.5 - med)/Sensibilidad);
  if(abs(I) >= 1 ){
  PANTALLA_MEDIDOR.print(I,3);
  PANTALLA_MEDIDOR.print(" A   ");
  }
  if(abs(I) < 1 ){
  PANTALLA_MEDIDOR.print(I*1000,0);
  PANTALLA_MEDIDOR.print(" mA   ");
  }
  delay(5000);
//  Potencia
  PANTALLA_MEDIDOR.setCursor(2,1);
  float P = voltaje * I;
  PANTALLA_MEDIDOR.print("P: ");
  if(abs(P) >= 1 ){
  PANTALLA_MEDIDOR.print(I,3);
  PANTALLA_MEDIDOR.print(" W   ");
  }
  if(abs(P) < 1 ){
  PANTALLA_MEDIDOR.print(P*1000,0);
  PANTALLA_MEDIDOR.print(" mW   ");
  }
  delay(5000);

  }

  void setDate( ) { /* function setDate */
  ////Set Real Time Clock
  if (digitalRead(configRTC) == HIGH) {

    //int _start = millis();

    GetDateStuff(Year, Month, Date, DoW, Hour, Minute, Second);

    Clock.setClockMode(false);  // set to 24h

    Clock.setSecond(Second);
    Clock.setMinute(Minute);
    Clock.setHour(Hour);
    Clock.setDate(Date);
    Clock.setMonth(Month);
    Clock.setYear(Year);
    Clock.setDoW(DoW);

  }
}

void GetDateStuff(byte& Year, byte& Month, byte& Day, byte& DoW, byte& Hour, byte& Minute, byte& Second) { /* function GetDateStuff */
  ////Get date data
  // Call this if you notice something coming in on
  // the serial port. The stuff coming in should be in
  // the order YYMMDDwHHMMSS, with an 'x' at the end.
  boolean GotString = false;
  char InChar;
  byte Temp1, Temp2;
  char InString[20];

  byte j = 0;
  while (!GotString) {
    if (Serial.available()) {
      InChar = Serial.read();
      InString[j] = InChar;
      j += 1;
      if (InChar == 'x') {
        GotString = true;
      }
    }
  }
  Serial.println(InString);
  // Read Year first
  Temp1 = (byte)InString[0] - 48;
  Temp2 = (byte)InString[1] - 48;
  Year = Temp1 * 10 + Temp2;
  // now month
  Temp1 = (byte)InString[2] - 48;
  Temp2 = (byte)InString[3] - 48;
  Month = Temp1 * 10 + Temp2;
  // now date
  Temp1 = (byte)InString[4] - 48;
  Temp2 = (byte)InString[5] - 48;
  Day = Temp1 * 10 + Temp2;
  // now Day of Week
  DoW = (byte)InString[6] - 48;
  // now Hour
  Temp1 = (byte)InString[7] - 48;
  Temp2 = (byte)InString[8] - 48;
  Hour = Temp1 * 10 + Temp2;
  // now Minute
  Temp1 = (byte)InString[9] - 48;
  Temp2 = (byte)InString[10] - 48;
  Minute = Temp1 * 10 + Temp2;
  // now Second
  Temp1 = (byte)InString[11] - 48;
  Temp2 = (byte)InString[12] - 48;
  Second = Temp1 * 10 + Temp2;
}
