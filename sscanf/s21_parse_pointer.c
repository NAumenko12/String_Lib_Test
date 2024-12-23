#include "s21_sscanf.h"

static int parse_pointer(const char **str_ptr, va_list args) {
    unsigned long long int value = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(&str_ptr);

    if (**str_ptr == '0' && (**(str_ptr + 1) == 'x' || **(str_ptr + 1) == 'X')) {
        (*str_ptr) += 2;
    }

    while (isxdigit(**str_ptr)) {
        if (isdigit(**str_ptr)) {
            value = value * 16 + (**str_ptr - '0');
        } else if (isupper(**str_ptr)) {
            value = value * 16 + (**str_ptr - 'A' + 10);
        } else {
            value = value * 16 + (**str_ptr - 'a' + 10);
        }
        (*str_ptr)++;
    }

    void **p = va_arg(args, void **);
    if (p) {
        *p = (void *)(uintptr_t)value;
    }

    return (*str_ptr != start_ptr);
}