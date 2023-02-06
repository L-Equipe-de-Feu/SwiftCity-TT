#include <Arduino.h>
#include "variables.h"
#include "segments.h"

void zero(int a)
{
  // tous sauf 22-23-24-25-26-27 -- 15-16-17-18-19-20 -- 8-9-10-11-12-13 -- 1-2-3-4-5-6
  if (a == 1)
  {
    seg22();
    segoff();
    seg23();
    segoff();
    seg24();
    segoff();
    seg25();
    segoff();
    seg26();
    segoff();
    seg27();
    segoff();

    // 22-23-24-2;5-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg16();
    segoff();
    seg17();
    segoff();
    seg18();
    segoff();
    seg19();
    segoff();
    seg20();
    segoff();

    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg9();
    segoff();
    seg10();
    segoff();
    seg11();
    segoff();
    seg12();
    segoff();
    seg13();
    segoff();

    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg2();
    segoff();
    seg3();
    segoff();
    seg4();
    segoff();
    seg5();
    segoff();
    seg6();
    segoff();
  }
}

void un(int a)
{
  // juste 23-24 -- 16-17 -- 9-10 -- 2-3
  if (a == 1)
  {
    seg23();
    segoff();
    seg24();
    segoff();

    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg16();
    segoff();
    seg17();
    segoff();

    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg9();
    segoff();
    seg10();
    segoff();

    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg2();
    segoff();
    seg3();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 0110 0000
}

void deux(int a)
{
  // 22-23-25-26-28 -- 15-16-18-19-21 -- 8-9-11-12-14 -- 1-2-4-5-7
  if (a == 1)
  {
    seg22();
    segoff();
    seg23();
    segoff();
    seg25();
    segoff();
    seg26();
    segoff();
    seg28();
    segoff();
    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg16();
    segoff();
    seg18();
    segoff();
    seg19();
    segoff();
    seg21();
    segoff();
    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg9();
    segoff();
    seg11();
    segoff();
    seg12();
    segoff();
    seg14();
    segoff();
    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg2();
    segoff();
    seg4();
    segoff();
    seg5();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 1101 1010
}

void trois(int a)
{
  // 22-23-24-25-28 -- 15-16-17-18-21 -- 8-9-10-11-14 -- 1-2-3-4-7
  if (a == 1)
  {
    seg22();
    segoff();
    seg23();
    segoff();
    seg24();
    segoff();
    seg25();
    segoff();
    seg28();
    segoff();
    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg16();
    segoff();
    seg17();
    segoff();
    seg18();
    segoff();
    seg21();
    segoff();
    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg9();
    segoff();
    seg10();
    segoff();
    seg11();
    segoff();
    seg14();
    segoff();
    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg2();
    segoff();
    seg3();
    segoff();
    seg4();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 1111 0010
}

void quatre(int a)
{
  // 23-24-27-28 -- 16-17-20-21 -- 9-10-13-14 -- 2-3-6-7
  if (a == 1)
  {
    seg23();
    segoff();
    seg24();
    segoff();
    seg27();
    segoff();
    seg28();
    segoff();
    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg16();
    segoff();
    seg17();
    segoff();
    seg20();
    segoff();
    seg21();
    segoff();
    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg9();
    segoff();
    seg10();
    segoff();
    seg13();
    segoff();
    seg14();
    segoff();
    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg2();
    segoff();
    seg3();
    segoff();
    seg6();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 0110 0110
}

void cinq(int a)
{
  // 22-24-25-26-28 -- 15-17-18-19-21 -- 8-10-11-13-14 -- 1-3-4-5-7
  if (a == 1)
  {
    seg22();
    segoff();
    seg24();
    segoff();
    seg25();
    segoff();
    seg26();
    segoff();
    seg28();
    segoff();
    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg17();
    segoff();
    seg18();
    segoff();
    seg19();
    segoff();
    seg21();
    segoff();
    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg10();
    segoff();
    seg11();
    segoff();
    seg13();
    segoff();
    seg14();
    segoff();
    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg3();
    segoff();
    seg4();
    segoff();
    seg5();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 1011 0110
}

void six(int a)
{
  // 22-24-25-26-27-28 -- 15-17-18-19-20-21 -- 8-10-11-12-13-14 -- 1-3-4-5-6-7
  if (a == 1)
  {
    seg22();
    segoff();
    seg24();
    segoff();
    seg25();
    segoff();
    seg26();
    segoff();
    seg27();
    segoff();
    seg28();
    segoff();
    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg17();
    segoff();
    seg18();
    segoff();
    seg19();
    segoff();
    seg20();
    segoff();
    seg21();
    segoff();
    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg10();
    segoff();
    seg11();
    segoff();
    seg12();
    segoff();
    seg13();
    segoff();
    seg14();
    segoff();
    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg3();
    segoff();
    seg4();
    segoff();
    seg5();
    segoff();
    seg6();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 1011 1110
}

void sept(int a)
{
  // 22-23-24 -- 15-16-17 -- 8-9-10 -- 1-2-3
  if (a == 1)
  {
    seg22();
    segoff();
    seg23();
    segoff();
    seg24();
    segoff();

    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg16();
    segoff();
    seg17();
    segoff();

    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg9();
    segoff();
    seg10();
    segoff();

    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg2();
    segoff();
    seg3();
    segoff();

    // 1-2-3-4-5-6-7
  }

  // 1110 0000
}

void huit(int a)
{
  // Tous ouvert
  if (a == 1)
  {
    seg22();
    segoff();
    seg23();
    segoff();
    seg24();
    segoff();
    seg25();
    segoff();
    seg26();
    segoff();
    seg27();
    segoff();
    seg28();
    segoff();

    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg16();
    segoff();
    seg17();
    segoff();
    seg18();
    segoff();
    seg19();
    segoff();
    seg20();
    segoff();
    seg21();
    segoff();

    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg9();
    segoff();
    seg10();
    segoff();
    seg11();
    segoff();
    seg12();
    segoff();
    seg13();
    segoff();
    seg14();
    segoff();

    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg2();
    segoff();
    seg3();
    segoff();
    seg4();
    segoff();
    seg5();
    segoff();
    seg6();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 1111 1110
}

void neuf(int a)
{
  // 22-23-24-27-28 -- 15-16-17-20-21 -- 8-9-10-13-14 -- 1-2-3-6-7
  if (a == 1)
  {
    seg22();
    segoff();
    seg23();
    segoff();
    seg24();
    segoff();
    seg27();
    segoff();
    seg28();
    segoff();

    // 22-23-24-25-26-27-28
  }
  if (a == 2)
  {
    seg15();
    segoff();
    seg16();
    segoff();
    seg17();
    segoff();
    seg20();
    segoff();
    seg21();
    segoff();
    // 15-16-17-18-19-20-21
  }
  if (a == 3)
  {
    seg8();
    segoff();
    seg9();
    segoff();
    seg10();
    segoff();
    seg13();
    segoff();
    seg14();
    segoff();
    // 8-9-10-11-12-13-14
  }
  if (a == 4)
  {
    seg1();
    segoff();
    seg2();
    segoff();
    seg3();
    segoff();
    seg6();
    segoff();
    seg7();
    segoff();
    // 1-2-3-4-5-6-7
  }

  // 1110 0110
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
}

void seg28()
{
  digitalWrite(SEG_A0_PIN, HIGH);
  digitalWrite(SEG_A1_PIN, HIGH);
  digitalWrite(SEG_A2_PIN, LOW);
  digitalWrite(SEG_A3_PIN, HIGH);
  digitalWrite(SEG_A4_PIN, HIGH);
  digitalWrite(SEG_EN_PIN, LOW);
  digitalWrite(SEG_CS_PIN, HIGH);
}

void segoff()
{
  digitalWrite(SEG_EN_PIN, HIGH);
}

void testaffichage(){
  un(1);
  delay(500);
  deux(1);
  delay(500);
  trois(1);
  delay(500);
  quatre(1);
  delay(500);
  cinq(1);
  delay(500);
  six(1);
  delay(500);
  sept(1);
  delay(500);
  huit(1);
  delay(500);
  neuf(1);
  delay(500);
  zero(1);
  delay(500);

  un(2);
  delay(500);
  deux(2);
  delay(500);
  trois(2);
  delay(500);
  quatre(2);
  delay(500);
  cinq(2);
  delay(500);
  six(2);
  delay(500);
  sept(2);
  delay(500);
  huit(2);
  delay(500);
  neuf(2);
  delay(500);
  zero(2);
  delay(500);

  un(3);
  delay(500);
  deux(3);
  delay(500);
  trois(3);
  delay(500);
  quatre(3);
  delay(500);
  cinq(3);
  delay(500);
  six(3);
  delay(500);
  sept(3);
  delay(500);
  huit(3);
  delay(500);
  neuf(3);
  delay(500);
  zero(3);
  delay(500);

  un(4);
  delay(500);
  deux(4);
  delay(500);
  trois(4);
  delay(500);
  quatre(4);
  delay(500);
  cinq(4);
  delay(500);
  six(4);
  delay(500);
  sept(4);
  delay(500);
  huit(4);
  delay(500);
  neuf(4);
  delay(500);
  zero(4);
  delay(500);

}


