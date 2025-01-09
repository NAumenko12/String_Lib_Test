#include <check.h>

#include "s21_string.h"

START_TEST(strstr_1) {
  char str[] = "qweasdzxc";
  char find[] = "zxc";

  char* ret = s21_strstr(str, find);

  ck_assert_ptr_eq(ret, str + 6);
}
END_TEST

START_TEST(strstr_2) {
  char str[] = "eweasdzxc";
  char find[] = "ASD";

  char* ret = s21_strstr(str, find);

  ck_assert_ptr_eq(ret, S21_NULL);
}
END_TEST

START_TEST(strstr_3) {
  char str[] = "\tw\tasdzxc";
  char find[] = "w\ta";

  char* ret = s21_strstr(str, find);

  ck_assert_ptr_eq(ret, str + 1);
}
END_TEST

START_TEST(strstr_4) {
  char str[] = "";
  char find[] = "ASD";

  char* ret = s21_strstr(str, find);

  ck_assert_ptr_eq(ret, S21_NULL);
}
END_TEST

START_TEST(strstr_5) {
  char str[] = "eweasdzxc";
  char find[] = "";

  char* ret = s21_strstr(str, find);

  ck_assert_ptr_eq(ret, str);
}
END_TEST

START_TEST(strstr_6) {
  char str[] = "";
  char find[] = "";

  char* ret = s21_strstr(str, find);

  ck_assert_ptr_eq(ret, str);
}
END_TEST

Suite* strstr_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strstr");
  tc_core = tcase_create("strstr");

  tcase_add_test(tc_core, strstr_1);
  tcase_add_test(tc_core, strstr_2);
  tcase_add_test(tc_core, strstr_3);
  tcase_add_test(tc_core, strstr_4);
  tcase_add_test(tc_core, strstr_5);
  tcase_add_test(tc_core, strstr_6);

  suite_add_tcase(s, tc_core);

  return s;
}