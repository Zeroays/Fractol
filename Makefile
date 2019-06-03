# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 13:50:02 by vrabaib           #+#    #+#              #
#    Updated: 2019/06/03 15:52:02 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = includes

FRACTALS = ./fractals/mandelbrot.c ./fractals/julia.c ./fractals/tricorn.c

SRC = images.c keys.c keys2.c mouse.c utils.c

SRCO = $(SRC:.c=.o)

FRACTALSO = mandelbrot.o julia.o tricorn.o

LIB = libft/libft.a

GL = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@echo "Cleaning and Re-Making libft..."
	@make -C libft/ fclean && make -C libft/
	@echo "Compiling files with libft..."
	@clang -Wall -Werror -Wextra -c $(SRC) $(FRACTALS) -I libft/includes 
	@echo "Linking graphics library to all files..."
	@clang $(GL) $(SRCO) $(FRACTALSO) $(LIB) -I$(HEADER) main.c -o $(NAME) 

all: $(NAME)

clean:
	@echo "Removing object files"
	@/bin/rm -rf $(SRCO) $(FRACTALSO) 
	@make -C libft clean

fclean: clean
	@echo "Removing dependencies with make"
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
	@echo "Remaking :D"

.PHONY: clean fclean 
