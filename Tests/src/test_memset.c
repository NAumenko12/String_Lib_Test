#include <check.h>

#include "s21_string.h"

START_TEST(memset_1) {
  char newbuf[16] = {0};
  char expected[16] = "aaa";

  s21_memset(newbuf, 'a', 3);

  ck_assert_mem_eq(newbuf, expected, sizeof(newbuf));
}
END_TEST

START_TEST(memset_2) {
  char oldbuf[16] = {0};
  char newbuf[16] = {0};

  const char* ret = s21_memset(newbuf, 'a', 0);

  ck_assert_mem_eq(oldbuf, ret, sizeof(oldbuf));
}
END_TEST

START_TEST(memset_3) {
  char buf[16] = {0};
  char expected[16] = "\000\000\000aaa";

  s21_memset(buf + 3, 'a', 3);

  ck_assert_mem_eq(buf, expected, sizeof(buf));
}
END_TEST

Suite* memset_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("memset");
  tc_core = tcase_create("memset");

  tcase_add_test(tc_core, memset_1);
  tcase_add_test(tc_core, memset_2);
  tcase_add_test(tc_core, memset_3);

  suite_add_tcase(s, tc_core);

  return s;
}