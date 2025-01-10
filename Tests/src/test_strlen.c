#include <check.h>

#include "s21_string.h"

START_TEST(strlen_1) {
  char str[] = "asd";

  s21_size_t expected = strlen(str);
  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, expected);
}
END_TEST

START_TEST(strlen_2) {
  char str[] = "asd123\0qwe";

  s21_size_t expected = strlen(str);
  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, expected);
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "\t\n\f\0qwe";

  s21_size_t expected = strlen(str);
  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, expected);
}
END_TEST

START_TEST(strlen_4) {
  char str[] = "";

  s21_size_t expected = strlen(str);
  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, expected);
}
END_TEST

Suite* strlen_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strlen");
  tc_core = tcase_create("strlen");

  tcase_add_test(tc_core, strlen_1);
  tcase_add_test(tc_core, strlen_2);
  tcase_add_test(tc_core, strlen_3);
  tcase_add_test(tc_core, strlen_4);

  suite_add_tcase(s, tc_core);

  return s;
}