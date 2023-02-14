#ifndef VARIABLES_H
#define VARIABLES_H

#include <Arduino.h>
#include <string.h>

//Appel des fonctions
void appelVariables();
void LOWSET();

// ACCELEROMÈETRE
#define X_AXIS_PIN A3
#define Y_AXIS_PIN A4
#define Z_AXIS_PIN A2

// JOYSTICK
#define JOY_GD_PIN A1
#define JOY_HB_PIN A0

// BOUTTONS
#define BOU_A_PIN 30
#define BOU_B_PIN 31
#define BOU_M_PIN 29
#define BOU_S_PIN 28
#define BOU_ARD_PIN 27
#define BOU_ARG_PIN 26

// LEDS
#define LED_1 22
#define LED_2 23
#define LED_3 24
#define LED_4 25

// 7 SEGMENTS
#define SEG_A0_PIN 2
#define SEG_WR_PIN 46
#define SEG_A1_PIN 3
#define SEG_CS_PIN 48
#define SEG_A2_PIN 4
#define SEG_D_PIN 50
#define SEG_A3_PIN 5
#define SEG_EN_PIN 52
#define SEG_A4_PIN 6

// Etat bouton
#define BOU_A_ON "A1"
#define BOU_A_OFF "A0"
#define BOU_B_ON "B1"
#define BOU_B_OFF "B0"
#define BOU_M_ON "M1"
#define BOU_M_OFF "M0"
#define BOU_P_ON "P1"
#define BOU_P_OFF "P0"
#define BOU_ARD_ON "D1"
#define BOU_ARD_OFF "D0"
#define BOU_ARG_ON "G1"
#define BOU_ARG_OFF "G0"

// Frequence de transmission serielle
#define BAUD 9600

#endif