# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 13:50:02 by vrabaib           #+#    #+#              #
#    Updated: 2019/05/27 11:18:42 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = display.h keys.h fractol.h

SRC = mandelbrot.c julia.c tricorn.c main.c utils.c utils2.c utils3.c 

SRCO = $(SRC:.c=.o)

LIB = libft/libft.a

GL = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@echo "Cleaning and Re-Making libft..."
	@make -C libft/ fclean && make -C libft/
	@echo "Compiling files with libft..."
	@clang -Wall -Werror -Wextra -c $(SRC) -I libft/includes 
	@echo "Linking graphics library to all files..."
	@clang $(GL) $(SRCO) $(LIB) -o $(NAME) 

all: $(NAME)

clean:
	@echo "Removing object files"
	@/bin/rm -rf $(SRCO) 
	@make -C libft clean

fclean: clean
	@echo "Removing dependencies with make"
	@/bin/rm -rf $(NAME) 
	@make -C libft fclean

re: fclean all
	@echo "Remaking :D"

.PHONY: clean fclean 
