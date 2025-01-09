#include <check.h>

#include "s21_string.h"

START_TEST(to_upper_1) {
  char str[] = "hello";
  char expected[] = "HELLO";
  char buf[64] = {0};

  s21_to_upper(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(to_upper_2) {
  char str[] = "hello";
  char expected[] = "HELLO";
  char buf[64] = {0};

  char* ret = s21_to_upper(str, buf);

  ck_assert_str_eq(expected, ret);
}
END_TEST

START_TEST(to_upper_3) {
  char str[] = "HELLO";
  char expected[] = "HELLO";
  char buf[64] = {0};

  s21_to_upper(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(to_upper_4) {
  char str[] = "Hello";
  char expected[] = "HELLO";
  char buf[64] = {0};

  s21_to_upper(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(to_upper_5) {
  char str[] = "12345";
  char expected[] = "12345";
  char buf[64] = {0};

  s21_to_upper(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

Suite* to_upper_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("to_upper");
  tc_core = tcase_create("to_upper");

  tcase_add_test(tc_core, to_upper_1);
  tcase_add_test(tc_core, to_upper_2);
  tcase_add_test(tc_core, to_upper_3);
  tcase_add_test(tc_core, to_upper_4);
  tcase_add_test(tc_core, to_upper_5);

  suite_add_tcase(s, tc_core);

  return s;
}