# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 22:29:00 by yasinbest         #+#    #+#              #
#    Updated: 2022/03/14 11:19:17 by ybestrio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = main.c gnl.c gnl_utils.c built1.c ft_split.c input.c test_command.c error.c splitquote.c spacers.c
OBJ = $(SRC:.c=.o)

LIB		= -lreadline
IREAD = -I/Users/$(USER)/.brew/opt/readline/include

LREAD = -L/Users/$(USER)/.brew/opt/readline/lib
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LREAD) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
