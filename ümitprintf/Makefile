NAME = libftprintf.a
SOURCES = \
	ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

*.o: *.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
