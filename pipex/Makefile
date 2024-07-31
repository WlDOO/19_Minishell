# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by nicolive          #+#    #+#              #
#    Updated: 2024/06/18 14:36:20 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

CC = cc

MY_SOURCES = ft_pipex_all.c ft_process.c ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c main.c ft_free.c \
			 ft_strdup.c
CFLAGS = -c -Wall -Werror -Wextra 

NAME = pipex

INCLUDE = ./pipex.h

INCLUDE3 = ./ft_printf/ft_printf.h

PRINTF = ./ft_printf

PRINTF.A = ./ft_printf/libftprintf.a

MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	@$(MAKE) -C $(PRINTF)
	@printf "                                               \r"
	@echo "																					 "
	@echo "\033[0;32m░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓██████▓▒░  ░▒▓██████▓▒░  "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "                                                                                  "    	
	@cc $(PRINTF.A) -o $(NAME) $(MY_OBJECTS)

clean:
	@$(MAKE) clean -C $(PRINTF)
	@${RM} ${MY_OBJECTS}


fclean: clean
	@$(MAKE) fclean -C $(PRINTF)
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all