# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 08:57:37 by aaslan            #+#    #+#              #
#    Updated: 2023/02/13 06:03:24 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
LFLAGS		:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX			:= mlx_linux/libmlx.a
SRC			:= $(wildcard src/*.c)
UTILS		:= $(wildcard src/utilities/*.c)
VALIDATORS	:= $(wildcard src/map_validators/*.c)
ANIMATIONS	:= $(wildcard src/animations/*.c)
HANDLERS	:= $(wildcard src/handlers/*.c)
HELPERS		:= $(wildcard src/mlx_helpers/*.c)
OBJS		:= $(SRC:%.c=%.o) $(UTILS:%.c=%.o) $(VALIDATORS:%.c=%.o) $(ANIMATIONS:%.c=%.o) $(HANDLERS:%.c=%.o) $(HELPERS:%.c=%.o)


all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) $(MLX) -o $(NAME)

$(MLX):
	@make -C mlx_linux
	@clear

clean:
	@rm -rf $(OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@make clean -C mlx_linux
	@clear

re: fclean all

norm:
	@norminette src/so_long.h src/*.c src/utilities/*.c src/map_validators/*.c src/animations/*.c src/handlers/*.c src/mlx_helpers/*.c

.PHONY: all clean fclean re
