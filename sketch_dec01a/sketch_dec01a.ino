#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
const int oneWireBus = 16;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
const char* ssid = "BTSSN1_WIFI";
const char* mdp = "22aaBB--";
int status = WL_IDLE_STATUS;
const int s0 = 19;
const int s1 = 18;
const int out = 15;
const int s2 = 2;
const int s3 = 4;
int red,blue,green,white;

void setup() {
 // Start the Serial Monitor
 Serial.begin(115200);
 pinMode(s0, OUTPUT);
 pinMode(s1, OUTPUT);
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 digitalWrite(s0, HIGH);
 digitalWrite(s1, HIGH);
 sensors.begin();
 WiFi.begin(ssid, mdp);

 Serial.println("Connection au serveur WiFi");
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.println("...");
 }
 Serial.print("Conecté à ");
 Serial.println(ssid);
 Serial.print("Adresse IP : ");
 Serial.println(WiFi.localIP());
 Serial.println();
}

void loop() {
 color();
 delay(500);
 Serial.println();
 envoival(color());
 delay(5000);
}

void color()
{
  //red
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(50); 
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  //blue
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH); 
  delay(50);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  //green
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  delay(50);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  //white
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(50);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  green=color;
  if(red<blue && red<green)
  Serial.println("color: Red");
  color=red
  else if(blue<red && blue<green)
  Serial.println("color: Blue");
  color=blue
  else if(green<red && green<blue)
  Serial.println("color: Green");
  color=green
  else if(white<10)
  Serial.println("color: White");
  color=white
  else
  Serial.println("color: Not Defined");
  color=notfound

}

 void envoival(float color){
 Serial.println("Envoi en cours...");
 const char* nomServer = "http://192.168.10.34/scripts/wifi/wifi.php";
 if(WiFi.status()== WL_CONNECTED){
 HTTPClient http;
 http.begin(nomServer);
 http.addHeader("Content-Type", "application/x-www-form-urlencoded");

 String postData = "color=" + String(temp);

 int httpCode = http.POST(postData);
 String valeur_transmise = http.getString();

 Serial.println("...");
 Serial.print("Valeur transmise : ");
 Serial.println("couleur");
 Serial.print(valeur_transmise);
 Serial.print("Code http de retour : ");
 Serial.println(httpCode);
 Serial.println("---------");
 Serial.println();

 http.end();
 }
 }
