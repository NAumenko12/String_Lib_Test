#include <check.h>

#include "s21_string.h"

START_TEST(strncat_1) {
  char src[] = "qweasdzxc";
  char dest1[16] = "12345";
  char dest2[16] = "12345";

  strncat(dest2, src, sizeof(dest1) - sizeof("12345"));
  s21_strncat(dest1, src, sizeof(dest1) - sizeof("12345"));

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_2) {
  char src[] = "qweasdzxc";
  char dest1[16] = "12345678zxc";
  char dest2[16] = "12345678zxc";

  strncat(dest2, src, sizeof(dest1) - sizeof("12345678zxc"));
  s21_strncat(dest1, src, sizeof(dest1) - sizeof("12345678zxc"));

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_3) {
  char src[] = "qweasdzxc";
  char dest2[16] = "12345678zxc";
  char dest1[16] = "12345678zxc";

  strncat(dest2, src, 0);
  s21_strncat(dest1, src, 0);

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_4) {
  char dest1[16] = "12345678zxc";
  char dest2[16] = "12345678zxc";

  strncat(dest2, "", 10);
  s21_strncat(dest1, "", 10);

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_5) {
  char dest1[16] = "12345678zxc";
  char dest2[16] = "12345678zxc";

  strncat(dest2, "123", 10);
  s21_strncat(dest1, "123", 10);

  ck_assert_pstr_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_6) {
  char src[] = "qwe\0asd";
  char dest1[24] = "12345678";
  char dest2[24] = "12345678";

  strncat(dest2, src, 10);
  s21_strncat(dest1, src, 10);

  ck_assert_pstr_eq(dest1, dest2);
  ck_assert_mem_eq(dest1, dest2, sizeof("12345678qwe\0asd"));
}
END_TEST

Suite* strncat_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("strncat");
  tc_core = tcase_create("strncat");

  tcase_add_test(tc_core, strncat_1);
  tcase_add_test(tc_core, strncat_2);
  tcase_add_test(tc_core, strncat_3);
  tcase_add_test(tc_core, strncat_4);
  tcase_add_test(tc_core, strncat_5);
  tcase_add_test(tc_core, strncat_6);

  suite_add_tcase(s, tc_core);

  return s;
}