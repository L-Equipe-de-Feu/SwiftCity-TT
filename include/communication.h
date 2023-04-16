#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <Arduino.h>
#include <ArduinoJson.h>

class Communication
{
private:
  int cTi(char c);

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
  //char etatMuon[10];

  int date[4] = {1, 1, 1, 1};
  char Muon[11] = {'W', '0', '1', '0', '3', '0', '5', '0', '7', '0','\0'};
  int vitesse = 1;


  void sendMsg();
  void sendMsgMuon();
  void readMsg();
  void serialSendReady();
  void serialReadReady();
};

#endif