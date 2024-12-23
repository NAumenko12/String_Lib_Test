#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>


int s21_sscanf(const char *str, const char *format, ...);
static int parse_input(const char *str, const char *format, va_list args);
static void parse_format_specifier(const char **format_ptr, int *flags, int *width, int *precision, int *length_modifier);
static int parse_value(const char **str_ptr, const char *format_ptr, int width, int length_modifier, va_list args);
static int parse_char(const char **str_ptr, va_list args);
static int parse_int(const char **str_ptr, int length_modifier, va_list args);
static int parse_string(const char **str_ptr, int width, va_list args);
static int parse_digit(char c, int base);
static void skip_spaces(const char **ptr);
static void parse_flag(const char **format_ptr, int *flags);
static int parse_number(const char **format_ptr);
static void parse_length_modifier(const char **format_ptr, int *length_modifier);
static int parse_float(const char **str_ptr, va_list args);
static int parse_octal(const char **str_ptr, int length_modifier, va_list args);
static int parse_unsigned(const char **str_ptr, int length_modifier, va_list args);
static int parse_hex(const char **str_ptr, int length_modifier, va_list args) ;
static int parse_pointer(const char **str_ptr, va_list args);
static int parse_count(const char **str_ptr, va_list args);

#define is_flag(c) ((c) == ' ' || (c) == '+' || (c) == '-' || (c) == '#' || (c) == '0')
#define is_digit(c) (isdigit((unsigned char)(c)))
#define is_length(c) ((c) == 'h' || (c) == 'l' || (c) == 'L')

#endif 