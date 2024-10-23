SOURCE = ft_bzero.c   ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c  ft_memcpy.c  ft_memset.c \
ft_strchr.c  ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_substr.c  ft_toupper.c ft_atoi.c \
ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memmove.c ft_split.c ft_strdup.c \
ft_strlcat.c ft_strlen.c ft_strnstr.c ft_strtrim.c ft_tolower.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c dl_lstadd_back.c \
dl_lstadd_front.c dl_lstclear.c dl_lstdelone.c dl_lstnew.c dl_lstsize.c ft_strcreate.c

OBJETS = $(SOURCE:.c=.o)

BONUSOBJ = $(BONUS:.c.o)

FLAG = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = ../inc/libft.h

INCLUDE_2 = ../inc/push_swap.h

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

all: $(NAME)

$(NAME): $(OBJETS)
	@ar -src $(NAME) $(OBJETS)

bonus: $(BONUSOBJ) $(OBJETS)
	@ar -src $(NAME) $(OBJETS)

$(OBJETS): $(BONUSOBJ)
	@gcc $(FLAG) -I $(INCLUDE) -I $(INCLUDE_2) -c ${@:.o=.c} -o $@

clean:
	@rm -f $(OBJETS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
