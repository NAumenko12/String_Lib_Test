#include "s21_sscanf.h"

static int parse_unsigned(const char **str_ptr, int length_modifier, va_list args) {
    unsigned long long int value = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(&str_ptr);

    while (isdigit(**str_ptr)) {
        value = value * 10 + (**str_ptr - '0');
        (*str_ptr)++;
    }

    if (length_modifier == 1) {
        unsigned short int *p = va_arg(args, unsigned short int *);
        if (p) *p = (unsigned short int)value;
    } else if (length_modifier == 2) {
        unsigned long int *p = va_arg(args, unsigned long int *);
        if (p) *p = (unsigned long int)value;
    } else {
        unsigned int *p = va_arg(args, unsigned int *);
        if (p) *p = (unsigned int)value;
    }

    return (*str_ptr != start_ptr);
}