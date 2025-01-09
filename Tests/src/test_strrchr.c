#include <check.h>

#include "s21_string.h"

START_TEST(strrchr_1) {
  char src[] = "qweasdzxc";

  char* ret = s21_strrchr(src, '1');

  ck_assert_ptr_eq(ret, S21_NULL);
}
END_TEST

START_TEST(strrchr_2) {
  char src[] = "eweasdzxc";

  char* ret = s21_strrchr(src, 'e');

  ck_assert_ptr_eq(ret, src + 2);
}
END_TEST

START_TEST(strrchr_3) {
  char src[] = "\tw\tasdzxc";

  char* ret = s21_strrchr(src, '\t');

  ck_assert_ptr_eq(ret, src + 2);
}
END_TEST

START_TEST(strrchr_4) {
  char src[] = "";

  char* ret = s21_strrchr(src, '\0');

  ck_assert_ptr_eq(ret, src);
}
END_TEST

Suite* strrchr_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strrchr");
  tc_core = tcase_create("strrchr");

  tcase_add_test(tc_core, strrchr_1);
  tcase_add_test(tc_core, strrchr_2);
  tcase_add_test(tc_core, strrchr_3);
  tcase_add_test(tc_core, strrchr_4);

  suite_add_tcase(s, tc_core);

  return s;
}