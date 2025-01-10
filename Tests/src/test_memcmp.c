#include <check.h>

#include "s21_string.h"

START_TEST(memcmp_1) {
  const char str1[] = "1234567";
  const char str2[] = "1234567";

  int expected = memcmp(str1, str2, 7);
  int retcode = s21_memcmp(str1, str2, 7);

  ck_assert_int_eq(retcode, expected);
}
END_TEST

START_TEST(memcmp_2) {
  const char str1[] = "1234567";
  const char str2[] = "1239567";

  int expected = memcmp(str1, str2, 7);
  int retcode = s21_memcmp(str1, str2, 7);

  ck_assert_int_lt(retcode, 0);
  ck_assert_int_lt(expected, 0);
}
END_TEST

START_TEST(memcmp_3) {
  const char str1[] = "1234577";
  const char str2[] = "1234567";

  int expected = memcmp(str1, str2, 7);
  int retcode = s21_memcmp(str1, str2, 7);

  ck_assert_int_gt(retcode, 0);
  ck_assert_int_gt(expected, 0);
}
END_TEST

START_TEST(memcmp_4) {
  const char str1[] = "1234567\0QWEASD";
  const char str2[] = "1234567\0QWEASD";

  int expected = memcmp(str1, str2, 15);
  int retcode = s21_memcmp(str1, str2, 15);

  ck_assert_int_eq(retcode, expected);
}
END_TEST

START_TEST(memcmp_5) {
  const char str1[] = "1234567\0QWEASD";
  const char str2[] = "1234567\0QWEZXC";

  int expected = memcmp(str1, str2, 15);
  int retcode = s21_memcmp(str1, str2, 15);

  ck_assert_int_lt(retcode, 0);
  ck_assert_int_lt(expected, 0);
}
END_TEST

START_TEST(memcmp_6) {
  const char str1[] = "1234567\0QWEASD";
  const char str2[] = "1234567\0QWEZXC";

  int expected = memcmp(str1, str2, 0);
  int retcode = s21_memcmp(str1, str2, 0);

  ck_assert_int_eq(retcode, expected);
}
END_TEST

START_TEST(memcmp_7) {
  const char str1[] = "";
  const char str2[] = "";

  int expected = memcmp(str1, str2, 1);
  int retcode = s21_memcmp(str1, str2, 1);

  ck_assert_int_eq(retcode, expected);
}
END_TEST

Suite* memcmp_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("memcmp");
  tc_core = tcase_create("memcmp");

  tcase_add_test(tc_core, memcmp_1);
  tcase_add_test(tc_core, memcmp_2);
  tcase_add_test(tc_core, memcmp_3);
  tcase_add_test(tc_core, memcmp_4);
  tcase_add_test(tc_core, memcmp_5);
  tcase_add_test(tc_core, memcmp_6);
  tcase_add_test(tc_core, memcmp_7);

  suite_add_tcase(s, tc_core);

  return s;
}