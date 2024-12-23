#include "s21_sscanf.h"


int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = parse_input(str, format, args);
    va_end(args);
    return result;
}











