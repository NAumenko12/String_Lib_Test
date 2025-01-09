#include <check.h>

#include "s21_string.h"

START_TEST(trim_1) {
  char str[] = "  Hello World  ";
  char trim[] = " ";
  char expected[] = "Hello World";
  char buf[64] = {0};

  s21_trim(str, trim, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(trim_2) {
  char str[] = "  Hello World  ";
  char trim[] = " ";
  char expected[] = "Hello World";
  char buf[64] = {0};

  char* ret = s21_trim(str, trim, buf);

  ck_assert_str_eq(expected, ret);
}
END_TEST

START_TEST(trim_3) {
  char str[] = "  Hello World  ";
  char trim[] = " ";
  char* expected = S21_NULL;
  //   char buf[64] = {0};

  char* ret = s21_trim(str, trim, S21_NULL);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(trim_4) {
  char str[] = "  Hello World  ";
  //   char trim[] = " ";
  char* expected = S21_NULL;
  char buf[64] = {0};

  char* ret = s21_trim(str, S21_NULL, buf);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(trim_5) {
  //   char str[] = "  Hello World  ";
  char trim[] = " ";
  char* expected = S21_NULL;
  char buf[64] = {0};

  char* ret = s21_trim(S21_NULL, trim, buf);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(trim_6) {
  char str[] = "**!!Hello World!!**";
  char trim[] = "*!";
  char expected[] = "Hello World";
  char buf[64] = {0};

  s21_trim(str, trim, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(trim_7) {
  char str[] = "**!!Hello World!!**";
  char trim[] = "Hello World";
  char expected[] = "**!!Hello World!!**";
  char buf[64] = {0};

  s21_trim(str, trim, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(trim_8) {
  char str[] = "Hello World!\n";
  char trim[] = "\n";
  char expected[] = "Hello World!";
  char buf[64] = {0};

  s21_trim(str, trim, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

Suite* trim_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("trim");
  tc_core = tcase_create("trim");

  tcase_add_test(tc_core, trim_1);
  tcase_add_test(tc_core, trim_2);
  tcase_add_test(tc_core, trim_3);
  tcase_add_test(tc_core, trim_4);
  tcase_add_test(tc_core, trim_5);
  tcase_add_test(tc_core, trim_6);
  tcase_add_test(tc_core, trim_7);
  tcase_add_test(tc_core, trim_8);

  suite_add_tcase(s, tc_core);

  return s;
}