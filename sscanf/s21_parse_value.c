#include "s21_sscanf.h"


static int parse_value(const char **str_ptr, const char *format_ptr, int width, int length_modifier, va_list args) {
    int value = 0;
    switch (*format_ptr) {
        case 'c':
            value = parse_char(str_ptr, args);
            break;
        case 'd':
        case 'i':
            value = parse_int(str_ptr, length_modifier, args);
            break;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            value = parse_float(str_ptr, args);
            break;
        case 'o':
            value = parse_octal(str_ptr, length_modifier, args);
            break;
        case 'u':
            value = parse_unsigned(str_ptr, length_modifier, args);
            break;
        case 'x':
        case 'X':
            value = parse_hex(str_ptr, length_modifier, args);
            break;
        case 'p':
            value = parse_pointer(str_ptr, args);
            break;
        case 'n':
            value = parse_count(str_ptr, args);
            break;
        case 's':
            value = parse_string(str_ptr, width, args);
            break;
        default:
            break;
    }
    return value;
}