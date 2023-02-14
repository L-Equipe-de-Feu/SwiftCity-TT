#include <communication.h>

void Communication::serialReadReady() { shouldRead_ = true; }
void Communication::serialSendReady() { shouldSend_ = true; }

void Communication::sendMsg()
{
  StaticJsonDocument<500> doc;
  // Elements du message
  // doc["time"] = millis();
  doc["Joystick"] = etatJoystick;
  doc["Accelerometre"] = etatAcc;

  // Serialisation (on change le Serial si on le veut à quelque part d'autre)
  // serializeJson(doc, Serial);

// Length (with one extra character for the null terminator)
int Taille_Joystick = etatJoystick.length() + 2; 
int Taille_Acc = etatAcc.length() + 2; 

char JOY[Taille_Joystick];
char ACC[Taille_Acc];

// Copy it over 
etatJoystick.toCharArray(JOY, Taille_Joystick);
etatAcc.toCharArray(ACC, Taille_Acc);
JOY[Taille_Joystick-2] = ';';
ACC[Taille_Acc-2] = ';';
JOY[Taille_Joystick-1] = '\0';
ACC[Taille_Acc-1] = '\0';


  Serial.write(JOY);
  Serial.write(ACC);
  Serial.print("\n");
  // Envoie
  // Serial.write(etatJoystick);
  // shouldSend_ = false;
}

void Communication::readMsg()
{
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_time, parse_vitesse;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  // shouldRead_ = false;

  // Si erreur dans le message
  if (error)
  {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }

  // Analyse des éléments du message message
  parse_time = doc["time"];
  parse_vitesse = doc["vitesse"];
  if (!parse_time.isNull() && !parse_vitesse.isNull())
  {
    time = parse_time;
    vitesse = parse_vitesse;
  }
}