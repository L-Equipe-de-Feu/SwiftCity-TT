#include <Arduino.h>
#include "variables.h"
#include "segments.h"

// Pour les pins
// 1 = 22-23-24-25-26-27-28
// 2 = 15-16-17-18-19-20-21
// 3 = 8-9-10-11-12-13-14
// 4 = 1-2-3-4-5-6-7

int valeur1 = 0;
int valeur2 = 0;
int valeur3 = 0;
int valeur4 = 0;

void appel()
{
  segoff();
  delay(100);
  segon();
  // pour 1
  if (valeur1 == 1)
  {
    un(1);
  }
  if (valeur2 == 1)
  {
    un(2);
  }
  if (valeur3 == 1)
  {
    un(3);
  }
  if (valeur4 == 1)
  {
    un(4);
  }

  // pour 2
  if (valeur1 == 2)
  {
    deux(1);
  }
  if (valeur2 == 2)
  {
    deux(2);
  }
  if (valeur3 == 2)
  {
    deux(3);
  }
  if (valeur4 == 2)
  {
    deux(4);
  }

  // pour 3
  if (valeur1 == 3)
  {
    trois(1);
  }
  if (valeur2 == 3)
  {
    trois(2);
  }
  if (valeur3 == 3)
  {
    trois(3);
  }
  if (valeur4 == 3)
  {
    trois(4);
  }

  // pour 4
  if (valeur1 == 4)
  {
    quatre(1);
  }
  if (valeur2 == 4)
  {
    quatre(2);
  }
  if (valeur3 == 4)
  {
    quatre(3);
  }
  if (valeur4 == 4)
  {
    quatre(4);
  }

  // pour 5
  if (valeur1 == 5)
  {
    cinq(1);
  }
  if (valeur2 == 5)
  {
    cinq(2);
  }
  if (valeur3 == 5)
  {
    cinq(3);
  }
  if (valeur4 == 5)
  {
    cinq(4);
  }

  // pour 6
  if (valeur1 == 6)
  {
    six(1);
  }
  if (valeur2 == 6)
  {
    six(2);
  }
  if (valeur3 == 6)
  {
    six(3);
  }
  if (valeur4 == 6)
  {
    six(4);
  }

  // pour 7
  if (valeur1 == 7)
  {
    sept(1);
  }
  if (valeur2 == 7)
  {
    sept(2);
  }
  if (valeur3 == 7)
  {
    sept(3);
  }
  if (valeur4 == 7)
  {
    sept(4);
  }

  // pour 8
  if (valeur1 == 8)
  {
    huit(1);
  }
  if (valeur2 == 8)
  {
    huit(2);
  }
  if (valeur3 == 8)
  {
    huit(3);
  }
  if (valeur4 == 8)
  {
    huit(4);
  }

  // pour 9
  if (valeur1 == 9)
  {
    neuf(1);
  }
  if (valeur2 == 9)
  {
    neuf(2);
  }
  if (valeur3 == 9)
  {
    neuf(3);
  }
  if (valeur4 == 9)
  {
    neuf(4);
  }

  // pour 0
  if (valeur1 == 0)
  {
    zero(1);
  }
  if (valeur2 == 0)
  {
    zero(2);
  }
  if (valeur3 == 0)
  {
    zero(3);
  }
  if (valeur4 == 0)
  {
    zero(4);
  }
}

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
    valeur1 = 0;
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
    valeur2 = 0;
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
    valeur3 = 0;
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
    valeur4 = 0;
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
    valeur1 = 1;
    return 0;
  }
  if (a == 2)
  {
    seg16();
    segsave();
    seg17();
    segsave();
    valeur2 = 1;
    return 0;
  }
  if (a == 3)
  {
    seg9();
    segsave();
    seg10();
    segsave();
    valeur3 = 1;
    return 0;
  }
  if (a == 4)
  {
    seg2();
    segsave();
    seg3();
    segsave();
    valeur4 = 1;
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
    valeur1 = 2;
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
    valeur2 = 2;
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
    valeur3 = 2;
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
    valeur4 = 2;
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
    valeur1 = 3;
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
    valeur2 = 3;
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
    valeur3 = 3;
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
    valeur4 = 3;
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
    valeur1 = 4;
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
    valeur2 = 4;
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
    valeur3 = 4;
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
    valeur4 = 4;
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
    valeur1 = 5;
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
    valeur2 = 5;
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
    valeur3 = 5;
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
    valeur4 = 5;
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
    valeur1 = 6;
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
    valeur2 = 6;
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
    valeur3 = 6;
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
    valeur4 = 6;
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
    valeur1 = 7;
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
    valeur2 = 7;
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
    valeur3 = 7;
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
    valeur4 = 7;
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
    valeur1 = 8;
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
    valeur2 = 8;
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
    valeur3 = 8;
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
    valeur4 = 8;
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
    valeur1 = 9;
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
    valeur2 = 9;
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
    valeur3 = 9;
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
    valeur4 = 9;
    return 0;
  }
  return 1;
}

