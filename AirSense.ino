#include <Wire.h>                     // Communication I2C
#include <LiquidCrystal_I2C.h>        // Écran LCD I2C
#include <DHT.h>                      // Capteur DHT

#define DHTPIN 4                      // Pin GPIO pour DHT
#define DHTTYPE DHT22                 // Type de capteur

DHT dht(DHTPIN, DHTTYPE);             // Initialisation du capteur DHT
LiquidCrystal_I2C lcd(0x27, 16, 2);   // Initialisation de l'écran LCD

void setup() {
  Serial.begin(115200);               // Initialisation de la communication série
  dht.begin();                        // Initialisation du capteur DHT
  
  lcd.init();                         // Initialisation de l'écran LCD
  lcd.setBacklight(true);             // Activation du rétroéclairage
  
  lcd.setCursor(0, 0);
  lcd.print("Projet 3 :");            // Message d'accueil
  lcd.setCursor(6, 1);
  lcd.print("AirSense");
  delay(2000);                        // Affichage initial
  lcd.clear();
}

void loop() {
  char tempStr[6];
  float temperature = dht.readTemperature();   // Lecture de la température
  float humidite = dht.readHumidity();         // Lecture de l'humidité

  if (isnan(temperature) || isnan(humidite)) {
    Serial.println("Erreur de lecture du capteur DHT!");
    lcd.clear();
    lcd.print("Erreur de capteur");
    delay(2000);              // Affichage de l'erreur
    return;
  }
  
  sprintf(tempStr, "%6.2f", temperature);  // Formatage 

  // Affichage sur le moniteur série
  Serial.print("Température: ");
  Serial.print(tempStr);
  Serial.print(" °C\tHumidité: ");
  Serial.print(humidite);
  Serial.println(" %");

  // Affichage sur l'écran LCD
  lcd.setCursor(0, 0); 
  lcd.print("Temp : ");
  lcd.print(tempStr);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humide: ");
  lcd.print(humidite);
  lcd.print(" %");

  delay(2000);                 // Fréquence de 0.5Hz
}
