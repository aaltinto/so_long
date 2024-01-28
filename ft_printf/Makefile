NAME = printf.a
FLAG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_functions.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) ft_printf.o ft_functions.o
clean:
	/bin/rm -f  ft_printf.o ft_functions.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re