#include "s21_sscanf.h"

static int parse_char(const char **str_ptr, va_list args) {
    char *c = va_arg(args, char *);
    if (c) {
        *c = **str_ptr;
        (*str_ptr)++;
        return 1;
    }
    return 0; 
}
