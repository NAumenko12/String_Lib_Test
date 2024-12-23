#include "s21_sscanf.h"

static void parse_flag(const char **format_ptr, int *flags) {
    switch (**format_ptr) {
        case ' ': *flags |= 1; break;
        case '+': *flags |= 2; break;
        case '-': *flags |= 4; break;
        case '#': *flags |= 8; break;
        case '0': *flags |= 16; break;
    }
    (*format_ptr)++;
}