#ifndef VARIABLES_H
#define VARIABLES_H

#include <Arduino.h>
#include <string.h>

// Appel des fonctions
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
#define SEG_WR_PIN 8
#define SEG_A1_PIN 3
#define SEG_CS_PIN 9
#define SEG_A2_PIN 4
#define SEG_D_PIN 10
#define SEG_A3_PIN 5
#define SEG_EN_PIN 11
#define SEG_A4_PIN 6

// Frequence de transmission serielle
#define BAUD 115200

#endif