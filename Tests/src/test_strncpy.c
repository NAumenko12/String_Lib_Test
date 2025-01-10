#include <check.h>

#include "s21_string.h"

START_TEST(strncpy_1) {
  char dest1[16] = {0};
  char dest2[16] = {0};
  char src[] = "asd";

  char* expected = strncpy(dest2, src, sizeof(dest1) - 1);
  char* ret = s21_strncpy(dest1, src, sizeof(dest1) - 1);

  ck_assert_pstr_eq(ret, expected);
}
END_TEST

START_TEST(strncpy_2) {
  char dest1[16] = "qwe";
  char dest2[16] = "qwe";
  char src[] = "asd";

  strncpy(dest2, src, sizeof(dest1) - 3 - 1);
  s21_strncpy(dest1, src, sizeof(dest1) - 3 - 1);

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_3) {
  char dest1[16] = "qwe";
  char dest2[16] = "qwe";
  char src[] = "asd\0zxc";

  strncpy(dest2, src, sizeof(dest1) - 3 - 1);
  s21_strncpy(dest1, src, sizeof(dest1) - 3 - 1);

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_4) {
  char dest1[16] = "qwezxc12345";
  char dest2[16] = "qwezxc12345";
  char src[] = "asd";

  strncpy(dest2, src, sizeof(dest2) - 3 - 1);
  s21_strncpy(dest1, src, sizeof(dest1) - 3 - 1);

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

Suite* strncpy_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strncpy");
  tc_core = tcase_create("strncpy");

  tcase_add_test(tc_core, strncpy_1);
  tcase_add_test(tc_core, strncpy_2);
  tcase_add_test(tc_core, strncpy_3);
  tcase_add_test(tc_core, strncpy_4);

  suite_add_tcase(s, tc_core);

  return s;
}