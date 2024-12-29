CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c move.c init.c free.c utils.c valid.c
LIB = ft_printf/
LIBA = libftprintf.a
LIB_PATH = $(LIB)libft/
OFILES = $(SRCS:.c=.o)
NAME = so_long
MLX_PATH = ../minilibx-linux
MLX_LIB = -L$(MLX_PATH) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIB)
	cp $(LIB)$(LIBA) .
	$(CC) $(CFLAGS) $(OFILES) $(LIBA) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	make -C $(LIB) clean

fclean: clean
	rm -f $(NAME) $(LIBA)
	make -C $(LIB) fclean

re: fclean all
