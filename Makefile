# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 11:42:32 by akunegel          #+#    #+#              #
#    Updated: 2024/10/30 12:11:44 by akunegel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3d

MLXREP	=	./library/mlx
MLX		=	-L./$(MLXREP) -lmlx -L/usr/lib -I$(MLXREP) -lXext -lX11 -lm -lz
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror library/mlx/libmlx.a library/mlx/libmlx_Linux.a -Ilibrary -I./ -I./$(MLXREP) -I/usr/include -O3
RM		=	rm -rf
SRC		=	srcs/parsing/* srcs/utils/* srcs/main.c includes/gnl/*.c srcs/raycasting/*.c

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean re

all: $(NAME)

$(NAME):
	@printf "$(CURSIVE)$(GRAY) - Compiling $(NAME)... $(RESET)\n"
	@make -C library/mlx
	@$(CC) $(SRC) -o $(NAME) $(MLX)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

clean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

fclean:
	@$(RM) $(NAME)
	@make clean -C library/mlx
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: clean all
