#include "s21_sscanf.h"

static int parse_string(const char **str_ptr, int width, va_list args) {
    char *str = va_arg(args, char *);
    if (str) {
        const char *start_ptr = *str_ptr;
        int count = 0;

        skip_spaces(&str_ptr);

        while (**str_ptr && (!isspace(**str_ptr) || width != -1) && (width == -1 || count < width)) {
            *str++ = **str_ptr;
            (*str_ptr)++;
            count++;
        }
        *str = '\0';

        if (*str_ptr != start_ptr) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}