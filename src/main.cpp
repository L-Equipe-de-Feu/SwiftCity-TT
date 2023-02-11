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
    //Serial.print("Démarrage test de 7 segments \n");
    //for (int i = 1; i < 4; i++)
    //{
    //  testaffichage(i);
    //}
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
