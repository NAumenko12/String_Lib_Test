#include <check.h>

#include "s21_string.h"

START_TEST(strlen_1) {
  char str[] = "asd";

  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, 3);
}
END_TEST

START_TEST(strlen_2) {
  char str[] = "asd123\0qwe";

  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, 6);
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "\t\n\f\0qwe";

  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, 3);
}
END_TEST

START_TEST(strlen_4) {
  s21_size_t ret = s21_strlen(S21_NULL);

  ck_assert_uint_eq(ret, 0);
}
END_TEST

START_TEST(strlen_5) {
  char str[] = "";

  s21_size_t ret = s21_strlen(str);

  ck_assert_uint_eq(ret, 0);
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
  tcase_add_test(tc_core, strlen_5);

  suite_add_tcase(s, tc_core);

  return s;
}