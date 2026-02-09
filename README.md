# Smart Home Monitoring System

## Présentation
Le **Smart Home Monitoring System** est un projet basé sur Arduino permettant de surveiller les conditions environnementales d’une pièce et de contrôler des équipements via une interface web.

Le système utilise l’**API Web Serial** pour établir une communication directe entre le navigateur et le microcontrôleur, sans nécessiter de serveur backend ni d’installation logicielle supplémentaire.  
Ce projet illustre l’intégration efficace entre **systèmes embarqués** et **technologies web modernes** pour concevoir un prototype de domotique simple et interactif.

---

## Fonctionnalités
- **Surveillance de la température et de l’humidité** grâce au capteur DHT11  
- **Mesure de la luminosité ambiante** via une photorésistance (LDR)  
- **Contrôle d’un éclairage** avec une LED simulant une lampe domestique  
- **Commande d’un servomoteur** pour simuler l’ouverture et la fermeture d’une porte  
- **Tableau de bord web** pour la lecture des capteurs et le pilotage des actionneurs  
- **Communication série directe** entre le navigateur et l’Arduino  

---

## Architecture du système

Le microcontrôleur agit comme **unité centrale de contrôle** :

**Entrées (Capteurs) :**
- DHT11 → température et humidité  
- LDR → intensité lumineuse  

**Sorties (Actionneurs) :**
- LED → gestion de l’éclairage  
- Servomoteur → simulation de contrôle d’accès  

**Couche de communication :**
- Connexion USB série (9600 bauds)  
- Protocole de commandes textuelles  

---

## Matériel requis

| Composant | Broche |
|------------|---------|
| Carte compatible Arduino | — |
| Capteur DHT11 | D3 |
| LED | D4 |
| Servomoteur | D5 |
| Photorésistance (LDR) | A0 |

---

## Commandes série supportées

| Commande | Action |
|------------|---------|
| `light_on` / `light_off` | Allumer ou éteindre la LED |
| `get_temperature` | Récupérer la température |
| `get_humidity` | Récupérer l’humidité |
| `get_light` | Lire la luminosité |
| `open` / `close` | Faire pivoter le servomoteur (0° à 180°) |

---

## Installation

### 1. Configuration matérielle
- Réaliser le câblage en respectant la configuration des broches définie dans `HOME_control.ino`.
- Connecter la carte Arduino à l’ordinateur via USB.

### 2. Téléversement du firmware
1. Ouvrir `HOME_control.ino` avec l’IDE Arduino.  
2. Installer les bibliothèques nécessaires :
   - `Servo`
   - `DHT`
3. Compiler puis téléverser le programme sur la carte.

### 3. Lancer l’interface web
1. Ouvrir `IHMcontrol.html` dans un navigateur compatible (**Chrome ou Edge recommandé**).
2. Cliquer sur **"Établir la connexion"**.
3. Sélectionner le port série correspondant à l’Arduino.
4. Utiliser le tableau de bord pour lire les capteurs ou contrôler les périphériques.

---

## Structure du projet
├── HOME_control.ino # Firmware Arduino (gestion des capteurs, traitement des commandes, pilotage des actionneurs)
└── IHMcontrol.html # Interface web utilisant l’API Web Serial

---

## Technologies utilisées
- Arduino (C/C++ embarqué)
- HTML5 / JavaScript
- API Web Serial
- Capteurs analogiques et numériques

---

## Améliorations possibles
- Adoption d’un format de messages structuré (JSON)
- Enregistrement et visualisation des données
- Communication sans fil (ESP32 / Wi-Fi)
- Interface responsive pour mobile
- Ajout d’un mécanisme d’authentification

---

## Intérêt pédagogique
Ce projet constitue un excellent support pour apprendre :

- les bases des systèmes embarqués  
- la communication série  
- l’intégration matériel–logiciel  
- l’interaction navigateur ↔ microcontrôleur  
- les principes fondamentaux de la domotique  

---
