#include <Arduino.h>
#include <variables.h>
#include <segments.h>
#include <communication.h>
#include <string.h>
#include <ArduinoJson.h>

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
long debouceDelay = 10;

void setup()
{
  Serial.begin(BAUD);
  appelVariables();
}

void loop()
{
  BOU_A = digitalRead(BOU_A_PIN);
  BOU_B = digitalRead(BOU_B_PIN);
  BOU_M = digitalRead(BOU_M_PIN);
  BOU_S = digitalRead(BOU_S_PIN);
  BOU_ARD = digitalRead(BOU_ARD_PIN);
  BOU_ARG = digitalRead(BOU_ARG_PIN);

  if ((millis() - lastDebounceTime_A) > debouceDelay)
  {
    if ((BOU_A == LOW) && (STATE_BOU_A < 0))
    {
      lastDebounceTime_A = millis();
      STATE_BOU_A = -STATE_BOU_A;

      Serial.print("Boutton A cliquer \n");
      //Serial.println("Allumange de la LED1");
      //digitalWrite(LED_1, HIGH);
      //delay(2000);
      //digitalWrite(LED_1, LOW);
    }
    else if ((BOU_A == HIGH) && (STATE_BOU_A > 0))
    {
      lastDebounceTime_A = millis();
      STATE_BOU_A = -STATE_BOU_A;
    }
  }

  if ((millis() - lastDebounceTime_B) > debouceDelay)
  {
    if ((BOU_B == LOW) && (STATE_BOU_B < 0))
    {
      lastDebounceTime_B = millis();
      STATE_BOU_B = -STATE_BOU_B;

      Serial.print("Boutton B cliquer \n");
      Serial.print("Démarrage test de 7 segments \n");
      for (int i = 1; i < 4; i++)
      {
        testaffichage(i);
      }
    }
    else if ((BOU_B == HIGH) && (STATE_BOU_B > 0))
    {
      lastDebounceTime_B = millis();
      STATE_BOU_B = -STATE_BOU_B;
    }
  }

  if ((millis() - lastDebounceTime_M) > debouceDelay)
  {
    if ((BOU_M == LOW) && (STATE_BOU_M < 0))
    {
      lastDebounceTime_M = millis();
      STATE_BOU_M = -STATE_BOU_M;

      Serial.print("Boutton M cliquer \n");
    }
    else if ((BOU_M == HIGH) && (STATE_BOU_M > 0))
    {
      lastDebounceTime_M = millis();
      STATE_BOU_M = -STATE_BOU_M;
    }
  }

  if ((millis() - lastDebounceTime_S) > debouceDelay)
  {
    if ((BOU_S == LOW) && (STATE_BOU_S < 0))
    {
      lastDebounceTime_S = millis();
      STATE_BOU_S = -STATE_BOU_S;

      Serial.print("Boutton S cliquer \n");
    }
    else if ((BOU_S == HIGH) && (STATE_BOU_S > 0))
    {
      lastDebounceTime_S = millis();
      STATE_BOU_S = -STATE_BOU_S;
    }
  }

  if ((millis() - lastDebounceTime_ARD) > debouceDelay)
  {
    if ((BOU_ARD == LOW) && (STATE_BOU_ARD < 0))
    {
      lastDebounceTime_ARD = millis();
      STATE_BOU_ARD = -STATE_BOU_ARD;

      Serial.print("Boutton ARD cliquer \n");
    }
    else if ((BOU_ARD == HIGH) && (STATE_BOU_ARD > 0))
    {
      lastDebounceTime_ARD = millis();
      STATE_BOU_ARD = -STATE_BOU_ARD;
    }
  }

  if ((millis() - lastDebounceTime_ARG) > debouceDelay)
  {
    if ((BOU_ARG == LOW) && (STATE_BOU_ARG < 0))
    {
      lastDebounceTime_ARG = millis();
      STATE_BOU_ARG = -STATE_BOU_ARG;

      Serial.print("Boutton ARG cliquer \n");
    }
    else if ((BOU_ARG == HIGH) && (STATE_BOU_ARG > 0))
    {
      lastDebounceTime_ARG = millis();
      STATE_BOU_ARG = -STATE_BOU_ARG;
    }
  }

  /*if (analogRead(JOY_GD_PIN > 1))
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
  }*/
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
