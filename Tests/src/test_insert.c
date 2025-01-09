#include <check.h>

#include "s21_string.h"

START_TEST(insert_1) {
  char str[] = "Hello World";
  char insert[] = "Beautiful ";
  char expected[] = "Hello Beautiful World";
  char buf[64] = {0};

  s21_insert(str, insert, 6, buf);

  ck_assert_str_eq(expected, buf);
}
END_TEST

START_TEST(insert_2) {
  char str[] = "Hello World";
  char insert[] = "Beautiful ";
  char expected[] = "Hello Beautiful World";
  char buf[64] = {0};

  char* ret = s21_insert(str, insert, 6, buf);

  ck_assert_str_eq(expected, ret);
}
END_TEST

START_TEST(insert_3) {
  char str[] = "Hello World";
  char insert[] = "Beautiful ";
  char* expected = S21_NULL;
  //   char buf[64] = {0};

  char* ret = s21_insert(str, insert, 6, S21_NULL);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(insert_4) {
  char str[] = "Hello World";
  //   char insert[] = "Beautiful ";
  char* expected = S21_NULL;
  char buf[64] = {0};

  char* ret = s21_insert(str, S21_NULL, 6, buf);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(insert_5) {
  //   char str[] = "Hello World";
  char insert[] = "Beautiful ";
  char* expected = S21_NULL;
  char buf[64] = {0};

  char* ret = s21_insert(S21_NULL, insert, 6, buf);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(insert_6) {
  char str[] = "Hello World";
  char insert[] = "Beautiful ";
  char* expected = S21_NULL;
  char buf[64] = {0};

  char* ret = s21_insert(str, insert, 13, buf);

  ck_assert_pstr_eq(expected, ret);
}
END_TEST

START_TEST(insert_7) {
  char str[] = "Hello World";
  char insert[] = "Beautiful ";
  char expected[] = "Beautiful Hello World";
  char buf[64] = {0};

  char* ret = s21_insert(str, insert, 0, buf);

  ck_assert_str_eq(expected, ret);
}
END_TEST

Suite* insert_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("insert");
  tc_core = tcase_create("insert");

  tcase_add_test(tc_core, insert_1);
  tcase_add_test(tc_core, insert_2);
  tcase_add_test(tc_core, insert_3);
  tcase_add_test(tc_core, insert_4);
  tcase_add_test(tc_core, insert_5);
  tcase_add_test(tc_core, insert_6);
  tcase_add_test(tc_core, insert_7);

  suite_add_tcase(s, tc_core);

  return s;
}