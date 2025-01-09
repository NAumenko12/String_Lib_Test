#include <check.h>

#include "s21_string.h"

START_TEST(strerror_1) {
  int errcode = 0;

#ifdef __linux__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Success");

#elif __APPLE__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Error 0");

#endif
}
END_TEST

START_TEST(strerror_2) {
  int errcode = 1;

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Operation not permitted");
}
END_TEST

START_TEST(strerror_3) {
  int errcode = -1;
#ifdef __linux__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Unknown error");

#elif __APPLE__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Unknown error");

#endif
}
END_TEST

START_TEST(strerror_4) {
  int errcode = -112;
#ifdef __linux__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Unknown error");

#elif __APPLE__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Unknown error");

#endif
}
END_TEST

START_TEST(strerror_5) {
  int errcode = 666;
#ifdef __linux__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Unknown error");

#elif __APPLE__

  char* ret = s21_strerror(errcode);

  ck_assert_pstr_eq(ret, "Unknown error");

#endif
}
END_TEST

Suite* strerror_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strerror");
  tc_core = tcase_create("strerror");

  tcase_add_test(tc_core, strerror_1);
  tcase_add_test(tc_core, strerror_2);
  tcase_add_test(tc_core, strerror_3);
  tcase_add_test(tc_core, strerror_4);
  tcase_add_test(tc_core, strerror_5);

  suite_add_tcase(s, tc_core);

  return s;
}