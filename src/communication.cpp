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

  char JOY[Taille_Joystick];
  char ACC[Taille_Acc];

  // Copy it over
  etatJoystick.toCharArray(JOY, Taille_Joystick);
  etatAcc.toCharArray(ACC, Taille_Acc);

  //JOY[Taille_Joystick - 1] = '\0';
  //ACC[Taille_Acc - 1] = '\0';

  Serial.write(JOY);
  Serial.write(ACC);
}

void Communication::readMsg()
{
  char buffer;

  if (Serial.available() > 0)
  {
    buffer = char(Serial.read());

    if (buffer == 'T')
    {
      while (Serial.available() < 7)
        ;
      for (int i = 0; i <= 3; i++)
      {
        buffer = char(Serial.read());
        date[i] = int(buffer);
      }
      for (int i = 0; i <= 1; i++)
      {
        buffer = Serial.read();
        vitesse[i] = int(buffer);
      }
    }
  }
}