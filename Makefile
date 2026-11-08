NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = flags_handler.c parser.c parser_utils.c push_swap.c stack.c \
	op_push.c op_swap.c op_rotate.c op_revrotate.c simple_sort.c \
	medium_sort.c complex_sort.c sort_utils.c main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR) CC="$(CC)" CFLAGS="$(CFLAGS)"

%.o: %.c push_swap.h $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
