#include <check.h>

#include "s21_string.h"

START_TEST(strncmp_1) {
  char str1[] = "asd";
  char str2[] = "zxc";

  int expected = strncmp(str1, str2, sizeof(str1));
  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_lt(cmp, 0);
  ck_assert_int_lt(expected, 0);
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "asd123";
  char str2[] = "asd123";

  int expected = strncmp(str1, str2, sizeof(str1));
  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(cmp, expected);
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "zxc";
  char str2[] = "asd";

  int expected = strncmp(str1, str2, sizeof(str1));
  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_gt(cmp, 0);
  ck_assert_int_gt(expected, 0);
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "asd";
  char str2[] = "";

  int expected = strncmp(str1, str2, sizeof(str1));
  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_gt(cmp, 0);
  ck_assert_int_gt(expected, 0);
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "asd\000123";
  char str2[] = "asd\000zxc";

  int expected = strncmp(str1, str2, sizeof(str1));
  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(cmp, expected);
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] = "asf";
  char str2[] = "asd";

  int expected = strncmp(str1, str2, 2);
  int cmp = s21_strncmp(str1, str2, 2);

  ck_assert_int_eq(cmp, expected);
}
END_TEST

Suite* strncmp_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strncmp");
  tc_core = tcase_create("strncmp");

  tcase_add_test(tc_core, strncmp_1);
  tcase_add_test(tc_core, strncmp_2);
  tcase_add_test(tc_core, strncmp_3);
  tcase_add_test(tc_core, strncmp_4);
  tcase_add_test(tc_core, strncmp_5);
  tcase_add_test(tc_core, strncmp_6);
  suite_add_tcase(s, tc_core);

  return s;
}