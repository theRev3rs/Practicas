#define in(pin) pinMode (pin, INPUT)
#define out(pin) pinMode (pin, OUTPUT)
#define ON(pin) digitalWrite (pin, HIGH)
#define OFF(pin) digitalWrite (pin, LOW)
#define b1 2
#define b2 3
#define R 4 
#define G 5
#define B 6

void setup() {
  in (b1);
  in (b2);
  out (R);
  out (G);
  out (B);
}

void loop() {
  int bt1; 
  bt1 = digitalRead (b1);
  int bt2; 
  bt2 = digitalRead (b2);


if (bt1 == HIGH && bt2 == LOW) {
    OFF(B);
    ON(R);
    ON (G);
    }
if (bt2 == HIGH && bt1 == LOW) {
    ON(B);
    ON (G);
    OFF(R);
    }
if (bt1 == HIGH && bt2 == HIGH){
  OFF(G);
  ON(B);
  ON (R);
  
}
if (bt1 == LOW && bt2 == LOW){
  OFF(G);
  OFF(B);
  ON(R); 
  delay (500);
  OFF(R); ON(G); 
  delay (500);
  OFF(G); ON(B); 
  delay (500);
  OFF(B); 
}
}
