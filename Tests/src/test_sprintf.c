#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "s21_string.h"

//
// Убрать когда начнут писать s21_sprintf
//
int s21_sprintf(char* s, const char* f, ...) {}

START_TEST(sprintf_1) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 123;

  sprintf(buf1, "%d", i);
  s21_sprintf(buf2, "%d", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_2) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = -123;

  sprintf(buf1, "int: %d", i);
  s21_sprintf(buf2, "int: %d", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_3) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  char c = 'a';

  sprintf(buf1, "char: %c", c);
  s21_sprintf(buf2, "char: %d", c);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_4) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = -123;

  sprintf(buf1, "int: %i", i);
  s21_sprintf(buf2, "int: %i", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_5) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = -3.14159265359f;

  sprintf(buf1, "%e", f);
  s21_sprintf(buf2, "%e", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_6) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = -3.14159265359f;

  sprintf(buf1, "%E", f);
  s21_sprintf(buf2, "%E", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_7) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = -3.14159265359f;

  sprintf(buf1, "%E", f);
  s21_sprintf(buf2, "%E", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_8) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = 0.00017238912f;

  sprintf(buf1, "%E", f);
  s21_sprintf(buf2, "%E", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_9) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = 0.00017238912f;

  sprintf(buf1, "%E", f);
  s21_sprintf(buf2, "%E", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_10) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = 0.00017238912f;

  sprintf(buf1, "%g", f);
  s21_sprintf(buf2, "%g", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_11) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = 0.00017238912f;

  sprintf(buf1, "%G", f);
  s21_sprintf(buf2, "%G", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_12) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 0777321;

  sprintf(buf1, "%o", i);
  s21_sprintf(buf2, "%o", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_13) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  char str[] = "Hello World";

  sprintf(buf1, "%s", str);
  s21_sprintf(buf2, "%s", str);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_14) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 34567;

  sprintf(buf1, "%u", i);
  s21_sprintf(buf2, "%u", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_15) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 34567;

  sprintf(buf1, "%x", i);
  s21_sprintf(buf2, "%x", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_16) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 34567;

  sprintf(buf1, "%X", i);
  s21_sprintf(buf2, "%X", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_17) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 34567;

  sprintf(buf1, "%p", &i);
  s21_sprintf(buf2, "%p", &i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_18) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 1234567;

  int n1 = 0;
  int n2 = 0;

  sprintf(buf1, "qweasdzxc %d %n", i, &n1);
  s21_sprintf(buf2, "qweasdzxc %d %n", i, &n2);

  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sprintf_19) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 100;

  sprintf(buf1, "Value is %d%% accurate", i);
  s21_sprintf(buf2, "Value is %d%% accurate", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_20) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  sprintf(buf1, "|%10d|", i);
  s21_sprintf(buf2, "|%10d|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_21) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  sprintf(buf1, "|%-10d|", i);
  s21_sprintf(buf2, "|%-10d|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_22) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  sprintf(buf1, "|%+d|", i);
  s21_sprintf(buf2, "|%+d|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_23) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  sprintf(buf1, "|%010d|", i);
  s21_sprintf(buf2, "|%010d|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_24) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  sprintf(buf1, "|%*d|", 10, i);
  s21_sprintf(buf2, "|%*d|", 10, i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_25) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  char str[] = "Hello World";

  sprintf(buf1, "|%*s|", 5, str);
  s21_sprintf(buf2, "|%*s|", 5, str);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_26) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  char str[] = "Hello World";

  sprintf(buf1, "|%.5s|", str);
  s21_sprintf(buf2, "|%.5s|", str);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_27) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = 3.14159;

  sprintf(buf1, "|%.2f|", f);
  s21_sprintf(buf2, "|%.2f|", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_28) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  long l = LONG_MAX;

  sprintf(buf1, "|%ld|", l);
  s21_sprintf(buf2, "|%ld|", l);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_29) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  long long l = LLONG_MAX;

  sprintf(buf1, "|%lld|", l);
  s21_sprintf(buf2, "|%lld|", l);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_30) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  sprintf(buf1, "|% d|", i);
  s21_sprintf(buf2, "|% d|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_31) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = -42;

  sprintf(buf1, "|% d|", i);
  s21_sprintf(buf2, "|% d|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_32) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 255;

  sprintf(buf1, "|%#x|", i);
  s21_sprintf(buf2, "|%#x|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_33) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 255;

  sprintf(buf1, "|%#X|", i);
  s21_sprintf(buf2, "|%#X|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_34) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 255;

  sprintf(buf1, "|%#o|", i);
  s21_sprintf(buf2, "|%#o|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_35) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  short i = 32000;

  sprintf(buf1, "|%hd|", i);
  s21_sprintf(buf2, "|%hd|", i);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_36) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float f = 42.12345;

  sprintf(buf1, "|%+010.3f|", f);
  s21_sprintf(buf2, "|%+010.3f|", f);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_37) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  char str[] = "Hello World";

  sprintf(buf1, "|%10.5s|", str);
  s21_sprintf(buf2, "|%10.5s|", str);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_38) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  double d = 12783.123456789;

  sprintf(buf1, "|%lf|", d);
  s21_sprintf(buf2, "|%lf|", d);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_39) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  long double d = 123456789.123456789L;

  sprintf(buf1, "|%Lf|", d);
  s21_sprintf(buf2, "|%Lf|", d);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_40) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  float d = 123.45;

  sprintf(buf1, "|%-+10.2f|", d);
  s21_sprintf(buf2, "|%-+010.2f|", d);

  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sprintf_41) {
  char buf1[64] = {0};
  char buf2[64] = {0};
  int i = 42;

  int ret1 = sprintf(buf1, "%d %d %d", i, i, i);
  int ret2 = s21_sprintf(buf2, "%d %d %d", i, i, i);

  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(ret1, ret2);
}
END_TEST

