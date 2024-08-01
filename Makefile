# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by nicolive          #+#    #+#              #
#    Updated: 2024/08/01 17:44:41 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

CC = cc

MY_SOURCES = src/lexer.c  src/main.c   src/signal.c src/parser/parcer.c src/parser/parser_utils.c \

CFLAGS = -c -Wall -Werror -Wextra

LINK = -L/Users/najeuneh/.brew/opt/readline/lib -I/Users/najeuneh/.brew/opt/readline/include -lreadline

OBJS_DIR = obj/

SRCS_DIR = src/

NAME = minishell

INCLUDE = ./inc/minishell.h

INCLUDE2 = ./inc/pipex.h

INCLUDE3 = ./inc/libft.h

LIBFT = ./libft

LIBFT.A = ./libft/libft.a

PIPEX = ./pipex

PIPEX.a = ./pipex/pipex.a

MY_OBJECTS = $(MY_SOURCES:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	@make -C $(LIBFT)
	@make -C $(PIPEX)
	@printf "                                               \r"
	cc $(MY_OBJECTS) $(PIPEX.A) $(LIBFT.A) -I/inc/ $(LINK) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parser
	@$(CC) -I/inc/ -o $@ -c $<

clean:
	@make clean -C $(LIBFT)
	@make fclean -C $(PIPEX)
	@${RM} ${MY_OBJECTS}


fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(PIPEX)
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all