void seg1()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg2()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg3()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg4()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg5()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg6()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg7()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg8()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg9()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg10()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg11()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg12()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg13()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg14()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg15()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg16()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, LOW);
}

void seg17()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg18()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg19()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg20()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg21()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg22()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg23()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg24()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, HIGH);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg25()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg26()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg27()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
}

void seg28()
{
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
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
  digitalWrite(SEG_D_PIN, LOW);
}

void segon()
{
  digitalWrite(SEG_A0_PIN, LOW);
  digitalWrite(SEG_A1_PIN, LOW);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, LOW);
  digitalWrite(SEG_A4_PIN, LOW);
  digitalWrite(SEG_CS_PIN, LOW);
  digitalWrite(SEG_WR_PIN, LOW);
  digitalWrite(SEG_D_PIN, HIGH);
}

void testaffichage(int i)
{
  if (i == 1)
  {
    valeur1 = 0;
    appel();
    valeur1 = 1;
    appel();
    valeur1 = 2;
    appel();
    valeur1 = 3;
    appel();
    valeur1 = 4;
    appel();
    valeur1 = 5;
    appel();
    valeur1 = 6;
    appel();
    valeur1 = 7;
    appel();
    valeur1 = 8;
    appel();
    valeur1 = 9;
    appel();
    valeur1 = 1;
  }
  if (i == 2)
  {
    valeur2 = 0;
    appel();
    valeur2 = 1;
    appel();
    valeur2 = 2;
    appel();
    valeur2 = 3;
    appel();
    valeur2 = 4;
    appel();
    valeur2 = 5;
    appel();
    valeur2 = 6;
    appel();
    valeur2 = 7;
    appel();
    valeur2 = 8;
    appel();
    valeur2 = 9;
    appel();
    valeur2 = 1;
  }
  if (i == 3)
  {
    valeur3 = 0;
    appel();
    valeur3 = 1;
    appel();
    valeur3 = 2;
    appel();
    valeur3 = 3;
    appel();
    valeur3 = 4;
    appel();
    valeur3 = 5;
    appel();
    valeur3 = 6;
    appel();
    valeur3 = 7;
    appel();
    valeur3 = 8;
    appel();
    valeur3 = 9;
    appel();
    valeur3 = 1;
  }
  if (i == 4)
  {
    valeur4 = 0;
    appel();
    valeur4 = 1;
    appel();
    valeur4 = 2;
    appel();
    valeur4 = 3;
    appel();
    valeur4 = 4;
    appel();
    valeur4 = 5;
    appel();
    valeur4 = 6;
    appel();
    valeur4 = 7;
    appel();
    valeur4 = 8;
    appel();
    valeur4 = 9;
    appel();
    valeur4 = 1;
  }
}
