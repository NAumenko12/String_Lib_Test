#include "s21_sscanf.h"

static int parse_int(const char **str_ptr, int length_modifier, va_list args) {
    int base = 10;
    int negative = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(&str_ptr);

    if (**str_ptr == '+' || **str_ptr == '-') {
        negative = (**str_ptr == '-');
        (*str_ptr)++;
    }

    if (**str_ptr == '0') {
        base = 8;
        (*str_ptr)++;
        if (**str_ptr == 'x' || **str_ptr == 'X') {
            base = 16;
            (*str_ptr)++;
        }
    }

    long long int value = 0;
    int digit;
    while ((digit = parse_digit(**str_ptr, base)) != -1) {
        value = value * base + digit;
        (*str_ptr)++;
    }

    if (length_modifier == 1) {
        short int *p = va_arg(args, short int *);
        if (p) {
            *p = (short int)(negative ? -value : value);
        }
    } else if (length_modifier == 2) {
        long int *p = va_arg(args, long int *);
        if (p) {
            *p = (long int)(negative ? -value : value);
        }
    } else {
        int *p = va_arg(args, int *);
        if (p) {
            *p = (int)(negative ? -value : value);
        }
    }

    if (*str_ptr != start_ptr) {
        return 1;
    } else {
        return 0; 
    }
}


