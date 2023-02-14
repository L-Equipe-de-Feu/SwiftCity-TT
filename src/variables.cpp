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
    pinMode(BOU_B_PIN, INPUT);
    pinMode(BOU_M_PIN, INPUT);
    pinMode(BOU_S_PIN, INPUT);

    pinMode(BOU_ARG_PIN, INPUT);
    pinMode(BOU_ARD_PIN, INPUT);

    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);

    pinMode(SEG_A0_PIN, OUTPUT);
    pinMode(SEG_WR_PIN, OUTPUT);
    pinMode(SEG_A1_PIN, OUTPUT);
    pinMode(SEG_CS_PIN, OUTPUT);
    pinMode(SEG_A2_PIN, OUTPUT);
    pinMode(SEG_D_PIN, OUTPUT);
    pinMode(SEG_A3_PIN, OUTPUT);
    pinMode(SEG_EN_PIN, OUTPUT);
    pinMode(SEG_A4_PIN, OUTPUT);
}

void LOWSET()
{
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);

    digitalWrite(SEG_A0_PIN, LOW);
    digitalWrite(SEG_WR_PIN, LOW);
    digitalWrite(SEG_A1_PIN, LOW);
    digitalWrite(SEG_CS_PIN, LOW);
    digitalWrite(SEG_A2_PIN, LOW);
    digitalWrite(SEG_D_PIN, LOW);
    digitalWrite(SEG_A3_PIN, LOW);
    digitalWrite(SEG_EN_PIN, LOW);
    digitalWrite(SEG_A4_PIN, LOW);
}
