#include <check.h>

#include "s21_string.h"

START_TEST(memcpy_1) {
  const char str[] = "ABCDEFG";
  char buf1[16] = {0};
  char buf2[16] = {0};

  memcpy(buf2, str, sizeof(str));
  s21_memcpy(buf1, str, sizeof(str));

  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(memcpy_2) {
  const char str[] = "ABCDEFG";
  char buf1[16] = {0};
  char buf2[16] = {0};

  const char* expected = memcpy(buf2, str, sizeof(str));
  const char* ret = s21_memcpy(buf1, str, sizeof(str));

  ck_assert_pstr_eq(ret, expected);
}
END_TEST

START_TEST(memcpy_3) {
  const char str[] = "ABCDEFG\0abcdefg";
  char buf1[16] = {0};
  char buf2[16] = {0};

  const char* expected = memcpy(buf2, str, sizeof(str));
  const char* ret = s21_memcpy(buf1, str, sizeof(str));

  ck_assert_pstr_eq(ret, expected);
  ck_assert_pstr_eq(ret + 8, expected + 8);
}
END_TEST

START_TEST(memcpy_4) {
  const char str[] = "ABCDEFG";
  char buf1[16] = "123";
  char buf2[16] = "123";

  const char* expected = memcpy(buf2, str, 0);
  const char* ret = s21_memcpy(buf1, str, 0);

  ck_assert_pstr_eq(ret, expected);
}
END_TEST

START_TEST(memcpy_5) {
  int src = 0xff << 15;
  int dest1 = 0;
  int dest2 = 0;

  int* expected = memcpy(&dest2, &src, sizeof(int));
  int* ret = s21_memcpy(&dest1, &src, sizeof(int));

  ck_assert_int_eq(*ret, *expected);
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