#include "s21_sscanf.h"

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
