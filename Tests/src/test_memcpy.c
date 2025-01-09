#include <check.h>

#include "s21_string.h"

START_TEST(memcpy_1) {
  const char str[] = "ABCDEFG";
  char buf[16] = {0};

  __attribute_maybe_unused__ const char* ret =
      s21_memcpy(buf, str, sizeof(str));

  ck_assert_pstr_eq(buf, str);
}
END_TEST

START_TEST(memcpy_2) {
  const char str[] = "ABCDEFG";
  char buf[16] = {0};

  const char* ret = s21_memcpy(buf, str, sizeof(str));

  ck_assert_pstr_eq(ret, str);
}
END_TEST

START_TEST(memcpy_3) {
  const char str[] = "ABCDEFG\0abcdefg";
  char buf[16] = {0};

  const char* ret = s21_memcpy(buf, str, sizeof(str));

  ck_assert_pstr_eq(ret, str);
  ck_assert_pstr_eq(ret + 8, str + 8);
}
END_TEST

START_TEST(memcpy_4) {
  const char str[] = "ABCDEFG";
  char buf[16] = "123";

  const char* ret = s21_memcpy(buf, str, 0);

  ck_assert_pstr_eq(ret, "123");
}
END_TEST

START_TEST(memcpy_5) {
  int src = 0xff << 15;
  int dest = 0;

  int* ret = s21_memcpy(&dest, &src, sizeof(int));

  ck_assert_int_eq(*ret, 0xff << 15);
}
END_TEST

Suite* memcpy_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("memcpy");
  tc_core = tcase_create("memcpy");

  tcase_add_test(tc_core, memcpy_1);
  tcase_add_test(tc_core, memcpy_2);
  tcase_add_test(tc_core, memcpy_3);
  tcase_add_test(tc_core, memcpy_4);
  tcase_add_test(tc_core, memcpy_5);

  suite_add_tcase(s, tc_core);

  return s;
}