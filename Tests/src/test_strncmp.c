#include <check.h>

#include "s21_string.h"

START_TEST(strncmp_1) {
  char str1[] = "asd";
  char str2[] = "zxc";

  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_lt(cmp, 0);
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "asd123";
  char str2[] = "asd123";

  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(cmp, 0);
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "zxc";
  char str2[] = "asd";

  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_gt(cmp, 0);
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "asd";
  char str2[] = "";

  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_gt(cmp, 0);
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "asd\000123";
  char str2[] = "asd\000zxc";

  int cmp = s21_strncmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(cmp, 0);
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] = "asd";

  int cmp = s21_strncmp(str1, S21_NULL, sizeof(str1));

  ck_assert_int_gt(cmp, 0);
}
END_TEST

START_TEST(strncmp_7) {
  char str1[] = "asd";

  int cmp = s21_strncmp(S21_NULL, str1, sizeof(str1));

  ck_assert_int_lt(cmp, 0);
}
END_TEST

START_TEST(strncmp_8) {
  int cmp = s21_strncmp(S21_NULL, S21_NULL, 10);

  ck_assert_int_eq(cmp, 0);
}
END_TEST

START_TEST(strncmp_9) {
  char str1[] = "asf";
  char str2[] = "asd";

  int cmp = s21_strncmp(str1, str2, 2);

  ck_assert_int_eq(cmp, 0);
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
  tcase_add_test(tc_core, strncmp_7);
  tcase_add_test(tc_core, strncmp_8);
  tcase_add_test(tc_core, strncmp_9);

  suite_add_tcase(s, tc_core);

  return s;
}