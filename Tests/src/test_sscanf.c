#include <check.h>
#include <stdio.h>
#include <wchar.h>

#include "s21_string.h"

START_TEST(sscanf_1) {
  char input[] = "42";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%d", &i1);
  s21_sscanf(input, "%d", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_2) {
  char input[] = "-42";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%d", &i1);
  s21_sscanf(input, "%d", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_3) {
  char input[] = "  \n   42";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%d", &i1);
  s21_sscanf(input, "%d", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_4) {
  char input[] = "-3.14";
  float f1 = 0;
  float f2 = 0;

  sscanf(input, "%f", &f1);
  s21_sscanf(input, "%f", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_5) {
  char input[] = "2.512e-2";
  float f1 = 0;
  float f2 = 0;

  sscanf(input, "%f", &f1);
  s21_sscanf(input, "%f", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_6) {
  char input[] = "-2.512e+4";
  float f1 = 0;
  float f2 = 0;

  sscanf(input, "%f", &f1);
  s21_sscanf(input, "%f", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_7) {
  char input[] = "2.512E-2";
  float f1 = 0.f;
  float f2 = 0.f;

  sscanf(input, "%f", &f1);
  s21_sscanf(input, "%f", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_8) {
  char input[] = "1.23456e-4";
  float f1 = 0.f;
  float f2 = 0.f;

  sscanf(input, "%e", &f1);
  s21_sscanf(input, "%e", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_9) {
  char input[] = "1.23456E-4";
  double f1 = 0.f;
  double f2 = 0.f;

  sscanf(input, "%lE", &f1);
  s21_sscanf(input, "%lE", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_10) {
  char input[] = "1.2345678999";
  double d1 = 0.f;
  double d2 = 0.f;

  sscanf(input, "%lf", &d1);
  s21_sscanf(input, "%lf", &d2);

  ck_assert_double_eq_tol(d1, d2, 1e-10);
}
END_TEST

START_TEST(sscanf_11) {
  char input[] = "1.2345678999e-2";
  double d1 = 0.f;
  double d2 = 0.f;

  sscanf(input, "%lf", &d1);
  s21_sscanf(input, "%lf", &d2);

  ck_assert_double_eq_tol(d1, d2, 1e-10);
}
END_TEST

START_TEST(sscanf_12) {
  char input[] = "a";
  char c1[2] = {0};
  char c2[2] = {0};

  sscanf(input, "%c", c1);
  s21_sscanf(input, "%c", c2);

  ck_assert_str_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_13) {
  char input[] = "f";
  char c1[2] = {0};
  char c2[2] = {0};

  sscanf(input, "%c", c1);
  s21_sscanf(input, "%c", c2);

  ck_assert_str_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_14) {
  char input[] = "52";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%i", &i1);
  s21_sscanf(input, "%i", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_15) {
  char input[] = "521298";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%i", &i1);
  s21_sscanf(input, "%i", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_16) {
  char input[] = "-52";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%i", &i1);
  s21_sscanf(input, "%i", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_17) {
  char input[] = "0666";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%i", &i1);
  s21_sscanf(input, "%i", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_18) {
  char input[] = "0xfa";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%i", &i1);
  s21_sscanf(input, "%i", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_19) {
  char input[] = "0XFA";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%i", &i1);
  s21_sscanf(input, "%i", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_20) {
  char input[] = "0.000001";
  float f1 = 0.f;
  float f2 = 0.f;

  sscanf(input, "%g", &f1);
  s21_sscanf(input, "%g", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_21) {
  char input[] = "0.000001";
  float f1 = 0.f;
  float f2 = 0.f;

  sscanf(input, "%G", &f1);
  s21_sscanf(input, "%G", &f2);

  ck_assert_float_eq_tol(f1, f2, 1e-6);
}
END_TEST

START_TEST(sscanf_22) {
  char input[] = "0777";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%o", &i1);
  s21_sscanf(input, "%o", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_23) {
  char input[] = "00";
  int i1 = -1;
  int i2 = -2;

  sscanf(input, "%o", &i1);
  s21_sscanf(input, "%o", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_24) {
  char input[] = "Hello, World";
  char str1[16] = {0};
  char str2[16] = {0};

  sscanf(input, "%s", str1);
  s21_sscanf(input, "%s", str2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sscanf_25) {
  char input[] = "Hello, World";
  char str1_1[16] = {0};
  char str2_1[16] = {0};
  char str1_2[16] = {0};
  char str2_2[16] = {0};

  sscanf(input, "%s %s", str1_1, str1_2);
  s21_sscanf(input, "%s %s", str2_1, str2_2);

  ck_assert_str_eq(str1_1, str2_1);
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST

START_TEST(sscanf_26) {
  char input[] = "123";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%u", &i1);
  s21_sscanf(input, "%u", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_27) {
  char input[] = "0xffe1";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%x", &i1);
  s21_sscanf(input, "%x", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_28) {
  char input[] = "0XFFE1";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%x", &i1);
  s21_sscanf(input, "%x", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_29) {
  char input[] = "0xffe1";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%X", &i1);
  s21_sscanf(input, "%X", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_30) {
  char input[] = "0XFFE1";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%X", &i1);
  s21_sscanf(input, "%X", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_31) {
  char input[] = "0x7ffdfd";
  void* p1 = S21_NULL;
  void* p2 = S21_NULL;

  sscanf(input, "%p", &p1);
  s21_sscanf(input, "%p", &p2);

  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_32) {
  char input[] = "12345asdfx%n";
  int tmp = 0;
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "%d%n", &tmp, &i1);
  s21_sscanf(input, "%d%n", &tmp, &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_33) {
  char input[] = "Value is 100% accurate";
  int i1 = 0;
  int i2 = 0;

  sscanf(input, "Value is %d%% accurate", &i1);
  s21_sscanf(input, "Value is %d%% accurate", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_34) {
  char input[] = "123";
  short i1 = 0;
  short i2 = 0;

  sscanf(input, "%hd", &i1);
  s21_sscanf(input, "%hd", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_35) {
  char input[] = "-123";
  short i1 = 0;
  short i2 = 0;

  sscanf(input, "%hd", &i1);
  s21_sscanf(input, "%hd", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_36) {
  char input[] = "0123";
  short i1 = 0;
  short i2 = 0;

  sscanf(input, "%ho", &i1);
  s21_sscanf(input, "%ho", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_37) {
  char input[] = "0123";
  short i1 = 0;
  short i2 = 0;

  sscanf(input, "%ho", &i1);
  s21_sscanf(input, "%ho", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_38) {
  char input[] = "0xf2f";
  short i1 = 0;
  short i2 = 0;

  sscanf(input, "%hx", &i1);
  s21_sscanf(input, "%hx", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_39) {
  char input[] = "0XF2F";
  short i1 = 0;
  short i2 = 0;

  sscanf(input, "%hX", &i1);
  s21_sscanf(input, "%hX", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_40) {
  char input[] = "123";
  long i1 = 0;
  long i2 = 0;

  sscanf(input, "%ld", &i1);
  s21_sscanf(input, "%ld", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_41) {
  char input[] = "-123";
  long i1 = 0;
  long i2 = 0;

  sscanf(input, "%ld", &i1);
  s21_sscanf(input, "%ld", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_42) {
  char input[] = "012345677777777";
  long i1 = 0;
  long i2 = 0;

  sscanf(input, "%lo", &i1);
  s21_sscanf(input, "%lo", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_43) {
  char input[] = "0X1234FFFFAABB";
  long i1 = 0;
  long i2 = 0;

  sscanf(input, "%lX", &i1);
  s21_sscanf(input, "%lX", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_44) {
  char input[] = "0x1234ffffaabb";
  long i1 = 0;
  long i2 = 0;

  sscanf(input, "%lx", &i1);
  s21_sscanf(input, "%lx", &i2);

  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_45) {
  char input[] = "-1.23498263912836123123e-1";
  long double d1 = 0;
  long double d2 = 0;

  sscanf(input, "%Lf", &d1);
  s21_sscanf(input, "%Lf", &d2);

  ck_assert_ldouble_eq_tol(d1, d2, 1e-18);
}
END_TEST

Suite* sscanf_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("sscanf");
  tc_core = tcase_create("sscanf");

  tcase_add_test(tc_core, sscanf_1);
  tcase_add_test(tc_core, sscanf_2);
  tcase_add_test(tc_core, sscanf_3);
  tcase_add_test(tc_core, sscanf_4);
  tcase_add_test(tc_core, sscanf_5);
  tcase_add_test(tc_core, sscanf_6);
  tcase_add_test(tc_core, sscanf_7);
  tcase_add_test(tc_core, sscanf_8);
  tcase_add_test(tc_core, sscanf_9);
  tcase_add_test(tc_core, sscanf_10);
  tcase_add_test(tc_core, sscanf_11);
  tcase_add_test(tc_core, sscanf_12);
  tcase_add_test(tc_core, sscanf_13);
  tcase_add_test(tc_core, sscanf_14);
  tcase_add_test(tc_core, sscanf_15);
  tcase_add_test(tc_core, sscanf_16);
  tcase_add_test(tc_core, sscanf_17);
  tcase_add_test(tc_core, sscanf_18);
  tcase_add_test(tc_core, sscanf_19);
  tcase_add_test(tc_core, sscanf_20);
  tcase_add_test(tc_core, sscanf_21);
  tcase_add_test(tc_core, sscanf_22);
  tcase_add_test(tc_core, sscanf_23);
  tcase_add_test(tc_core, sscanf_24);
  tcase_add_test(tc_core, sscanf_25);
  tcase_add_test(tc_core, sscanf_26);
  tcase_add_test(tc_core, sscanf_27);
  tcase_add_test(tc_core, sscanf_28);
  tcase_add_test(tc_core, sscanf_29);
  tcase_add_test(tc_core, sscanf_30);
  tcase_add_test(tc_core, sscanf_31);
  tcase_add_test(tc_core, sscanf_32);
  tcase_add_test(tc_core, sscanf_33);
  tcase_add_test(tc_core, sscanf_34);
  tcase_add_test(tc_core, sscanf_35);
  tcase_add_test(tc_core, sscanf_36);
  tcase_add_test(tc_core, sscanf_37);
  tcase_add_test(tc_core, sscanf_38);
  tcase_add_test(tc_core, sscanf_39);
  tcase_add_test(tc_core, sscanf_40);
  tcase_add_test(tc_core, sscanf_41);
  tcase_add_test(tc_core, sscanf_42);
  tcase_add_test(tc_core, sscanf_43);
  tcase_add_test(tc_core, sscanf_44);
  tcase_add_test(tc_core, sscanf_45);

  suite_add_tcase(s, tc_core);

  return s;
}