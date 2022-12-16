NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) *.o
	@echo "\n\033[92m $@ built ✅\033[0m\n"
clean:
	@rm -f  *.o
	@echo "\n\033[36m object files removed 👋\033[0m\n"
fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[36m executables removed 👋\033[0m\n"

re: fclean all

.PHONY : all clean fclean re
