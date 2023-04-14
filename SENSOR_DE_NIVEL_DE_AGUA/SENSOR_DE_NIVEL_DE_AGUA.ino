#define sensor 8
#define bomba 11
#define vacio 4
#define lleno 5

void setup() {
 pinMode(sensor, INPUT);
 pinMode(bomba, OUTPUT);
 pinMode(vacio, OUTPUT);
 pinMode(lleno, OUTPUT);
}

void loop() {
  int estado;
  estado = digitalRead(sensor);
  if (estado == HIGH){
    digitalWrite(vacio, HIGH);
    digitalWrite(lleno, LOW);
    digitalWrite(bomba, HIGH);
    }
    estado = digitalRead(sensor);
  if (estado == LOW){
    digitalWrite(vacio, LOW);
    digitalWrite(lleno, HIGH);
    digitalWrite(bomba, LOW);
    delay(1000);
    } 
}
