#include <check.h>

#include "s21_string.h"

START_TEST(memchr_1) {
  const char str[] = "ABCDEFG";
  int char_to_find = 'D';

  const char* finded = s21_memchr(str, char_to_find, 7);

  ck_assert_ptr_eq(finded, str + 3);
}
END_TEST

START_TEST(memchr_2) {
  const char str[] = "ABCDEFA";
  int char_to_find = 'A';

  const char* finded = s21_memchr(str, char_to_find, 7);

  ck_assert_ptr_eq(finded, str);
}
END_TEST

START_TEST(memchr_3) {
  const char str[] = "ABCDEFA";
  int char_to_find = 'a';

  const char* finded = s21_memchr(str, char_to_find, 7);

  ck_assert_ptr_eq(finded, S21_NULL);
}
END_TEST

START_TEST(memchr_4) {
  const char str[] = "ABCDEFA";
  int char_to_find = '\0';

  const char* finded = s21_memchr(str, char_to_find, 8);

  ck_assert_ptr_eq(finded, str + 7);
}
END_TEST

START_TEST(memchr_5) {
  const char str[] = "ABCDEFA\nQWEASDZXC";
  int char_to_find = 'Z';

  const char* finded = s21_memchr(str, char_to_find, 17);

  ck_assert_ptr_eq(finded, str + 14);
}
END_TEST

Suite* memchr_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("memchr");
  tc_core = tcase_create("memchr");

  tcase_add_test(tc_core, memchr_1);
  tcase_add_test(tc_core, memchr_2);
  tcase_add_test(tc_core, memchr_3);
  tcase_add_test(tc_core, memchr_4);
  tcase_add_test(tc_core, memchr_5);

  suite_add_tcase(s, tc_core);

  return s;
}
