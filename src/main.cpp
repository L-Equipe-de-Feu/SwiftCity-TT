#include <Arduino.h>
#include <variables.h>
#include <segments.h>
#include <communication.h>
#include <string.h>
#include <ArduinoJson.h>

void setup()
{
  Serial.begin(BAUD);
  appelVariables();
}

void loop()
{
  Serial.print("OK\n");
  if (digitalRead(BOU_A_PIN) == HIGH)
  {
    Serial.print("Boutton A cliquer \n");
    Serial.println("Allumange de la LED1");
    digitalWrite(LED_1, HIGH);
    delay(2000);
    digitalWrite(LED_1, LOW);
  }

  if (digitalRead(BOU_B_PIN) == HIGH)
  {
    Serial.print("Boutton B cliquer \n");
    Serial.print("Démarrage test de 7 segments \n");
    for (int i = 1; i < 4; i++)
    {
      testaffichage(i);
    }
  }

  if (digitalRead(BOU_M_PIN) == HIGH)
  {
    Serial.print("Boutton M cliquer \n");
  }

  if (digitalRead(BOU_S_PIN) == HIGH)
  {
    Serial.print("Boutton S cliquer \n");
  }

  if (digitalRead(BOU_ARD_PIN) == HIGH)
  {
    Serial.print("Boutton ARD cliquer \n");
  }

  if (digitalRead(BOU_ARG_PIN) == HIGH)
  {
    Serial.print("Boutton ARG cliquer \n");
  }

  if (analogRead(JOY_GD_PIN > 1))
  {
    Serial.print("Valeur de joystick Gauche-Droit");
    Serial.print(digitalRead(JOY_GD_PIN));
    Serial.println();
  }

  if (analogRead(JOY_HB_PIN > 1))
  {
    Serial.print("Valeur de joystick Haut-Bas");
    Serial.print(digitalRead(JOY_HB_PIN));
    Serial.println();
  }
}

/*---------------------------- Fonctions "Main" -----------------------------*/

//void setup() {
// Serial.begin(BAUD);               // Initialisation de la communication serielle
//  pinMode(pinLED, OUTPUT);
//  digitalWrite(pinLED, ledState);
//}

/* Boucle principale (infinie) */
//void loop() {
//
//  if(shouldRead_){
//    readMsg();
//    sendMsg();
//  }
//
//  potValue = analogRead(pinPOT);
//  //Serial.println(potValue);          // debug
//  delay(10);  // delais de 10 ms
//}
