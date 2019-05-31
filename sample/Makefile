# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 13:50:02 by vrabaib           #+#    #+#              #
#    Updated: 2019/05/27 12:46:30 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sample

SRC = sample.c

SRCO = $(SRC:.c=.o)

GL = -L../minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@clang -Wall -Werror -Wextra -c $(SRC) 
	@echo "Linking graphics library to all files..."
	@clang $(GL) $(SRCO) -o $(NAME) 

all: $(NAME)

clean:
	@echo "Removing object files"
	@/bin/rm -rf $(SRCO) 

fclean: clean
	@echo "Removing dependencies with make"
	@/bin/rm -rf $(NAME) 

re: fclean all
	@echo "Remaking :D"

.PHONY: clean fclean 
