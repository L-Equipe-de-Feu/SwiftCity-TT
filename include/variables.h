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
#define SEG_A0_PIN 38
#endif

#ifndef SEG_WR_PIN
#define SEG_WR_PIN 39
#endif

#ifndef SEG_A1_PIN
#define SEG_A1_PIN 40
#endif

#ifndef SEG_CS_PIN
#define SEG_CS_PIN 41
#endif

#ifndef SEG_A2_PIN
#define SEG_A2_PIN 42
#endif

#ifndef SEG_D_PIN
#define SEG_D_PIN 43
#endif

#ifndef SEG_A3_PIN
#define SEG_A3_PIN 44
#endif

#ifndef SEG_EN_PIN
#define SEG_EN_PIN 45
#endif

#ifndef SEG_A4_PIN
#define SEG_A4_PIN 46
#endif

#ifndef BAUD
#define BAUD 9600        // Frequence de transmission serielle
#endif

String etatBoutonA;
String etatBoutonB;
String etatBoutonM;
String etatBoutonP;
String etatBoutonAD;
String etatBoutonAG;
String etatJoystick;
String etatAcc;


#endif