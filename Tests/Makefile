ifeq ($(origin CC),default)
	CC = gcc
endif

CFLAGS ?= -fprofile-arcs -ftest-coverage -O0 -g -Wall -Wextra -std=c11
OUT_O_DIR ?= ./build
COMMONINC = -I../buiditsya
LDFLAGS = -L. -lcheck -lsubunit -lm --coverage

ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

override CFLAGS += $(COMMONINC)

CSRC = src/main.c src/test_memchr.c src/test_memcmp.c src/test_memcpy.c src/test_memset.c src/test_strncat.c src/test_strchr.c src/test_strncmp.c\
src/test_strncpy.c src/test_strcspn.c src/test_strerror.c src/test_strlen.c src/test_strpbrk.c src/test_strrchr.c src/test_strstr.c\
src/test_strtok.c src/test_sscanf.c src/test_sprintf.c src/test_to_upper.c src/test_to_lower.c src/test_insert.c src/test_trim.c

PREFIX = $(OUT_O_DIR)/obj

COBJ := $(addprefix $(PREFIX)/,$(CSRC:.c=.o))
DEPS = $(COBJ:.o=.d)

.PHONY: all
all: $(OUT_O_DIR)/test

$(OUT_O_DIR)/test: $(COBJ) ../buiditsya/s21_string.a
	$(CC) $^ -o $@ $(LDFLAGS)


$(COBJ) : $(PREFIX)/%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPS) : $(PREFIX)/%.d : %.c
	@mkdir -p $(@D)
	$(CC) -E $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean rebuild test
test: $(OUT_O_DIR)/test
	-./build/test

clean:
	rm -rf $(OUT_O_DIR)

rebuild: clean all

.PHONY: gcov_report
gcov_report: test
	lcov --capture --directory $(PREFIX) --output-file $(OUT_O_DIR)/coverage.info
	genhtml $(OUT_O_DIR)/coverage.info --output-directory $(OUT_O_DIR)/coverage


# targets which we have no need to recollect deps
NODEPS = clean

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
include $(DEPS)
endif
