#include <check.h>

#include "s21_string.h"

START_TEST(strpbrk_1) {
  char str[] = "qweasd123";
  char find[] = "1";

  char* expected = strpbrk(str, find);
  char* ret = s21_strpbrk(str, find);

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strpbrk_2) {
  char str[] = "qweasd123";
  char find[] = "ASDF";

  char* expected = strpbrk(str, find);
  char* ret = s21_strpbrk(str, find);

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strpbrk_3) {
  char str[] = "qweasd123";
  char find[] = "123q";

  char* expected = strpbrk(str, find);
  char* ret = s21_strpbrk(str, find);

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strpbrk_4) {
  char str[] = "";
  char find[] = "123q";

  char* expected = strpbrk(str, find);
  char* ret = s21_strpbrk(str, find);

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strpbrk_5) {
  char str[] = "qweasd123";
  char find[] = "";

  char* expected = strpbrk(str, find);
  char* ret = s21_strpbrk(str, find);

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strpbrk_6) {
  char str[] = "";
  char find[] = "";

  char* expected = strpbrk(str, find);
  char* ret = s21_strpbrk(str, find);

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

Suite* strpbrk_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strpbrk");
  tc_core = tcase_create("strpbrk");

  tcase_add_test(tc_core, strpbrk_1);
  tcase_add_test(tc_core, strpbrk_2);
  tcase_add_test(tc_core, strpbrk_3);
  tcase_add_test(tc_core, strpbrk_4);
  tcase_add_test(tc_core, strpbrk_5);
  tcase_add_test(tc_core, strpbrk_6);

  suite_add_tcase(s, tc_core);

  return s;
}