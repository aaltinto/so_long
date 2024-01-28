NAME = so_long
FLAG = -framework OpenGL -framework AppKit -Wall -Wextra -Werror
SRC = main.c\
		map.c\
		map_reader.c\
		so_long_utils.c\
		ft_printf/printf.a\
		libft/libft.a\
		ft_get_next_line/gnl.a
SRC_BONUS = main_bonus.c\
		map_b.c\
		map_reader_b.c\
		so_long_b_utils.c\
		so_long_b_utils_2.c\
		ft_printf/printf.a\
		libft/libft.a\
		ft_get_next_line/gnl.a

all: $(NAME)

$(NAME) :
	make all -C ft_printf
	make all -C libft
	make all -C ft_get_next_line
	gcc $(SRC) $(FLAG) -o $(NAME) mlx/libmlx.a

bonus:
	make all -C ft_printf
	make all -C libft
	make all -C ft_get_next_line
	gcc $(SRC_BONUS) $(FLAG) -o $(NAME) mlx/libmlx.a
clean:
	make clean -C ft_get_next_line
	make clean -C ft_printf
	make all -C libft
fclean: 
	make fclean -C ft_get_next_line
	make fclean -C libft
	make fclean -C ft_printf
	rm $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re