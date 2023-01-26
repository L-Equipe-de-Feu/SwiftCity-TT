#include <Arduino.h>
#include "variables.h"

void setup() {
    Serial.begin(9600);
    pinMode(X_AXIS_PIN, INPUT);
    pinMode(Y_AXIS_PIN, INPUT);
    pinMode(Z_AXIS_PIN, INPUT);

    pinMode(JOY_GD_PIN, INPUT);
    pinMode(JOY_HB_PIN, INPUT);
    
    pinMode(BOU_A_PIN, INPUT);
    pinMode(BOU_B_PIN, INPUT);
    pinMode(BOU_M_PIN, INPUT);
    pinMode(BOU_S_PIN, INPUT);
    pinMode(BOU_ARG_PIN, INPUT);
    pinMode(BOU_ARD_PIN, INPUT);

    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
}

void loop() {

  if( digitalRead(BOU_A_PIN) == HIGH){
    Serial.print("Boutton A cliquer \n");
    Serial.println("Allumange de la LED1");
    digitalWrite(LED_1, HIGH);
    delay(2000);
    digitalWrite(LED_2, LOW);
  }

  if( digitalRead(BOU_B_PIN) == HIGH){
    Serial.print("Boutton B cliquer \n");
  }

  if( digitalRead(BOU_M_PIN) == HIGH){
    Serial.print("Boutton M cliquer \n");
  }

  if( digitalRead(BOU_S_PIN) == HIGH){
    Serial.print("Boutton S cliquer \n");
  }

  if( digitalRead(BOU_ARD_PIN) == HIGH){
    Serial.print("Boutton ARD cliquer \n");
  }
  
  if( digitalRead(BOU_ARG_PIN) == HIGH){
    Serial.print("Boutton ARG cliquer \n");
  }

  if( analogRead(JOY_GD_PIN > 1)){
    Serial.print("Valeur de joystick Gauche-Droit");
    Serial.print(digitalRead(JOY_GD_PIN));
    Serial.println();
  }

  if( analogRead(JOY_HB_PIN > 1)){
    Serial.print("Valeur de joystick Haut-Bas");
    Serial.print(digitalRead(JOY_HB_PIN));
    Serial.println();
  }


}