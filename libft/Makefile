# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/16 16:04:36 by vrabaib           #+#    #+#              #
#    Updated: 2019/05/07 14:40:24 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h get_next_line.h
SOURCES_C = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_lstnew.c	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_ltrcount.c ft_wrdcount.c ft_isnegative.c ft_intlen.c ft_iswhitespace.c \
ft_capitalize.c ft_strndup.c get_next_line.c ft_intnew.c

SOURCES_O = $(SOURCES_C:.c=.o)

all: $(NAME) 
	
$(NAME):
	@gcc -Wall -Werror -Wextra $(D_HEADER) -c $(SOURCES_C) 
	@ar rc $(NAME) $(SOURCES_O)
	@ranlib $(NAME)

clean:
	@rm -f $(SOURCES_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
