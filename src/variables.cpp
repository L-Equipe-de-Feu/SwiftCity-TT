#include <Arduino.h>
#include "variables.h"
#include "segments.h"

void appelVariables()
{
    pinMode(X_AXIS_PIN, INPUT); 
    pinMode(Y_AXIS_PIN, INPUT);
    pinMode(Z_AXIS_PIN, INPUT);

    pinMode(JOY_GD_PIN, INPUT);
    pinMode(JOY_HB_PIN, INPUT);

    pinMode(BOU_A_PIN, INPUT);
    digitalWrite(BOU_A_PIN, LOW);
    pinMode(BOU_B_PIN, INPUT);
    digitalWrite(BOU_B_PIN, LOW);
    pinMode(BOU_M_PIN, INPUT);
    digitalWrite(BOU_M_PIN, LOW);
    pinMode(BOU_S_PIN, INPUT);
    digitalWrite(BOU_S_PIN, LOW);
    pinMode(BOU_ARG_PIN, INPUT);
    digitalWrite(BOU_ARG_PIN, LOW);
    pinMode(BOU_ARD_PIN, INPUT);
    digitalWrite(BOU_ARD_PIN, LOW);

    pinMode(LED_1, OUTPUT);
    digitalWrite(LED_1, LOW);
    pinMode(LED_2, OUTPUT);
    digitalWrite(LED_2, LOW);
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_3, LOW);
    pinMode(LED_4, OUTPUT);
    digitalWrite(LED_4, LOW);

    pinMode(SEG_A0_PIN, OUTPUT);
    digitalWrite(SEG_A0_PIN, LOW);
    pinMode(SEG_WR_PIN, OUTPUT);
    digitalWrite(SEG_WR_PIN, LOW);
    pinMode(SEG_A1_PIN, OUTPUT);
    digitalWrite(SEG_A1_PIN, LOW);
    pinMode(SEG_CS_PIN, OUTPUT);
    digitalWrite(SEG_CS_PIN, LOW);
    pinMode(SEG_A2_PIN, OUTPUT);
    digitalWrite(SEG_A2_PIN, LOW);
    pinMode(SEG_D_PIN, OUTPUT);
    digitalWrite(SEG_D_PIN, LOW);
    pinMode(SEG_A3_PIN, OUTPUT);
    digitalWrite(SEG_A3_PIN, LOW);
    pinMode(SEG_EN_PIN, OUTPUT);
    digitalWrite(SEG_EN_PIN, LOW);
    pinMode(SEG_A4_PIN, OUTPUT);
    digitalWrite(SEG_A4_PIN, LOW);
}