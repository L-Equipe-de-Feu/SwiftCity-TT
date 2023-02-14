#include <Arduino.h>
#include <variables.h>
#include <segments.h>
#include <communication.h>
#include <string.h>
#include <ArduinoJson.h>

// Appel des variables pour le debounce
int BOU_A = HIGH;
int BOU_B = HIGH;
int BOU_M = HIGH;
int BOU_S = HIGH;
int BOU_ARD = HIGH;
int BOU_ARG = HIGH;
int STATE_BOU_A = -1;
int STATE_BOU_B = -1;
int STATE_BOU_M = -1;
int STATE_BOU_S = -1;
int STATE_BOU_ARD = -1;
int STATE_BOU_ARG = -1;
long lastDebounceTime_A = 0;
long lastDebounceTime_B = 0;
long lastDebounceTime_M = 0;
long lastDebounceTime_S = 0;
long lastDebounceTime_ARD = 0;
long lastDebounceTime_ARG = 0;
long lastDebounceTime_SEND = 0;
unsigned long debouceDelay = 20;
unsigned long SendTime = 50;

// Appel des variables pour le compteur et le debounce
unsigned long previousMillis = 0;

void setup()
{
  Serial.begin(BAUD);
  appelVariables();
  LOWSET();
}

void loop()
{
  Communication com;

  int VitesseSegments = 1;
  int ValeurSegments = 0000;
  unsigned long currentMillis = millis();

  // Appel des 7 segments avec le calcul de vitesse
  if (com.vitesse != VitesseSegments)
  {
    // VitesseSegments = com.vitesse;
  }

  VitesseEtAppel(VitesseSegments, &previousMillis, &currentMillis);

  // Set manuellement les chiffre sur 7 segments
  if (com.time != ValeurSegments)
  {
    ValeurSegments = com.time;
    // SetTemp(ValeurSegments[0], ValeurSegments[1], ValeurSegments[2], ValeurSegments[3]);
  }

  BOU_A = digitalRead(BOU_A_PIN);
  BOU_B = digitalRead(BOU_B_PIN);
  BOU_M = digitalRead(BOU_M_PIN);
  BOU_S = digitalRead(BOU_S_PIN);
  BOU_ARD = digitalRead(BOU_ARD_PIN);
  BOU_ARG = digitalRead(BOU_ARG_PIN);

  // Code pour bouton A
  if ((currentMillis - lastDebounceTime_A) > debouceDelay)
  {
    if ((BOU_A == LOW) && (STATE_BOU_A < 0))
    {
      // Debounce
      lastDebounceTime_A = millis();
      STATE_BOU_A = -STATE_BOU_A;

      // Action
      Serial.write("A;");
    }
    else if ((BOU_A == HIGH) && (STATE_BOU_A > 0))
    {
      // Debounce
      lastDebounceTime_A = millis();
      STATE_BOU_A = -STATE_BOU_A;
    }
  }

  // Code pour bouton B
  if ((currentMillis - lastDebounceTime_B) > debouceDelay)
  {
    if ((BOU_B == LOW) && (STATE_BOU_B < 0))
    {
      // Debounce
      lastDebounceTime_B = millis();
      STATE_BOU_B = -STATE_BOU_B;

      // Action
      Serial.write("B;");
    }
    else if ((BOU_B == HIGH) && (STATE_BOU_B > 0))
    {
      // Debounce
      lastDebounceTime_B = millis();
      STATE_BOU_B = -STATE_BOU_B;
    }
  }

  // Code pour bouton M
  if ((currentMillis - lastDebounceTime_M) > debouceDelay)
  {
    if ((BOU_M == LOW) && (STATE_BOU_M < 0))
    {
      // Debounce
      lastDebounceTime_M = millis();
      STATE_BOU_M = -STATE_BOU_M;

      // Action
      Serial.write("M;");
    }
    else if ((BOU_M == HIGH) && (STATE_BOU_M > 0))
    {
      // Debounce
      lastDebounceTime_M = millis();
      STATE_BOU_M = -STATE_BOU_M;
    }
  }

  // Code pour bouton S
  if ((currentMillis - lastDebounceTime_S) > debouceDelay)
  {
    if ((BOU_S == LOW) && (STATE_BOU_S < 0))
    {
      // Debounce
      lastDebounceTime_S = millis();
      STATE_BOU_S = -STATE_BOU_S;

      // Action
      Serial.write("S;");
    }
    else if ((BOU_S == HIGH) && (STATE_BOU_S > 0))
    {
      // Debounce
      lastDebounceTime_S = millis();
      STATE_BOU_S = -STATE_BOU_S;
    }
  }

  // Code pour bouton ARD
  if ((currentMillis - lastDebounceTime_ARD) > debouceDelay)
  {
    if ((BOU_ARD == LOW) && (STATE_BOU_ARD < 0))
    {
      // Debounce
      lastDebounceTime_ARD = millis();
      STATE_BOU_ARD = -STATE_BOU_ARD;

      // Action
      Serial.write("ARD;");
    }
    else if ((BOU_ARD == HIGH) && (STATE_BOU_ARD > 0))
    {
      // Debounce
      lastDebounceTime_ARD = millis();
      STATE_BOU_ARD = -STATE_BOU_ARD;
    }
  }

  // Code pour boutton ARG
  if ((currentMillis - lastDebounceTime_ARG) > debouceDelay)
  {
    if ((BOU_ARG == LOW) && (STATE_BOU_ARG < 0))
    {
      // Debounce
      lastDebounceTime_ARG = millis();
      STATE_BOU_ARG = -STATE_BOU_ARG;

      // Action
      Serial.write("ARG;");
    }
    else if ((BOU_ARG == HIGH) && (STATE_BOU_ARG > 0))
    {
      // Debounce
      lastDebounceTime_ARG = millis();
      STATE_BOU_ARG = -STATE_BOU_ARG;
    }
  }

  // Code pour Joystick G-D
  if (analogRead(JOY_GD_PIN) < 500 || analogRead(JOY_GD_PIN) > 524)
  {
    com.etatJoystick = "Jx" + String(analogRead(JOY_GD_PIN)) + "y" + String(analogRead(JOY_HB_PIN));
  }
  else
  {
    com.etatAcc = "Jx0y0z0";
  }

  // Code pour Acceleromètre
  if (analogRead(X_AXIS_PIN) < 500 || analogRead(X_AXIS_PIN) > 524 || analogRead(Y_AXIS_PIN) < 500 || analogRead(Y_AXIS_PIN) > 524 || analogRead(Z_AXIS_PIN) < 500 || analogRead(Z_AXIS_PIN) > 524)
  {
    com.etatAcc = "Cx" + String(analogRead(X_AXIS_PIN)) + "y" + String(analogRead(Y_AXIS_PIN)) + "z" + String(analogRead(Z_AXIS_PIN));
  }
  else
  {
    com.etatAcc = "Cx0y0z0";
  }

  if ((currentMillis - lastDebounceTime_SEND) > SendTime)
  {
    if (com.shouldSend_)
    {
      lastDebounceTime_SEND = millis();
      com.sendMsg();
    }
    else
    {
      lastDebounceTime_SEND = millis();
    }
  }
}

