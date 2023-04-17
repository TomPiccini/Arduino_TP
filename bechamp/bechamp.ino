int i=0;
int f=0;
void setup() {
  pinMode(0, OUTPUT);     

}

void loop() {
   for (int i = 0;i <= 100; i += 10) {
      f=map(i,0,100,0,255);
      analogWrite(0,f);
      delay(50);
  }
   for (int i = 100;i > 0; i -= 10) {
      f=map(i,0,100,0,255);
      analogWrite(0,f);
      delay(50);
     
  }
}
