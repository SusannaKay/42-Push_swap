NAME = push_swap
CFLAGS = -g -gdwarf-4 -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = 	operations/swap.c\
		operations/push.c\
		operations/rotate.c\
		operations/reverse.c\
		utils/parsing.c\
		push_swap.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(CFLAGS) $(LIBFT) $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) $(LIBFT_PATH) -O3 -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all clean fclean re