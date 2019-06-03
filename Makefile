CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME1 = checker

NAME2 = push_swap

SRC1 = checker.c main.c instructions.c stack*.c utils*.c checks*.c

SRC2 = push_swap*.c main.c instructions.c stack*.c utils*.c checks*.c

all: $(NAME1) $(NAME2)

pre:
	@make -C libft
	@make -C libft/ft_printf
	@make -C libft/get_next_line

$(NAME1): pre	
	@$(CC) $(CFLAGS) $(SRC1) -Llibft -lft  -Llibft/ft_printf -lftprintf \
		-Llibft/get_next_line -lftget_next_line -o $@

$(NAME2): pre	
	@$(CC) $(CFLAGS) $(SRC2) -Llibft -lft  -Llibft/ft_printf -lftprintf \
		-Llibft/get_next_line -lftget_next_line -o $@

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	@make clean -C libft/get_next_line
	@rm -f *.o

fclean: clean
	@make fclean -C libft
	@make fclean -C libft/ft_printf
	@make fclean -C libft/get_next_line
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re