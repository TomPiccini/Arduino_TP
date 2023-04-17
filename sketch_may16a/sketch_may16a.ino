int i=0;
int f=0;
int r=0;
void setup() {
  pinMode(3, OUTPUT);   
  pinMode(A0, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  f=analogRead(A0);
  i=map(f,0,1023,0,254 );
  r=map(i,0,254,0,100);
  analogWrite(3, i);

  if (r<23) {
   Serial.print("moteur off"); 
   Serial.print(":");
   Serial.print(r);
   Serial.print("%");
   Serial.println();
  }
  else {
   Serial.print("moteur on "); 
   Serial.print(":");
   Serial.print(r);
   Serial.print("%");
   Serial.println();
  }
}
