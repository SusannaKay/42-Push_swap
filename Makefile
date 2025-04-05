NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = 	operations/swap.c\
		operations/push.c\
		operations/rotate.c\
		operations/reverse.c\
		utils/parse_utils.c\
		utils/list_utils.c\
		utils/array_utils.c\
		utils/sort_utils.c\
		utils/radix_sort.c\
		push_swap.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re