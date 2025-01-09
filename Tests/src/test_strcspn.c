#include <check.h>

#include "s21_string.h"

START_TEST(strcspn_1) {
  char src[] = "qweasdzxc\n";
  char find[] = "\n";

  s21_size_t ret = s21_strcspn(src, find);

  ck_assert_uint_eq(ret, 9);
}
END_TEST

START_TEST(strcspn_2) {
  char src[] = "qweasdzxc\n";
  char find[] = "\naz";

  s21_size_t ret = s21_strcspn(src, find);

  ck_assert_uint_eq(ret, 3);
}
END_TEST

START_TEST(strcspn_3) {
  char src[] = "qweasdzxc\n";
  char find[] = "";

  s21_size_t ret = s21_strcspn(src, find);

  ck_assert_uint_eq(ret, 10);
}
END_TEST

START_TEST(strcspn_4) {
  char src[] = "";
  char find[] = "asdzxc";

  s21_size_t ret = s21_strcspn(src, find);

  ck_assert_uint_eq(ret, 0);
}
END_TEST

Suite* strcspn_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strcspn");
  tc_core = tcase_create("strcspn");

  tcase_add_test(tc_core, strcspn_1);
  tcase_add_test(tc_core, strcspn_2);
  tcase_add_test(tc_core, strcspn_3);
  tcase_add_test(tc_core, strcspn_4);

  suite_add_tcase(s, tc_core);

  return s;
}