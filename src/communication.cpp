#include <communication.h>

void Communication::serialReadReady() { shouldRead_ = true; }
void Communication::serialSendReady() { shouldSend_ = true; }

void Communication::sendMsg()
{
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["Joystick"] = etatJoystick;
  doc["Accelerometre"] = etatAcc;

  // Serialisation (on change le Serial si on le veut à quelque part d'autre)
  // serializeJson(doc, Serial);

  // Length (with one extra character for the null terminator)
  int Taille_Joystick = etatJoystick.length() + 1;
  int Taille_Acc = etatAcc.length() + 1;
  //int Taille_Muon = etatMuon.length() + 1;

  char JOY[Taille_Joystick];
  char ACC[Taille_Acc];
  //char MUON[Taille_Muon];

  // Copy it over
  etatJoystick.toCharArray(JOY, Taille_Joystick);
  etatAcc.toCharArray(ACC, Taille_Acc);
  //etatMuon.toCharArray(MUON, Taille_Muon);

  // JOY[Taille_Joystick - 1] = '\0';
  // ACC[Taille_Acc - 1] = '\0';

  Serial.write(JOY);
  Serial.write(ACC);
  Serial.write(Muon);
  // Serial.write('\n');
}

void Communication::readMsg()
{
  char buffer;
  int chiffre;

  if (Serial.available() >= 7)
  {
    buffer = char(Serial.read());

    if (buffer == 'T')
    {
      for (int i = 0; i < 4; i++)
      {
        buffer = char(Serial.read());
        chiffre = cTi(buffer);
        date[i] = int(chiffre);
      }

      buffer = char(Serial.read());
      if (buffer == 'X')
      {
        buffer = char(Serial.read());
        chiffre = cTi(buffer);
        vitesse = int(chiffre);
      }
    }
  }
  if (Serial2.available() >= 10)
  {
    buffer = char(Serial2.read());

    if (buffer == 'W')
    {
      for (int i = 1; i < 10; i++)
      {
        Muon[i] = char(Serial2.read());
      }
      //etatMuon = Muon;
    }
  }
}


int Communication::cTi(char c)
{
  int i = c - '0';
  return i;
}