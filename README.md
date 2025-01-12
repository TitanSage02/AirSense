# AirSense

AirSense est un projet basé sur un microcontrôleur ESP32, un capteur DHT22, et un écran LCD I2C pour surveiller en temps réel la température et l'humidité de l'air. Ce projet est idéal pour les débutants en électronique et IoT, et il peut être facilement 
étendu pour des applications domestiques ou industrielles.

Tester le projet ici : https://wokwi.com/projects/419885822855762945

## Composants nécessaires
- ESP32
- Capteur DHT22 (ou DHT11)
- Écran LCD I2C (16x2)
- Protoboard 830 points (Optionnel)
- Câbles de connexion
- Source d'alimentation (USB ou batterie)

## Schéma de câblage
1. **DHT22** :
   - VCC -> 5V sur l'ESP32
   - GND -> GND sur l'ESP32
   - Data -> GPIO4 sur l'ESP32

2. **Écran LCD I2C** :
   - VCC -> 5V sur l'ESP32
   - GND -> GND sur l'ESP32
   - SDA -> GPIO21 sur l'ESP32
   - SCL -> GPIO22 sur l'ESP32

## Installation des bibliothèques
Les bibliothèques suivantes doivent être installées via le **Library Manager** d'Arduino IDE :
- `DHT` : Pour interfacer avec le capteur DHT22/DHT11.
- `LiquidCrystal_I2C` : Pour interfacer avec l'écran LCD I2C.

## Code
Le code du projet est disponible dans le fichier `AirSense.ino`. Le programme lit la température et l'humidité du capteur DHT22, puis affiche les valeurs sur un écran LCD et les envoie au moniteur série.

### Fonctionnalités principales
- Lecture et affichage en temps réel de la température (°C) et de l'humidité relative (%).
- Affichage des messages d'erreur en cas de défaillance du capteur.
- Interface utilisateur simple et directe sur l'écran LCD.

## Usage
1. Téléversez le code sur l'ESP32 via Arduino IDE.
2. Connectez les composants selon le schéma de câblage.
3. Ouvrez le moniteur série (baud rate : 115200) pour voir les données en temps réel.
4. L'écran LCD affichera les mesures de température et d'humidité.

## Développement futur
- Ajout de la connectivité WiFi pour envoyer les données à une plateforme cloud.
- Intégration avec des services comme Blynk pour un suivi à distance.
- Ajout de fonctionnalités d'alerte en cas de dépassement de seuils de température ou d'humidité.

## Licence
Ce projet est sous licence MIT. Voir le fichier `LICENSE` pour plus de détails.

---

### Exemple de sortie
Moniteur Série :
```
Température:  25.00 °C    Humidité:  40.00 %
```

Écran LCD :
```
Temp : 25.00 C
Humide: 40.00 %
```

---

## Contribution
Les contributions sont les bienvenues ! N'hésitez pas à ouvrir une issue ou soumettre une pull request pour toute amélioration ou suggestion.



## Fichiers supplémentaires

1. **AirSense.ino** : Le fichier contenant le code Arduino du projet.
2. **LICENSE** : Un fichier de licence (MIT License) pour autoriser les utilisateurs à modifier et redistribuer le code.
3. **images/** : Un dossier contenant des images du montage matériel et du projet final pour illustration dans le README.


## Organisation des fichiers
```
AirSense/
│
├── AirSense.ino
├── README.md
├── LICENSE
└── images/
    ├── wiring_diagram.png
```