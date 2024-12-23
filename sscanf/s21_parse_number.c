#include "s21_sscanf.h"

static int parse_number(const char **format_ptr) {
    int number = 0;
    while (is_digit(**format_ptr)) {
        number = number * 10 + (**format_ptr - '0');
        (*format_ptr)++;
    }
    return number;
}