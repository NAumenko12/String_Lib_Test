#include "s21_sscanf.h"

static int parse_input(const char *str, const char *format, va_list args) {
    int result = 0;
    const char *str_ptr = str;
    const char *format_ptr = format;

    while (*format_ptr) {
        if (*format_ptr != '%') {
            if (*str_ptr != *format_ptr) {
                skip_spaces(&str_ptr);
                skip_spaces(&format_ptr);
            } else {
                str_ptr++;
                format_ptr++;
            }
        } else {
            format_ptr++;
            int flags = 0, width = -1, precision = -1, length_modifier = 0;
            parse_format_specifier(&format_ptr, &flags, &width, &precision, &length_modifier);
            result += parse_value(&str_ptr, format_ptr, width, length_modifier, args);
            format_ptr++;
        }
    }

    return result;
}
