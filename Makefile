# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2018/05/21 19:02:53 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = 	main.c \
		key_hook.c \
		init.c \
		move.c \
		draw.c \
		color.c \
		mouse.c \
		mandelbrot.c \
		julia.c \
		heart.c \

OBJ = $(SRCS:.c=.o)

CC = gcc -g -Wall -Werror -Wextra

HEADERS = fractol.h \
		libft/libft.h \

LIBS = libft/libft.a

FLAGS = -lmlx -framework OpenGL -framework AppKit -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(FLAGS)
	@echo "\033[31mFractol \033[33mMAKED\033[0m"

$(OBJ): $(SRCS) $(HEADERS)
	make -C libft
	$(CC) -c $(SRCS) -I $(HEADERS)

clean:
	rm -f $(OBJ)
	make clean -C libft
	@echo "\033[33mCLEANED\033[0m"

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	@echo "\033[33mCLEANED ALL\033[0m"

re: fclean all

.PHONY: all clean fclean re