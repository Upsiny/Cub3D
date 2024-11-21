# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 11:42:32 by akunegel          #+#    #+#              #
#    Updated: 2024/11/21 13:09:28 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

MLXREP	=	./library/mlx
MLX		=	-L./$(MLXREP) -lmlx -L/usr/lib -I$(MLXREP) -lXext -lX11 -lm -lz
CC		=	gcc $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror library/mlx/libmlx.a library/mlx/libmlx_Linux.a -Ilibrary -I./ -I./$(MLXREP) -I/usr/include -O3 -g -fsanitize=address
RM		=	rm -rf
SRC		=	srcs/parsing/check_map.c srcs/parsing/check_rgb.c srcs/parsing/get_file.c srcs/parsing/get_map.c srcs/parsing/get_paths.c srcs/parsing/get_t_paths.c srcs/parsing/parsing.c srcs/parsing/paths_checks.c \
			srcs/utils/ft_exit.c srcs/utils/ft_split.c srcs/utils/utils.c srcs/utils/utils2.c \
			srcs/main.c \
			includes/gnl/get_next_line.c includes/gnl/get_next_line_utils.c \
			srcs/raycasting/camera.c  srcs/raycasting/raycasting2.c srcs/raycasting/game.c srcs/raycasting/raycasting.c srcs/raycasting/mlx.c srcs/raycasting/textures.c srcs/raycasting/move.c

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
