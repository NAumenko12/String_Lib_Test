#include "s21_sscanf.h"

static void skip_spaces(const char **ptr) {
    while (isspace(**ptr)) {
        (*ptr)++;
    }
}