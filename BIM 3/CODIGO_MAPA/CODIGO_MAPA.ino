/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: RICARDO ESTRADA , HENRY ESQUITE
 * GRUPO: 1
 * Proyecto: MAPA INTERACTIVO
*/
//Librerias
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

//Directivas
#define buzz 9
#define pinNeo 6//Pin al que esta el NeoPixel
#define NUMPIXELS 22 //Cantidad de Neopixeles en la cadena
#define preguntas 22 //Cantidad de preguntas
#define ciclos 12  //Veces en las que los neopixels cambian de color
#define tpr 15 //Segundos Para Responder

//Variables
int num_pregunta;  //Numero de pregunta
String respondiendo;

//Funciones
int ruleta();  //Elije un numero de pregunta al azar (Nideah como se hace juas juas)
void responder();   //Muestra la pregunta en el BT espera respuesta y determina si es correcta o incorrecta
void correcta();  //La respuesta dada es correcta
void incorrecta(); //La respuesta es incorrecta
void contador_tpr();
//Constructores
Adafruit_NeoPixel pixels(NUMPIXELS, pinNeo, NEO_GRB + NEO_KHZ800); 

void setup() {
  pixels.begin();
  Serial.begin(9600);
  Serial.println("Primera pregunta");
}

void loop() {
  num_pregunta = ruleta();
  responder();
  delay(5000);
   Serial.println();
  Serial.println("Siguiente pregunta");
}
int ruleta(){
  int num_random;
    return num_random = random(0, 21); //Selecciona un numero de pregunta al azar
  }

void responder(){
  //https://aprende.guatemala.com/historia/geografia/departamentos-de-guatemala-cabeceras/
    if(num_pregunta == 0){
    Serial.println("Cabecera departamental de Petén");
    contador_tpr();
      if(respondiendo == String("Flores")){    //Respuesta correcta
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 1){
    Serial.println("Cabecera departamental de Izabal");
    contador_tpr();
      if(respondiendo == String("Puerto Barrios")){    //Respuesta correcta
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 2){
    Serial.println("Cabecera departamental de Alta Verapaz");
    contador_tpr();
      if(respondiendo == String("Coban")){    //Respuesta correcta
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 3){
    Serial.println("Cabecera departamental de Quiché");
    contador_tpr();
      if(respondiendo == String("Santa Cruz del Quiché")){   //Respuesta correcta
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 4){
    Serial.println("Cabecera departamental de Huehuetenango");
    contador_tpr();
      if(respondiendo == String("Huehuetenango")){  //Resuesta Correcta
        correcta();
      }
      else{
        incorrecta();
      }
      }
       if(num_pregunta == 5){
    Serial.println("Cabecera departamental de Escuintla");
    contador_tpr();
      if(respondiendo == String("Escuintla")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
        if(num_pregunta == 6 ){
    Serial.println("Cabecera departamental de San Marcos");
    contador_tpr();
      if(respondiendo == String("San Marcos")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 7 ){
    Serial.println("Cabecera departamental de Jutiapa");
    contador_tpr();
      if(respondiendo == String("Jutiapa")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 8 ){
    Serial.println("Cabecera departamental de Baja Verapaz");
    contador_tpr();
      if(respondiendo == String("Salama")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
       if(num_pregunta == 9 ){
    Serial.println("Cabecera departamental de Santa Rosa");
    contador_tpr();
      if(respondiendo == String("Cuilapa")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 10 ){
    Serial.println("Cabecera departamental de Zacapa");
    contador_tpr();
      if(respondiendo == String("Zacapa")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 11 ){
    Serial.println("Cabecera departamental de Suchitepéquez");
    contador_tpr();
      if(respondiendo == String("Mazatenango")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 12 ){
    Serial.println("Cabecera departamental de Chiquimula");
    contador_tpr();
      if(respondiendo == String("Chiquimula")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 13 ){
    Serial.println("Cabecera departamental de Guatemala");
    contador_tpr();
      if(respondiendo == String("Guatemala")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 14 ){
    Serial.println("Cabecera departamental de Jalapa");
    contador_tpr();
      Serial.println(respondiendo);
      if(respondiendo == String("Jalapa")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 15 ){
    Serial.println("Cabecera departamental de Chimaltenango");
    contador_tpr();
      if(respondiendo == String("Chimaltenango")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 16 ){
    Serial.println("Cabecera departamental de Quetzaltenango");
    contador_tpr();
      if(respondiendo == String("Quetzaltenango")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 17 ){
    Serial.println("Cabecera departamental de El progreso");
    contador_tpr();
      if(respondiendo == String("Guastatoya")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 18 ){
    Serial.println("Cabecera departamental de Retalhuleu");
    contador_tpr();
      if(respondiendo == String("Retalhuleu")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 19 ){
    Serial.println("Cabecera departamental de Sololá");
    contador_tpr();
      if(respondiendo == String("Solola")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 20 ){
    Serial.println("Cabecera departamental de Totonicapán");
    contador_tpr();
      if(respondiendo == String("Totonicapan")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
      if(num_pregunta == 21 ){
    Serial.println("Cabecera departamental de Sacatepéquez");
    contador_tpr();
      if(respondiendo == String("La antigua guatemala")){
        correcta();
      }
      else{
        incorrecta();
      }
      }
  }

void contador_tpr(){
  bool tiempo_agotado = false;
  int i = tpr;
  while((!Serial.available()>0) && tiempo_agotado == false){
    Serial.print(i);
    Serial.print("...");
    delay(1000);
    i--;
    if(i < 0){
      tiempo_agotado = true;
       Serial.println();
      Serial.println("Tiempo Agotado :( ");
      Serial.print("No hubo respuesta");
      }
    }
    Serial.println();
    respondiendo = Serial.readStringUntil('\n');
    if(tiempo_agotado == false){
      Serial.println("Respuesta recibida: " + respondiendo);
      }
  }
  
void correcta(){
  Serial.println("Respuesta Correcta");
  for(int i = 0; i < ciclos; i++ ){    //Patron de Neopixeles cuando se contesta bien
    int G = random(0,255);
    pixels.setPixelColor(num_pregunta, pixels.Color(0, G, 0));
    pixels.show();
    delay(100);
    }
    delay(100);
    pixels.setPixelColor(num_pregunta, pixels.Color(0, 0, 0));
    pixels.show();
  }
  
void incorrecta(){
  Serial.println("Respuesta Incorrecta");
  tone(buzz, 440);  //Aca iria la melodia si alguien la hubiera subido juas juas ( No Hate )
  delay(100);
  noTone(buzz);
  delay(1000);
   for(int i = 0; i < ciclos; i++ ){    //Patron de Neopixeles cuando se contesta bien
    int R = random(0,255);
    pixels.setPixelColor(num_pregunta, pixels.Color(R, 0, 0));
    pixels.show();
    delay(100);
    }
    delay(100);
    pixels.setPixelColor(num_pregunta, pixels.Color(0, 0, 0));
    pixels.show();
  }
