#include <check.h>

#include "s21_string.h"

START_TEST(strncpy_1) {
  char dest[16] = {0};
  char src[] = "asd";

  char* ret = s21_strncpy(dest, src, sizeof(dest) - 1);

  ck_assert_ptr_eq(ret, dest);
}
END_TEST

START_TEST(strncpy_2) {
  char dest[16] = "qwe";
  char src[] = "asd";

  s21_strncpy(dest, src, sizeof(dest) - 3 - 1);

  ck_assert_pstr_eq(dest, "asd");
}
END_TEST

START_TEST(strncpy_3) {
  char dest[16] = "qwe";
  char src[] = "asd\0zxc";

  s21_strncpy(dest, src, sizeof(dest) - 3 - 1);

  ck_assert_pstr_eq(dest, "asd");
}
END_TEST

START_TEST(strncpy_4) {
  char src[] = "asd";

  char* ret = s21_strncpy(S21_NULL, src, 15);

  ck_assert_ptr_eq(ret, S21_NULL);
}
END_TEST

START_TEST(strncpy_5) {
  char dest[16] = "qwe";

  s21_strncpy(dest, S21_NULL, sizeof(dest) - 3 - 1);

  ck_assert_pstr_eq(dest, "qwe");
}
END_TEST

START_TEST(strncpy_6) {
  char dest[16] = "qwezxc12345";
  char src[] = "asd";

  s21_strncpy(dest, src, sizeof(dest) - 3 - 1);

  ck_assert_pstr_eq(dest, "asd");
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
  tcase_add_test(tc_core, strncpy_5);
  tcase_add_test(tc_core, strncpy_6);

  suite_add_tcase(s, tc_core);

  return s;
}