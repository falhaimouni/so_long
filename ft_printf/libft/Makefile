CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isalpha.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_memcpy.c \
        ft_memset.c ft_strlcat.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
	ft_strncmp.c ft_strnstr.c ft_atoi.c ft_memmove.c ft_memchr.c ft_strdup.c ft_calloc.c ft_substr.c \
	ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_memcmp.c ft_itoa.c ft_strmapi.c ft_putstr_fd.c ft_putnbr_fd.c\
	ft_putendl_fd.c ft_striteri.c ft_split.c get_next_line.c
OFILES = $(SRCS:.c=.o)
BONUS =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBON = $(BONUS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES) 

bonus: $(OBON) $(OFILES)
	@ar rcs	$(NAME)	 $(OFILES) $(OBON)

clean:
	rm -f $(OFILES) $(OBON)
fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
