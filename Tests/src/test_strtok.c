#include <check.h>

#include "s21_string.h"

START_TEST(strtok_1) {
  char str[] = "192.168.255.255";
  char expected[] = "192\000168\000255\000255";
  char del[] = ".";
  char* tokens[10] = {0};
  int idx = 0;

  char* ret = s21_strtok(str, del);

  while (ret != S21_NULL) {
    tokens[idx++] = ret;
    ret = s21_strtok(S21_NULL, del);
  }

  ck_assert_mem_eq(str, expected, sizeof(str));
  ck_assert_pstr_eq(tokens[0], str);
  ck_assert_pstr_eq(tokens[1], str + 4);
  ck_assert_pstr_eq(tokens[2], str + 8);
  ck_assert_pstr_eq(tokens[3], str + 12);
}
END_TEST

START_TEST(strtok_2) {
  char str[] =
      "Особенности национальной рыбалки - художественный, комедийный фильм.";
  char expected[] =
      "Особенности\0национальной\0рыбалки\0- художественный\0 комедийный\0фи"
      "льм\0";
  char del[] = " ,.-";
  char* tokens[10] = {0};
  int idx = 0;

  char* ret = s21_strtok(str, del);

  while (ret != S21_NULL) {
    tokens[idx++] = ret;
    ret = s21_strtok(S21_NULL, del);
  }

  ck_assert_mem_eq(str, expected, sizeof(str));
  ck_assert_str_eq(tokens[0], "Особенности");
  ck_assert_str_eq(tokens[1], "национальной");
  ck_assert_str_eq(tokens[2], "рыбалки");
  ck_assert_str_eq(tokens[3], "художественный");
  ck_assert_str_eq(tokens[4], "комедийный");
  ck_assert_str_eq(tokens[5], "фильм");
}
END_TEST

START_TEST(strtok_3) {
  char str[] = "https://edu.21-school.ru/";
  char expected[] = "https://edu.21-school.ru/";
  char del[] = "afAF";
  char* tokens[10] = {0};
  int idx = 0;

  char* ret = s21_strtok(str, del);

  while (ret != S21_NULL) {
    tokens[idx++] = ret;
    ret = s21_strtok(S21_NULL, del);
  }

  ck_assert_mem_eq(str, expected, sizeof(str));
  ck_assert_str_eq(tokens[0], expected);
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "";
  char expected[] = "";
  char del[] = " .,";
  char* tokens[10] = {0};
  int idx = 0;

  char* ret = s21_strtok(str, del);

  while (ret != S21_NULL) {
    tokens[idx++] = ret;
    ret = s21_strtok(S21_NULL, del);
  }

  ck_assert_mem_eq(str, expected, sizeof(str));
  ck_assert_pstr_eq(tokens[0], S21_NULL);
}
END_TEST

Suite* strtok_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strtok");
  tc_core = tcase_create("strtok");

  tcase_add_test(tc_core, strtok_1);
  tcase_add_test(tc_core, strtok_2);
  tcase_add_test(tc_core, strtok_3);
  tcase_add_test(tc_core, strtok_4);

  suite_add_tcase(s, tc_core);

  return s;
}