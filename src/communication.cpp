#include <communication.h>

  void Communication::serialReadReady() { shouldRead_ = true; }
  void Communication::serialSendReady() { shouldSend_ = true; }

  void Communication::sendMsg() {
    StaticJsonDocument<500> doc;
    // Elements du message
    //doc["time"] = millis();
    doc["Bouton A"] = etatBoutonA;
    doc["Bouton B"] = etatBoutonB;
    doc["Bouton Menu"] = etatBoutonM;
    doc["Bouton Pause"] = etatBoutonP;
    doc["Bouton Arriere Droit"] = etatBoutonARD;
    doc["Bouton Arriere Gauche"] = etatBoutonARG;
    doc["Joystick"] = etatJoystick;
    doc["Accelerometre"] = etatAcc;

    // Serialisation
    serializeJson(doc, Serial);

    // Envoie
    Serial.println();
    //shouldSend_ = false;
  }

  void Communication::readMsg(){
    // Lecture du message Json
    StaticJsonDocument<500> doc;
    JsonVariant parse_time, parse_vitesse;

    // Lecture sur le port Seriel
    DeserializationError error = deserializeJson(doc, Serial);
    //shouldRead_ = false;

    // Si erreur dans le message
    if (error) {
      Serial.print("deserialize() failed: ");
      Serial.println(error.c_str());
      return;
    }
    
    // Analyse des éléments du message message
    parse_time = doc["time"];
    parse_vitesse = doc["vitesse"];
    if (!parse_time.isNull() && !parse_vitesse.isNull()) {
      time = parse_time;
      vitesse = parse_vitesse;
    }
  }