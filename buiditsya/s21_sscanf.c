#include "s21_sscanf.h"
#include "s21_string.h"



int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = parse_input(str, format, args);
    va_end(args);
    return result;
}


static void skip_spaces(const char **ptr) {
    while (isspace(**ptr)) {
        (*ptr)++;
    }
}

static int parse_value(const char **str_ptr, const char *format_ptr, int width, int length_modifier, va_list args, const char *str) {
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
            value = parse_count(str_ptr, str, args);
            break;
        case 's':
            value = parse_string(str_ptr, width, args);
            break;
        default:
            break;
    }
    return value;
}

static int parse_unsigned(const char **str_ptr, int length_modifier, va_list args) {
    unsigned long long int value = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(str_ptr);

    while (isdigit(**str_ptr)) {
        value = value * 10 + (**str_ptr - '0');
        (*str_ptr)++;
    }

    if (length_modifier == 1) {
        unsigned short int *p = va_arg(args, unsigned short int *);
        if (p) *p = (unsigned short int)value;
    } else if (length_modifier == 2) {
        unsigned long int *p = va_arg(args, unsigned long int *);
        if (p) *p = (unsigned long int)value;
    } else {
        unsigned int *p = va_arg(args, unsigned int *);
        if (p) *p = (unsigned int)value;
    }

    return (*str_ptr != start_ptr);
}

static int parse_string(const char **str_ptr, int width, va_list args) {
    char *str = va_arg(args, char *);
    if (str) {
        const char *start_ptr = *str_ptr;
        int count = 0;

        skip_spaces(str_ptr);

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

static int parse_pointer(const char **str_ptr, va_list args) {
    unsigned long long int value = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(str_ptr);

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

static int parse_octal(const char **str_ptr, int length_modifier, va_list args) {
    unsigned long long int value = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(str_ptr);

    if (**str_ptr == '0') {
        (*str_ptr)++;
    }

    while (isdigit(**str_ptr) && **str_ptr >= '0' && **str_ptr <= '7') {
        value = value * 8 + (**str_ptr - '0');
        (*str_ptr)++;
    }

    if (length_modifier == 1) {
        unsigned short int *p = va_arg(args, unsigned short int *);
        if (p) *p = (unsigned short int)value;
    } else if (length_modifier == 2) {
        unsigned long int *p = va_arg(args, unsigned long int *);
        if (p) *p = (unsigned long int)value;
    } else {
        unsigned int *p = va_arg(args, unsigned int *);
        if (p) *p = (unsigned int)value;
    }

    return (*str_ptr != start_ptr);
}


static int parse_number(const char **format_ptr) {
    int number = 0;
    while (is_digit(**format_ptr)) {
        number = number * 10 + (**format_ptr - '0');
        (*format_ptr)++;
    }
    return number;
}

static void parse_length_modifier(const char **format_ptr, int *length_modifier) {
    switch (**format_ptr) {
        case 'h': *length_modifier = 1; break;
        case 'l': *length_modifier = 2; break;
        default: *length_modifier = 3; break;
    }
    (*format_ptr)++;
}

static int parse_int(const char **str_ptr, int length_modifier, va_list args) {
    int base = 10;
    int negative = 0;
    const char *start_ptr = *str_ptr;
    skip_spaces(str_ptr);
    if (**str_ptr == '+' || **str_ptr == '-') {
        negative = (**str_ptr == '-');
        (*str_ptr)++;
    }
    if (**str_ptr == '0') {
        base = 8;
        (*str_ptr)++;
        if (**str_ptr == 'x' || **str_ptr == 'X') {
            base = 16;
            (*str_ptr)++;
        }
    }
    long long int value = 0;
    int digit;
    while ((digit = parse_digit(**str_ptr, base)) != -1) {
        value = value * base + digit;
        (*str_ptr)++;
    }
    if (length_modifier == 1) {
        short int *p = va_arg(args, short int *);
        if (p) {
            *p = (short int)(negative ? -value : value);
        }
    } else if (length_modifier == 2) {
        long int *p = va_arg(args, long int *);
        if (p) {
            *p = (long int)(negative ? -value : value);
        }
    } else {
        int *p = va_arg(args, int *);
        if (p) {
            *p = (int)(negative ? -value : value);
        }
    }

    if (*str_ptr != start_ptr) {
        return 1;
    } else {
        return 0; 
    }
}

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
            result += parse_value(&str_ptr, format_ptr, width, length_modifier, args, str);
            format_ptr++;
        }
    }

    return result;
}

static int parse_hex(const char **str_ptr, int length_modifier, va_list args){
    unsigned long long int value = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(str_ptr);

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

    if (length_modifier == 1) {
        unsigned short int *p = va_arg(args, unsigned short int *);
        if (p) *p = (unsigned short int)value;
    } else if (length_modifier == 2) {
        unsigned long int *p = va_arg(args, unsigned long int *);
        if (p) *p = (unsigned long int)value;
    } else {
        unsigned int *p = va_arg(args, unsigned int *);
        if (p) *p = (unsigned int)value;
    }

    return (*str_ptr != start_ptr);
}

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

static int parse_float(const char **str_ptr, va_list args) {
    double value = 0.0;
    int negative = 0;
    const char *start_ptr = *str_ptr;

    skip_spaces(str_ptr);

    if (**str_ptr == '+' || **str_ptr == '-') {
        negative = (**str_ptr == '-');
        (*str_ptr)++;
    }
    while (isdigit(**str_ptr)) {
        value = value * 10 + (**str_ptr - '0');
        (*str_ptr)++;
    }
    if (**str_ptr == '.') {
        (*str_ptr)++;
        double fraction = 1.0;
        while (isdigit(**str_ptr)) {
            fraction /= 10.0;
            value += (**str_ptr - '0') * fraction;
            (*str_ptr)++;
        }
    }
    if (**str_ptr == 'e' || **str_ptr == 'E') {
        (*str_ptr)++;
        int exponent_negative = 0;
        if (**str_ptr == '+' || **str_ptr == '-') {
            exponent_negative = (**str_ptr == '-');
            (*str_ptr)++;
        }
        int exponent = 0;
        while (isdigit(**str_ptr)) {
            exponent = exponent * 10 + (**str_ptr - '0');
            (*str_ptr)++;
        }
        if (exponent_negative) {
            exponent = -exponent;
        }
        value *= pow(10, exponent);
    }

    if (negative) {
        value = -value;
    }

    double *p = va_arg(args, double *);
    if (p) {
        *p = value;
    }

    return (*str_ptr != start_ptr);
}

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

static int parse_digit(char c, int base) {
    int digit = -1;

    if (isdigit(c)) {
        digit = c - '0';
    } else if (base == 16 && isxdigit(c)) {
        if (isupper(c)) {
            digit = c - 'A' + 10;
        } else {
            digit = c - 'a' + 10;
        }
    }

    if (digit >= 0 && digit < base) {
        return digit;
    } else {
        return -1;
    }
}

static int parse_char(const char **str_ptr, va_list args) {
    char *c = va_arg(args, char *);
    if (c) {
        *c = **str_ptr;
        (*str_ptr)++;
        return 1;
    }
    return 0; 
}

static int parse_count(const char **str_ptr, const char*str,  va_list args) {
    int *p = va_arg(args, int *);
    if (p) {
        *p = *str_ptr - str; 
    }
    return 0; 
} 
