#include <check.h>

#include "s21_string.h"

START_TEST(strncat_1) {
  char src[] = "qweasdzxc";
  char dest[16] = "12345";

  s21_strncat(dest, src, sizeof(dest) - sizeof("12345"));

  ck_assert_pstr_eq(dest, "12345qweasdzxc");
}
END_TEST

START_TEST(strncat_2) {
  char src[] = "qweasdzxc";
  char dest[16] = "12345678zxc";

  s21_strncat(dest, src, sizeof(dest) - sizeof("12345678zxc"));

  ck_assert_pstr_eq(dest, "12345678zxcqwea");
}
END_TEST

START_TEST(strncat_3) {
  char src[] = "qweasdzxc";
  char dest[16] = "12345678zxc";

  s21_strncat(dest, src, 0);

  ck_assert_pstr_eq(dest, "12345678zxc");
}
END_TEST

START_TEST(strncat_4) {
  char dest[16] = "12345678zxc";

  s21_strncat(dest, "", 10);

  ck_assert_pstr_eq(dest, "12345678zxc");
}
END_TEST

START_TEST(strncat_5) {
  char dest[16] = "12345678zxc";

  s21_strncat(dest, "123", 10);

  ck_assert_pstr_eq(dest, "12345678zxc123");
}
END_TEST

START_TEST(strncat_6) {
  char dest[16] = "12345678";

  s21_strncat(dest, S21_NULL, 10);

  ck_assert_pstr_eq(dest, "12345678");
}
END_TEST

START_TEST(strncat_7) {
  char src[] = "qwe\0asd";
  char dest[24] = "12345678";

  s21_strncat(dest, src, 10);

  ck_assert_pstr_eq(dest, "12345678qwe");
  ck_assert_mem_ne(dest, "12345678qwe\0asd", sizeof("12345678qwe\0asd"));
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
  tcase_add_test(tc_core, strncat_7);

  suite_add_tcase(s, tc_core);

  return s;
}