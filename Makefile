# Variables
NAME = pushswap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c stack_logic.c utils.c sort_three.c instructions/swap.c instructions/rotate.c instructions/push.c instructions/reverse.c sort_stack.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -Iinstructions -I$(LIBFT_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus		

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
