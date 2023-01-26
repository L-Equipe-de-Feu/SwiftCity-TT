#include <Arduino.h>
#include <variables.h>
#include <segments.h>

void setup() {
    Serial.begin(9600);
    appelVariables();



  //7-Segment Display Init
  digitalWrite(OE,LOW);        //Enables SR Operation
  initializeSRData();          //Prepares SR and clears data on serial line

  //Test
  setDigit(0,0,4,true);
  setDigit(0,1,5,true);
  setDigit(0,2,6,true);
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

  refreshDisplay(); 

}