# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 22:29:00 by yasinbest         #+#    #+#              #
#    Updated: 2022/03/20 12:42:01 by tmartial         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = built_exe.c built1.c built2.c built3.c built4.c built5.c error.c\
execution.c execution2.c execution3.c free_all.c\
ft_split.c libft_utils.c libft_utils2.c main.c parseur_danny.c\
parseur_danny2.c parseur2.c parseur3.c parsing.c prepare_cmd.c prepare_cmd2.c\
prepare_cmd3.c prepare_cmd4.c\
redir_err.c redir_err2.c signal_utils.c signal.c signal2.c splitquote.c\
splitquote2.c\
test_command.c tim_libft.c tim_libft2.c tim_libftlst.c tim_lst.c\
tim_parser.c trash.c\

OBJ = $(SRC:.c=.o)
LIB		= -lreadline
CC = gcc

CFLAGS = -Wall -Wextra -Werror -I  /Users/$(USER)/.brew/opt/readline/include

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME) -L /Users/$(USER)/.brew/opt/readline/lib

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
