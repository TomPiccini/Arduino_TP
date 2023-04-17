const int SENSOR_PIN = 36; // Broche de signal du capteur
const int PUMP_PIN = 2; // Broche de la pompe

void setup() {
  pinMode(SENSOR_PIN, INPUT); // Configuration de la broche du capteur en entrée
  pinMode(PUMP_PIN, OUTPUT); // Configuration de la broche de la pompe en sortie
  Serial.begin(9600); // Initialisation de la communication série pour le débogage
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN); // Lecture de la valeur du capteur
  if (sensorValue == LOW) { // Si une main est détecté
    digitalWrite(PUMP_PIN, LOW); // Activation de la pompe
    Serial.println("Main détectée, pompe activée."); // Message de débogage
    delay(900);
    digitalWrite(PUMP_PIN, HIGH);
    sensorValue == HIGH ;
    delay(5000);
  }
  else { // Si aucune main n'est détectée
    digitalWrite(PUMP_PIN, HIGH); // Désactivation de la pompe
    Serial.println("Main non détectée, pompe non activée."); // Message de débogage
  }
}
