#include "s21_sscanf.h"

static void parse_length_modifier(const char **format_ptr, int *length_modifier) {
    switch (**format_ptr) {
        case 'h': *length_modifier = 1; break;
        case 'l': *length_modifier = 2; break;
        default: *length_modifier = 3; break;
    }
    (*format_ptr)++;
}