/*---------------------------- Fonctions "Main" -----------------------------*/

/*void loop() {
  Communication com;

  if (analogRead(JOY_GD_PIN) < 500 || analogRead(JOY_GD_PIN) > 524)
  {
    com.etatJoystick = "Jx" + String(analogRead(JOY_GD_PIN)) + "y" + String(analogRead(JOY_HB_PIN));
  }
  else
  {
    com.etatJoystick = "Jx0y0";
  }

  if (analogRead(JOY_GD_PIN) < 500 || analogRead(JOY_GD_PIN) > 524)
  {
    com.etatAcc = "Cx" + String(analogRead(X_AXIS_PIN)) + "y" + String(analogRead(Y_AXIS_PIN)) + "z" + String(analogRead(Z_AXIS_PIN));
  }
  else
  {
    com.etatAcc = "Cx0y0z0";
  }

  if (digitalRead(BOU_A_PIN) == HIGH)
  {
    com.etatBoutonA = BOU_A_ON;
  }
  else
  {
    com.etatBoutonA = BOU_A_OFF;
  }

  if (digitalRead(BOU_B_PIN) == HIGH)
  {
    com.etatBoutonB = BOU_B_ON;
  }
  else
  {
    com.etatBoutonB = BOU_B_OFF;
  }

  if (digitalRead(BOU_M_PIN) == HIGH)
  {
    com.etatBoutonM = BOU_M_ON;
  }
  else
  {
    com.etatBoutonM = BOU_M_OFF;
  }

  if (digitalRead(BOU_S_PIN) == HIGH)
  {
    com.etatBoutonP = BOU_P_ON;
  }
  else
  {
    com.etatBoutonP = BOU_P_OFF;
  }

  if (digitalRead(BOU_ARD_PIN) == HIGH)
  {
    com.etatBoutonARD = BOU_ARD_ON;
  }
  else
  {
    com.etatBoutonARD = BOU_ARD_OFF;
  }

  if (digitalRead(BOU_ARG_PIN) == HIGH)
  {
    com.etatBoutonARG = BOU_ARG_ON;
  }
  else
  {
    com.etatBoutonARG = BOU_ARG_OFF;
  }

  if(com.shouldSend_)
  {
    com.sendMsg();
  }

}*/
