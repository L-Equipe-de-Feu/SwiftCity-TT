#include <Arduino.h>
#include "variables.h"
#include "segments.h"

// Pour les pins
// 1 = 22-23-24-25-26-27-28
// 2 = 15-16-17-18-19-20-21
// 3 = 8-9-10-11-12-13-14
// 4 = 1-2-3-4-5-6-7

void appel(int valeur4, int valeur3, int valeur2, int valeur1)
{
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
    seg6();
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
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg2()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg3()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg4()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg5()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg6()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg7()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg8()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
}

void seg9()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg10()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg11()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg12()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg13()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg14()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg15()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg16()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 0);
}

void seg17()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg18()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg19()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg20()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg21()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg22()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg23()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg24()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 255);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 255);
}

void seg25()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 255);
}

void seg26()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 255);
}

void seg27()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 255);
}

void seg28()
{
  analogWrite(SEG_CS_PIN, 0);
  //analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_A0_PIN, 255);
  analogWrite(SEG_A1_PIN, 255);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 255);
  analogWrite(SEG_A4_PIN, 255);
}

void segsave()
{
  analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_WR_PIN, 255);
  //analogWrite(SEG_CS_PIN, 255);
}

void segoff()
{
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
  analogWrite(SEG_CS_PIN, 0);
  analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_D_PIN, 0);
}

void segon()
{
  analogWrite(SEG_A0_PIN, 0);
  analogWrite(SEG_A1_PIN, 0);
  analogWrite(SEG_A2_PIN, 0);
  analogWrite(SEG_A3_PIN, 0);
  analogWrite(SEG_A4_PIN, 0);
  analogWrite(SEG_CS_PIN, 0);
  analogWrite(SEG_WR_PIN, 0);
  analogWrite(SEG_EN_PIN, 0);
  analogWrite(SEG_D_PIN, 255);
}

void testaffichage(int i, int x)
{

  if (i == 1)
  {
    appel(1, 0, 0, 0);
    delay(x);
    appel(2, 0, 0, 0);
    delay(x);
    appel(3, 0, 0, 0);
    delay(x);
    appel(4, 0, 0, 0);
    delay(x);
    appel(5, 0, 0, 0);
    delay(x);
    appel(6, 0, 0, 0);
    delay(x);
    appel(7, 0, 0, 0);
    delay(x);
    appel(8, 0, 0, 0);
    delay(x);
    appel(9, 0, 0, 0);
    delay(x);
  }
  if (i == 2)
  {
    appel(0, 1, 0, 0);
    delay(x);
    appel(0, 2, 0, 0);
    delay(x);
    appel(0, 3, 0, 0);
    delay(x);
    appel(0, 4, 0, 0);
    delay(x);
    appel(0, 5, 0, 0);
    delay(x);
    appel(0, 6, 0, 0);
    delay(x);
    appel(0, 7, 0, 0);
    delay(x);
    appel(0, 8, 0, 0);
    delay(x);
    appel(0, 9, 0, 0);
    delay(x);
  }
  if (i == 3)
  {
    appel(0, 0, 1, 0);
    delay(x);
    appel(0, 0, 2, 0);
    delay(x);
    appel(0, 0, 3, 0);
    delay(x);
    appel(0, 0, 4, 0);
    delay(x);
    appel(0, 0, 5, 0);
    delay(x);
    appel(0, 0, 6, 0);
    delay(x);
    appel(0, 0, 7, 0);
    delay(x);
    appel(0, 0, 8, 0);
    delay(x);
    appel(0, 0, 9, 0);
    delay(x);
  }
  if (i == 4)
  {
    appel(0, 0, 0, 1);
    delay(x);
    appel(0, 0, 0, 2);
    delay(x);
    appel(0, 0, 0, 3);
    delay(x);
    appel(0, 0, 0, 4);
    delay(x);
    appel(0, 0, 0, 5);
    delay(x);
    appel(0, 0, 0, 6);
    delay(x);
    appel(0, 0, 0, 7);
    delay(x);
    appel(0, 0, 0, 8);
    delay(x);
    appel(0, 0, 0, 9);
    delay(x);
  }
}

void testaffichageindi(float i)
{
  seg1();
  delay(i);
  seg2();
  delay(i);
  seg3();
  delay(i);
  seg4();
  delay(i);
  seg5();
  delay(i);
  seg6();
  delay(i);
  seg7();
  delay(i);
  seg8();
  delay(i);
  seg9();
  delay(i);
  seg10();
  delay(i);
  seg11();
  delay(i);
  seg12();
  delay(i);
  seg13();
  delay(i);
  seg14();
  delay(i);
  seg15();
  delay(i);
  seg16();
  delay(i);
  seg17();
  delay(i);
  seg18();
  delay(i);
  seg19();
  delay(i);
  seg20();
  delay(i);
  seg21();
  delay(i);
  seg22();
  delay(i);
  seg23();
  delay(i);
  seg24();
  delay(i);
  seg25();
  delay(i);
  seg26();
  delay(i);
  seg27();
  delay(i);
  seg28();
  delay(i);
}

/*void SetTemp(int Segment1, int Segment2, int Segment3, int Segment4)
{
  valeur1 = Segment1;
  valeur2 = Segment2;
  valeur3 = Segment3;
  valeur4 = Segment4;
  appel();
}*/

/*void VitesseEtAppel(int vitesse, unsigned long *previousMillis, unsigned long *currentMillis)
{
  unsigned const long interval = ((minutes * 60 * 1000) / vitesse);

  if ((*currentMillis - (*previousMillis)) >= interval)
  {
    valeur4 += 1;

    if (valeur4 == 10)
    {
      valeur4 = 0;
      valeur3 = valeur3 + 1;
    }
    if (valeur1 == 0)
    {
      if (valeur2 == 2)
      {
        if (valeur3 == 2)
        {
          if (valeur4 == 9)
          {
            valeur2 += 1;
            valeur3 = 0;
            valeur4 = 1;
          }
        }
      }
    }

    if (valeur3 == 3)
    {

      if (valeur2 % 2 != 0 || (valeur1 == 0 && valeur2 == 8))
      {
        if (valeur4 == 2)
        {
          valeur2 = valeur2 + 1;
          valeur3 = 0;
          valeur4 = 1;
        }
      }
      else
      {
        if (valeur4 == 1)
        {
          valeur2 = valeur2 + 1;
          valeur3 = 0;
          valeur4 = 1;
        }
      }
    }
    if (valeur2 == 10)
    {
      valeur2 = 0;
      valeur1 = valeur1 + 1;
    }
    if (valeur1 == 1)
    {
      if (valeur2 == 3)
      {
        valeur1 = 0;
        valeur2 = 1;
      }
    }
    appel();
    *previousMillis = *currentMillis;
  }
  else
  {
    appel();
  }
}*/
