#include <Arduino.h>
#include <variables.h>
#include <segments.h>
#include <communication.h>
#include <string.h>
#include <ArduinoJson.h>
#include <muon.h>

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
unsigned long SendTime = 100;

unsigned long debounceTimemicro1 = 525;
unsigned long muDetectTime = 33;

int Date_ref[4] = {1, 1, 1, 1};
int Vitesse_ref = 1;

// Appel des variables pour le compteur et le debounce
unsigned long previousMillis = 0;
unsigned long lastmicros = 0;

Communication com;
Muon m;

void setup()
{
  Serial.begin(BAUD);
  appelVariables();
  LOWSET();
}

void loop()
{
  unsigned long currentMillis = millis();
  unsigned long currentmicros = micros();

  com.readMsg();

  // Set manuellement les chiffre sur 7 segments
  if (com.date[0] != Date_ref[0] || com.date[1] != Date_ref[1] || com.date[2] != Date_ref[2] || com.date[3] != Date_ref[3])
  {
    Date_ref[0] = com.date[0];
    Date_ref[1] = com.date[1];
    Date_ref[2] = com.date[2];
    Date_ref[3] = com.date[3];
  }

  if (com.vitesse != Vitesse_ref)
  {
    Vitesse_ref = com.vitesse;
  }

  appel(Date_ref[0], Date_ref[1], Date_ref[2], Date_ref[3]);

  BOU_A = digitalRead(BOU_A_PIN);
  BOU_B = digitalRead(BOU_B_PIN);
  BOU_M = digitalRead(BOU_M_PIN);
  BOU_S = digitalRead(BOU_S_PIN);
  BOU_ARD = digitalRead(BOU_ARD_PIN);
  BOU_ARG = digitalRead(BOU_ARG_PIN);

  // Code pour LEDS
  if (Vitesse_ref == 1)
  {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  else if (Vitesse_ref == 2)
  {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  else if (Vitesse_ref == 3)
  {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  }
  else if (Vitesse_ref == 4)
  {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  }
  else
  {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }

  // Code pour bouton A
  if ((currentMillis - lastDebounceTime_A) > debouceDelay)
  {
    if ((BOU_A == LOW) && (STATE_BOU_A < 0))
    {
      // Debounce
      lastDebounceTime_A = millis();
      STATE_BOU_A = -STATE_BOU_A;

      // Action
      Serial.write("A");
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
      Serial.write("B");
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
      Serial.write("M");
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
      Serial.write("S");
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
      Serial.write("D");
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
      Serial.write("G");
    }
    else if ((BOU_ARG == HIGH) && (STATE_BOU_ARG > 0))
    {
      // Debounce
      lastDebounceTime_ARG = millis();
      STATE_BOU_ARG = -STATE_BOU_ARG;
    }
  }

  // Code pour Joystick G-D
  int maxjoy = 524;
  int minjoy = 500;
  if (analogRead(JOY_GD_PIN) < minjoy || analogRead(JOY_GD_PIN) > maxjoy || analogRead(JOY_HB_PIN) < minjoy || analogRead(JOY_HB_PIN) > maxjoy)
  {
    String GDRes, HBRes;
    if (analogRead(JOY_GD_PIN) < minjoy || analogRead(JOY_GD_PIN) > maxjoy)
    {
      int GD = analogRead(JOY_GD_PIN);

      GDRes = String(int(GD / 1000)) + String(int((GD % 1000) / 100)) + String(int((GD % 100) / 10)) + String(int((GD % 10)));
    }
    else
    {
      GDRes = String(9999);
    }

    if (analogRead(JOY_HB_PIN) < minjoy || analogRead(JOY_HB_PIN) > maxjoy)
    {
      int HB = analogRead(JOY_HB_PIN);
      HBRes = String(int(HB / 1000)) + String(int((HB % 1000) / 100)) + String(int((HB % 100) / 10)) + String(int((HB % 10)));
    }
    else
    {
      HBRes = String(9999);
    }
    com.etatJoystick = "Jx" + GDRes + "y" + HBRes;
  }
  else
  {
    com.etatJoystick = "Jx9999y9999";
  }

  // Code pour Acceleromètre
  if (analogRead(X_AXIS_PIN) <= 999 || analogRead(X_AXIS_PIN) >= 0 || analogRead(Y_AXIS_PIN) <= 999 || analogRead(Y_AXIS_PIN) >= 0 || analogRead(Z_AXIS_PIN) <= 999 || analogRead(Z_AXIS_PIN) >= 0)
  {
    int X = analogRead(X_AXIS_PIN);
    int Y = analogRead(Y_AXIS_PIN);
    int Z = analogRead(Z_AXIS_PIN);

    if (X > 676)
    {
      X = 676;
    }
    else
    {
      X = X;
    }
    if (Y > 676)
    {
      Y = 676;
    }
    else
    {
      Y = Y;
    }
    if (Z > 676)
    {
      Z = 676;
    }
    else
    {
      Z = Z;
    }

    String XRes, YRes, ZRes;
    XRes = String(int(X / 100)) + String(int((X % 100) / 10)) + String(int((X % 10)));
    YRes = String(int(Y / 100)) + String(int((Y % 100) / 10)) + String(int((Y % 10)));
    ZRes = String(int(Z / 100)) + String(int((Z % 100) / 10)) + String(int((Z % 10)));

    com.etatAcc = "Cx" + XRes + "y" + YRes + "z" + ZRes;
  }
  else
  {
    com.etatAcc = "Cx999y999z999";
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

  //Code pour MUON
  String nmoyenne;
  if ((currentmicros - lastmicros) > muDetectTime && (currentmicros - m.get_lastTime()) > debounceTimemicro1)
    {
        if (analogRead(MUON_PIN) > 200)
        {
            float moyenne = m.calculMoyenne(currentmicros);
            nmoyenne = String((int(moyenne / 100000000))) + String((int(moyenne) % 100000000) / 10000000) + String((int(moyenne) % 10000000) / 1000000) + String((int(moyenne) % 1000000) / 100000) + String((int(moyenne) % 100000) / 10000) + String((int(moyenne) % 10000) / 1000) + String((int(moyenne) % 1000) / 100) + String((int(moyenne) % 100) / 10) + String(int(moyenne) % 10);
            com.etatMuon = "W" + String(nmoyenne);
            com.sendMsg();

            lastmicros = currentmicros;
        }
    }
    
}
