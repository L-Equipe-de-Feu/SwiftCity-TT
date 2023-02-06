#include <Arduino.h>
#include "variables.h"
#include "segments.h"

// Pour les pins
// 1 = 22-23-24-25-26-27-28
// 2 = 15-16-17-18-19-20-21
// 3 = 8-9-10-11-12-13-14
// 4 = 1-2-3-4-5-6-7

int zero(int a)
{
  // 22-23-24-25-26-27 -- 15-16-17-18-19-20 -- 8-9-10-11-12-13 -- 1-2-3-4-5-6
  // 1111 1100
  if (a == 1)
  {
    seg22();
    segsave();
    seg23();
    segsave();
    seg24();
    segsave();
    seg25();
    segsave();
    seg26();
    segsave();
    seg27();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg16();
    segsave();
    seg17();
    segsave();
    seg18();
    segsave();
    seg19();
    segsave();
    seg20();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg9();
    segsave();
    seg10();
    segsave();
    seg11();
    segsave();
    seg12();
    segsave();
    seg13();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg2();
    segsave();
    seg3();
    segsave();
    seg4();
    segsave();
    seg5();
    segsave();
    seg6();
    segsave();
    return 0;
  }
  return 1;
}

int un(int a)
{
  // juste 23-24 -- 16-17 -- 9-10 -- 2-3
  // 0110 0000
  if (a == 1)
  {
    seg23();
    segsave();
    seg24();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg16();
    segsave();
    seg17();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg9();
    segsave();
    seg10();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg2();
    segsave();
    seg3();
    segsave();
    return 0;
  }
  return 1;
}

int deux(int a)
{
  // 22-23-25-26-28 -- 15-16-18-19-21 -- 8-9-11-12-14 -- 1-2-4-5-7
  // 1101 1010
  if (a == 1)
  {
    seg22();
    segsave();
    seg23();
    segsave();
    seg25();
    segsave();
    seg26();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg16();
    segsave();
    seg18();
    segsave();
    seg19();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg9();
    segsave();
    seg11();
    segsave();
    seg12();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg2();
    segsave();
    seg4();
    segsave();
    seg5();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

int trois(int a)
{
  // 22-23-24-25-28 -- 15-16-17-18-21 -- 8-9-10-11-14 -- 1-2-3-4-7
  // 1111 0010
  if (a == 1)
  {
    seg22();
    segsave();
    seg23();
    segsave();
    seg24();
    segsave();
    seg25();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg16();
    segsave();
    seg17();
    segsave();
    seg18();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg9();
    segsave();
    seg10();
    segsave();
    seg11();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg2();
    segsave();
    seg3();
    segsave();
    seg4();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

int quatre(int a)
{
  // 23-24-27-28 -- 16-17-20-21 -- 9-10-13-14 -- 2-3-6-7
  // 0110 0110
  if (a == 1)
  {
    seg23();
    segsave();
    seg24();
    segsave();
    seg27();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg16();
    segsave();
    seg17();
    segsave();
    seg20();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg9();
    segsave();
    seg10();
    segsave();
    seg13();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg2();
    segsave();
    seg3();
    segsave();
    seg6();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

int cinq(int a)
{
  // 22-24-25-26-28 -- 15-17-18-19-21 -- 8-10-11-13-14 -- 1-3-4-5-7
  // 1011 0110
  if (a == 1)
  {
    seg22();
    segsave();
    seg24();
    segsave();
    seg25();
    segsave();
    seg26();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg17();
    segsave();
    seg18();
    segsave();
    seg19();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg10();
    segsave();
    seg11();
    segsave();
    seg13();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg3();
    segsave();
    seg4();
    segsave();
    seg5();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

int six(int a)
{
  // 22-24-25-26-27-28 -- 15-17-18-19-20-21 -- 8-10-11-12-13-14 -- 1-3-4-5-6-7
  // 1011 1110
  if (a == 1)
  {
    seg22();
    segsave();
    seg24();
    segsave();
    seg25();
    segsave();
    seg26();
    segsave();
    seg27();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg17();
    segsave();
    seg18();
    segsave();
    seg19();
    segsave();
    seg20();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg10();
    segsave();
    seg11();
    segsave();
    seg12();
    segsave();
    seg13();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg3();
    segsave();
    seg4();
    segsave();
    seg5();
    segsave();
    seg6();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

int sept(int a)
{
  // 22-23-24 -- 15-16-17 -- 8-9-10 -- 1-2-3
  // 1110 0000
  if (a == 1)
  {
    seg22();
    segsave();
    seg23();
    segsave();
    seg24();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg16();
    segsave();
    seg17();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg9();
    segsave();
    seg10();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg2();
    segsave();
    seg3();
    segsave();
    return 0;
  }
  return 1;
}

int huit(int a)
{
  // Tous ouvert
  // 1111 1110
  if (a == 1)
  {
    seg22();
    segsave();
    seg23();
    segsave();
    seg24();
    segsave();
    seg25();
    segsave();
    seg26();
    segsave();
    seg27();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg16();
    segsave();
    seg17();
    segsave();
    seg18();
    segsave();
    seg19();
    segsave();
    seg20();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg9();
    segsave();
    seg10();
    segsave();
    seg11();
    segsave();
    seg12();
    segsave();
    seg13();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg2();
    segsave();
    seg3();
    segsave();
    seg4();
    segsave();
    seg5();
    segsave();
    seg6();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

int neuf(int a)
{
  // 22-23-24-27-28 -- 15-16-17-20-21 -- 8-9-10-13-14 -- 1-2-3-6-7
  // 1110 0110
  if (a == 1)
  {
    seg22();
    segsave();
    seg23();
    segsave();
    seg24();
    segsave();
    seg27();
    segsave();
    seg28();
    segsave();
    return 0;
  }
  if (a == 2)
  {
    seg15();
    segsave();
    seg16();
    segsave();
    seg17();
    segsave();
    seg20();
    segsave();
    seg21();
    segsave();
    return 0;
  }
  if (a == 3)
  {
    seg8();
    segsave();
    seg9();
    segsave();
    seg10();
    segsave();
    seg13();
    segsave();
    seg14();
    segsave();
    return 0;
  }
  if (a == 4)
  {
    seg1();
    segsave();
    seg2();
    segsave();
    seg3();
    segsave();
    seg6();
    segsave();
    seg7();
    segsave();
    return 0;
  }
  return 1;
}

void seg1()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg2()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg3()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg4()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg5()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg6()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg7()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg8()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg9()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg10()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg11()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg12()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg13()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg14()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg15()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg16()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg17()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg18()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg19()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg20()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg21()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg22()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg23()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg24()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg25()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg26()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg27()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void seg28()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
}

void segsave()
{
  digitalWrite(SEG_CS_PIN, HIGH);
  digitalWrite(SEG_WR_PIN, HIGH);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void segoff()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_EN_PIN, HIGH);
}

void testaffichage(int i)
{
  un(i);
  delay(500);
  deux(i);
  delay(500);
  trois(i);
  delay(500);
  quatre(i);
  delay(500);
  cinq(i);
  delay(500);
  six(i);
  delay(500);
  sept(i);
  delay(500);
  huit(i);
  delay(500);
  neuf(i);
  delay(500);
  zero(i);
  delay(500);
  segoff();
}
