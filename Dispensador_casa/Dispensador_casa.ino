/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Jose Ricardo Estrada Guay
Seccion: A
Carne: 2010553
*/
#define sig 6
#define prev 5
int i = 1;
struct item{
  unsigned int preciou;
  unsigned int stock;
  String nombre;
  unsigned int bodega;
  float precio_l;
};

item Coca;
item Oreo;
item Te_Lipton;
item Colgate;

void setup(){
  Serial.begin(9600);
  pinMode(sig, INPUT);
  pinMode(prev, INPUT);
  //Coca
  Coca.preciou = 2;
  Coca.stock = 23;
  Coca.nombre = "Coca-Cola";
  Coca.bodega = 34;
  Coca.precio_l = (Coca.preciou*23);
  //Oreo
  Oreo.preciou = 7;
  Oreo.stock = 15;
  Oreo.nombre = "Oreo 6 Colgates";
  Oreo.bodega = 29;
  Oreo.precio_l = (Oreo.preciou*11);
  //Te_Lipton
  Te_Lipton.preciou = 10;
  Te_Lipton.stock = 35;
  Te_Lipton.nombre = "Te Lipton 500ml";
  Te_Lipton.bodega = 19;
  Te_Lipton.precio_l = (Te_Lipton.preciou*15);
  
  //Colgate
  Colgate.preciou = 6;
  Colgate.stock = 28;
  Colgate.nombre = "Pasta Colgate 300ml";
  Colgate.bodega = 29;
  Colgate.precio_l = (Colgate.preciou*5.5);
  }
void loop(){
  int producto = i;
  if (digitalRead(sig) == 1){
     i++;
     }
  else if (digitalRead(prev)==1){
     i--;
     }
  else if ( i < 1){
    i = 4;
    }
  else if ( i > 4){
    i = 1;
    }
if (producto == 1){
  Serial.println("Producto no.1: ");
  Serial.println(Coca.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Coca.preciou);
  Serial.print("Stock: ");
  Serial.println(Coca.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(Coca.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Coca.precio_l);
  Serial.println("  ");
  delay(1000);
}
if (producto == 2){
  Serial.println("Producto no.2: ");
  Serial.println(Oreo.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Oreo.preciou);
  Serial.print("Stock: ");
  Serial.println(Oreo.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(Oreo.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Oreo.precio_l);
  Serial.println("  ");
  delay(1000);
}
if (producto == 3){
  Serial.println("Producto no.3: ");
  Serial.println(Te_Lipton.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Te_Lipton.preciou);
  Serial.print("Stock: ");
  Serial.println(Te_Lipton.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(Te_Lipton.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Te_Lipton.precio_l);
  Serial.println("  ");
  delay(1000);
}
if (producto == 4){
  Serial.println("Producto no.4: ");
  Serial.println(Colgate.nombre);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Colgate.preciou);
  Serial.print("Stock: ");
  Serial.println(Colgate.stock);
  Serial.print("Unidades en bodega: ");
  Serial.println(Colgate.bodega);
  Serial.print("Precio Unitario: Q.");
  Serial.println(Colgate.precio_l);
  Serial.println("  ");
  delay(1000);  
}else if ( producto > 4){
  i = 1;
  loop();
  }
  else if ( producto < 1){
  i = 4;
  loop();
  }
  }
