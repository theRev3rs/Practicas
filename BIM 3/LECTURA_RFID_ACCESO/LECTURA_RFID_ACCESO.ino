//Librerias
#include <SPI.h>
#include <MFRC522.h>


//Directivas
#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
#define voltaje A0   //Pin Sensor de voltaje
#define corriente A1 //Pin sensor de corriente

//Variables
float Sensibilidad=0.185;

//Constructores
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522

void setup() {
  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Acceso: Estado del circuito");
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0xC3, 0xF7, 0x35, 0xAD} ; //código del usuario 1
byte Usuario2[4]= {0x22, 0xB9, 0xC9, 0x34} ; //código del usuario 2
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
                    calculos();
                    }
                  else if(compareArray(ActualUID,Usuario2)){
                    Serial.println("Verificado: Quim");
                    calculos();
                    }
                  else{
                    Serial.println("Acceso denegado...");
                  }
                  // Terminamos la lectura de la tarjeta tarjeta  actual
                  mfrc522.PICC_HaltA();
          
            }
      
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
  
  float voltaje =  (float)15*analogRead(A0)/1023;
  Serial.print("Voltaje: ");
  Serial.print(voltaje);
  Serial.println(" V");
  delay(500);

  float voltajeSensor= analogRead(A1)*(5 / 1023.0); //lectura del sensor   
  float I=abs((voltajeSensor-2.5)/Sensibilidad); //Ecuación  para obtener la corriente
  Serial.print("Corriente: ");
  Serial.print(I,3);   //3 decimales
  Serial.println(" A");
  delay(200); 

  float P = voltaje * I;
  Serial.print("Potencia: ");
  Serial.print(P); 
  Serial.println(" W"); 
  }
