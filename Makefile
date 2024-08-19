# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by najeuneh          #+#    #+#              #
#    Updated: 2024/08/19 15:59:10 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

CC = cc

MY_SOURCES = src/lexer.c src/main.c src/signal.c src/parser/parcer.c src/parser/parser_utils.c src/heredoc.c src/parser/parser_utils2.c \
			src/exec/exec.c src/exec/exec_utils.c src/bultins/echo.c src/bultins/bultins_utils.c \
			src/bultins/cd.c src/bultins/env.c src/bultins/exit.c src/bultins/export.c src/bultins/pwd.c src/bultins/unset.c \

CFLAGS = -c -Wall -Werror -Wextra

LINK = -L/Users/najeuneh/.brew/opt/readline/lib -I/Users/najeuneh/.brew/opt/readline/include -lreadline

OBJS_DIR = obj/

SRCS_DIR = src/

NAME = minishell


INCLUDE = ./inc/minishell.h

INCLUDE2 = ./inc/pipex.h

INCLUDE3 = ./inc/libft.h

INCLUDE4 = ./inc/ft_printf.h

LIBFT = ./libft

LIBFT.A = ./libft/libft.a

PRINTF = ./ft_printf

PRINTF.A = ./ft_printf/libftprintf.a


MY_OBJECTS = $(MY_SOURCES:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	@make -C $(LIBFT)
	@printf "                                               \r"
	@echo "																					 "
	@echo "           _       _     _          _ _ "
	@echo "          (_)     (_)   | |        | | |"
	@echo " _ __ ___  _ _ __  _ ___| |__   ___| | |"
	@echo "| '_   _ \| |  _ \| / __| '_ \ / _ \ | |"
	@echo "| | | | | | | | | | \__ \ | | |  __/ | |"
	@echo "|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|"
	@echo "                                                                                  "    	
	cc $(MY_OBJECTS) $(LIBFT.A) $(LINK) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/bultins
	@mkdir -p $(OBJS_DIR)/parser
	@mkdir -p $(OBJS_DIR)/exec
	$(CC) $(CFLAGS) -I/inc/ -o $@ -c $<

debug: $(MY_OBJECTS)
	@make -C $(LIBFT)
	@cc -fsanitize=address -g3 $(MY_OBJECTS) $(LIBFT.A) -I/inc/ $(LINK) -o $(NAME)
	
clean:
	@make clean -C $(LIBFT)
	@${RM} ${MY_OBJECTS}


fclean: clean
	@make fclean -C $(LIBFT)
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all