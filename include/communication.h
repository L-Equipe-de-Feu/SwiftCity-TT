#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <Arduino.h>
#include <ArduinoJson.h>

class Communication
{

public:
  volatile bool shouldSend_ = true; // Drapeau prêt à envoyer un message
  volatile bool shouldRead_ = true; // Drapeau prêt à lire un message

  String etatBoutonA;
  String etatBoutonB;
  String etatBoutonM;
  String etatBoutonP;
  String etatBoutonARD;
  String etatBoutonARG;
  String etatJoystick;
  String etatAcc;

  int time;
  int vitesse;

  void sendMsg();
  void readMsg();
  void serialSendReady();
  void serialReadReady();
};

#endif