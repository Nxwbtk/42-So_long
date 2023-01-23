# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 21:38:14 by bsirikam          #+#    #+#              #
#    Updated: 2023/01/23 23:04:39 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c ft_strrchr.c ft_strncmp.c ft_strchr.c ft_printf.c \
ft_printf_util.c ft_printf_util2.c ft_gnl.c ft_get_line.c \
ft_create_map.c ft_check_line.c ft_check_ber.c ft_gnl_utils.c \
ft_check_frame.c ft_ha_p.c ft_so_long_utils.c ft_flood_fill.c \
ft_creat_real_map.c ft_render.c ft_key_hook.c ft_close.c \
ft_dern.c ft_help_key_hook.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = #-g -Wall -Werror -Wextra
HEADER = so_long.h
MLX_INC = -LMLX -lMLX  -framework OpenGL -framework AppKit
# MLX_DIR = ./MLX
MLX_DIR = ./mlx_Linux

%.o: %.c $(HEADER)
# @$(CC) $(CFLAGS) -IMLX -c $< -o $@
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: MLX_LIB $(NAME)

$(NAME): $(OBJ)
# @$(CC) $(OBJ) -o $(NAME) $(MLX_INC)
	$(CC) $(OBJ) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)


leak:
	@leaks -atExit -- ./so_long map.ber

MLX_LIB:
	@make -C $(MLX_DIR) 2> /dev/null

norm:
	@norminette -R CheckForbiddenHeaderSource $(SRC)
	@norminette -R CheckDefine *.h

clean:
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