Suite* sprintf_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("sprintf");
  tc_core = tcase_create("sprintf");

  tcase_add_test(tc_core, sprintf_1);
  tcase_add_test(tc_core, sprintf_2);
  tcase_add_test(tc_core, sprintf_3);
  tcase_add_test(tc_core, sprintf_4);
  tcase_add_test(tc_core, sprintf_5);
  tcase_add_test(tc_core, sprintf_6);
  tcase_add_test(tc_core, sprintf_7);
  tcase_add_test(tc_core, sprintf_8);
  tcase_add_test(tc_core, sprintf_9);
  tcase_add_test(tc_core, sprintf_10);
  tcase_add_test(tc_core, sprintf_11);
  tcase_add_test(tc_core, sprintf_12);
  tcase_add_test(tc_core, sprintf_13);
  tcase_add_test(tc_core, sprintf_14);
  tcase_add_test(tc_core, sprintf_15);
  tcase_add_test(tc_core, sprintf_16);
  tcase_add_test(tc_core, sprintf_17);
  tcase_add_test(tc_core, sprintf_18);
  tcase_add_test(tc_core, sprintf_19);
  tcase_add_test(tc_core, sprintf_20);
  tcase_add_test(tc_core, sprintf_21);
  tcase_add_test(tc_core, sprintf_22);
  tcase_add_test(tc_core, sprintf_23);
  tcase_add_test(tc_core, sprintf_24);
  tcase_add_test(tc_core, sprintf_25);
  tcase_add_test(tc_core, sprintf_26);
  tcase_add_test(tc_core, sprintf_27);
  tcase_add_test(tc_core, sprintf_28);
  tcase_add_test(tc_core, sprintf_29);
  tcase_add_test(tc_core, sprintf_30);
  tcase_add_test(tc_core, sprintf_31);
  tcase_add_test(tc_core, sprintf_32);
  tcase_add_test(tc_core, sprintf_33);
  tcase_add_test(tc_core, sprintf_34);
  tcase_add_test(tc_core, sprintf_35);
  tcase_add_test(tc_core, sprintf_36);
  tcase_add_test(tc_core, sprintf_37);
  tcase_add_test(tc_core, sprintf_38);
  tcase_add_test(tc_core, sprintf_39);
  tcase_add_test(tc_core, sprintf_40);
  tcase_add_test(tc_core, sprintf_41);

  suite_add_tcase(s, tc_core);

  return s;
}