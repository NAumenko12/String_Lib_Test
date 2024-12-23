#include "s21_sscanf.h"

static void parse_format_specifier(const char **format_ptr, int *flags, int *width, int *precision, int *length_modifier) {
    bool stop = false;
    while (**format_ptr && !stop) {
        if (is_flag(**format_ptr)) {
            parse_flag(format_ptr, flags);
        } else if (is_digit(**format_ptr)) {
            *width = parse_number(format_ptr);
        } else if (**format_ptr == '.') {
            (*format_ptr)++;
            *precision = parse_number(format_ptr);
        } else if (is_length(**format_ptr)) {
            parse_length_modifier(format_ptr, length_modifier);
        } else {
            stop = true;
        }
    }
}