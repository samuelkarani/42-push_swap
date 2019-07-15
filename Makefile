CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME1 = checker

NAME2 = push_swap

SRC1 = checker.c main.c instructions.c stack.c stack2.c utils.c utils2.c checks.c checks2.c

SRC2 = push_swap.c push_swap2.c push_swap3.c push_swap4.c main.c instructions.c \
	stack.c stack2.c utils.c utils2.c checks.c checks2.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

pre:
	@make -C libft
	@make -C libft/ft_printf
	@make -C libft/get_next_line

$(NAME1): $(OBJ1) pre	
	@$(CC) $(CFLAGS) $(OBJ1) -Llibft -lft  -Llibft/ft_printf -lftprintf \
		-Llibft/get_next_line -lftget_next_line -o $@

$(NAME2): $(OBJ2) pre
	@$(CC) $(CFLAGS) $(OBJ2) -Llibft -lft  -Llibft/ft_printf -lftprintf \
		-Llibft/get_next_line -lftget_next_line -o $@

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	@make clean -C libft/get_next_line
	@rm -f *.o

fclean:
	@make fclean -C libft
	@make fclean -C libft/ft_printf
	@make fclean -C libft/get_next_line
	@rm -f *.o
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re