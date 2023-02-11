#ifndef VARIABLES_H
#define VARIABLES_H

#include <Arduino.h>
#include <string.h>

void appelVariables();

//ACCELEROMÈETRE
#ifndef X_AXIS_PIN
#define X_AXIS_PIN A3
#endif

#ifndef Y_AXIS_PIN
#define Y_AXIS_PIN A4
#endif

#ifndef Z_AXIS_PIN
#define Z_AXIS_PIN A2
#endif

//JOYSTICK
#ifndef JOY_GD_PIN
#define JOY_GD_PIN A1
#endif

#ifndef JOY_HB_PIN
#define JOY_HB_PIN A0
#endif

//BOUTTONS
#ifndef BOU_A_PIN
#define BOU_A_PIN 30
#endif

#ifndef BOU_B_PIN
#define BOU_B_PIN 31
#endif

#ifndef BOU_M_PIN
#define BOU_M_PIN 29
#endif

#ifndef BOU_S_PIN
#define BOU_S_PIN 28
#endif

#ifndef BOU_ARD_PIN
#define BOU_ARD_PIN 27
#endif

#ifndef BOU_ARG_PIN
#define BOU_ARG_PIN 26
#endif

//LEDS
#ifndef LED_1
#define LED_1 22
#endif

#ifndef LED_2
#define LED_2 23
#endif

#ifndef LED_3
#define LED_3 24
#endif

#ifndef LED_4
#define LED_4 25
#endif

//7 SEGMENTS
#ifndef SEG_A0_PIN
#define SEG_A0_PIN 2
#endif

#ifndef SEG_WR_PIN
#define SEG_WR_PIN 46
#endif

#ifndef SEG_A1_PIN
#define SEG_A1_PIN 3
#endif

#ifndef SEG_CS_PIN
#define SEG_CS_PIN 48
#endif

#ifndef SEG_A2_PIN
#define SEG_A2_PIN 4
#endif

#ifndef SEG_D_PIN
#define SEG_D_PIN 50
#endif

#ifndef SEG_A3_PIN
#define SEG_A3_PIN 5
#endif

#ifndef SEG_EN_PIN
#define SEG_EN_PIN 52
#endif

#ifndef SEG_A4_PIN
#define SEG_A4_PIN 6
#endif

//Etat bouton
#ifndef BOU_A_ON
#define BOU_A_ON "A1"
#endif

#ifndef BOU_A_OFF
#define BOU_A_OFF "A0"
#endif

#ifndef BOU_B_ON
#define BOU_B_ON "B1"
#endif

#ifndef BOU_B_OFF
#define BOU_B_OFF "B0"
#endif

#ifndef BOU_M_ON
#define BOU_M_ON "M1"
#endif

#ifndef BOU_M_OFF
#define BOU_M_OFF "M0"
#endif

#ifndef BOU_P_ON
#define BOU_P_ON "P1"
#endif

#ifndef BOU_P_OFF
#define BOU_P_OFF "P0"
#endif

#ifndef BOU_ARD_ON
#define BOU_ARD_ON "D1"
#endif

#ifndef BOU_ARD_OFF
#define BOU_ARD_OFF "D0"
#endif

#ifndef BOU_ARG_ON
#define BOU_ARG_ON "G1"
#endif

#ifndef BOU_ARG_OFF
#define BOU_ARG_OFF "G0"
#endif

// Frequence de transmission serielle
#ifndef BAUD
#define BAUD 9600
#endif

#endif