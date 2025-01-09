#include <check.h>

#include "s21_string.h"

START_TEST(to_lower_1) {
  char str[] = "HELLO";
  char expected[] = "hello";
  char buf[64] = {0};

  s21_to_lower(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(to_lower_2) {
  char str[] = "HELLO";
  char expected[] = "hello";
  char buf[64] = {0};

  char* ret = s21_to_lower(str, buf);

  ck_assert_str_eq(expected, ret);
}
END_TEST

START_TEST(to_lower_3) {
  char str[] = "hello";
  char expected[] = "hello";
  char buf[64] = {0};

  s21_to_lower(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(to_lower_4) {
  char str[] = "Hello";
  char expected[] = "hello";
  char buf[64] = {0};

  s21_to_lower(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(to_lower_5) {
  char str[] = "12345";
  char expected[] = "12345";
  char buf[64] = {0};

  s21_to_lower(str, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

Suite* to_lower_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("to_lower");
  tc_core = tcase_create("to_lower");

  tcase_add_test(tc_core, to_lower_1);
  tcase_add_test(tc_core, to_lower_2);
  tcase_add_test(tc_core, to_lower_3);
  tcase_add_test(tc_core, to_lower_4);
  tcase_add_test(tc_core, to_lower_5);

  suite_add_tcase(s, tc_core);

  return s;
}