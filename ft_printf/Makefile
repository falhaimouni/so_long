CC = cc 
CFLAGS = -Werror -Wextra -Wall -g
SRCS = ft_printf.c ft_len.c ft_conversion.c ft_putnum.c ft_pointerhex.c
LIB = libft/
LIBA = libft.a
OFILES = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	@make -C $(LIB)
	@cp $(LIB)$(LIBA) .
	@mv $(LIBA) $(NAME)
	@ar rcs $(NAME) $(OFILES)
clean: 
	rm -f $(OFILES)
	@make -C $(LIB) clean

fclean: clean 
	rm -f $(NAME)
	@make -C $(LIB) fclean
	
re: fclean all