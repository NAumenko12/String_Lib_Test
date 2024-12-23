#include "s21_sscanf.h"

static int parse_count(const char **str_ptr, va_list args) {
    int *p = va_arg(args, int *);
    if (p) {
        *p = *str_ptr - str; 
    }
    return 0; 
}