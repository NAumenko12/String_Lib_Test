#include "s21_sscanf.h"

static int parse_float(const char **str_ptr, va_list args) {
    double value = 0.0;
    int negative = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(&str_ptr);

    if (**str_ptr == '+' || **str_ptr == '-') {
        negative = (**str_ptr == '-');
        (*str_ptr)++;
    }
    while (isdigit(**str_ptr)) {
        value = value * 10 + (**str_ptr - '0');
        (*str_ptr)++;
    }
    if (**str_ptr == '.') {
        (*str_ptr)++;
        double fraction = 1.0;
        while (isdigit(**str_ptr)) {
            fraction /= 10.0;
            value += (**str_ptr - '0') * fraction;
            (*str_ptr)++;
        }
    }
    if (**str_ptr == 'e' || **str_ptr == 'E') {
        (*str_ptr)++;
        int exponent_negative = 0;
        if (**str_ptr == '+' || **str_ptr == '-') {
            exponent_negative = (**str_ptr == '-');
            (*str_ptr)++;
        }
        int exponent = 0;
        while (isdigit(**str_ptr)) {
            exponent = exponent * 10 + (**str_ptr - '0');
            (*str_ptr)++;
        }
        if (exponent_negative) {
            exponent = -exponent;
        }
        value *= pow(10, exponent);
    }

    if (negative) {
        value = -value;
    }

    double *p = va_arg(args, double *);
    if (p) {
        *p = value;
    }

    return (*str_ptr != start_ptr);
}