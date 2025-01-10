#include <check.h>

#include "s21_string.h"

START_TEST(strchr_1) {
  char src[] = "qweasdzxc";

  char* expected = strchr(src, '1');
  char* ret = s21_strchr(src, '1');

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strchr_2) {
  char src[] = "qweasdzxc";

  char* expected = strchr(src, 'e');
  char* ret = s21_strchr(src, 'e');

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strchr_3) {
  char src[] = "qw\tasdzxc";

  char* expected = strchr(src, '\t');
  char* ret = s21_strchr(src, '\t');

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

START_TEST(strchr_4) {
  char src[] = "";

  char* expected = strchr(src, '\0');
  char* ret = s21_strchr(src, '\0');

  ck_assert_ptr_eq(ret, expected);
}
END_TEST

Suite* strchr_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strchr");
  tc_core = tcase_create("strchr");

  tcase_add_test(tc_core, strchr_1);
  tcase_add_test(tc_core, strchr_2);
  tcase_add_test(tc_core, strchr_3);
  tcase_add_test(tc_core, strchr_4);

  suite_add_tcase(s, tc_core);

  return s;
}