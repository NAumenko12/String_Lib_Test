
LIB_NAME = s21_string.a


CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
Files = s21_sscanf.c s21_string.c s21_sscanf.h s21_string.h
OBJS = $(Files:.c=.o)
HEADERS =  s21_sscanf.h s21_string.h
all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(LIB_NAME)

rebuild: clean all

