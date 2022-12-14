# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 21:38:14 by bsirikam          #+#    #+#              #
#    Updated: 2023/01/06 03:01:04 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c ft_strrchr.c ft_strncmp.c ft_strchr.c ft_printf.c \
ft_printf_util.c ft_printf_util2.c ft_gnl.c ft_get_line.c \
ft_create_map.c ft_check_line.c ft_check_ber.c ft_gnl_utils.c \
ft_check_frame.c ft_ha_p.c ft_so_long_utils.c ft_flood_fill.c \
ft_creat_real_map.c ft_render.c ft_key_hook.c ft_close.c \
ft_dern.c

# SRC_B =

OBJ = $(SRC:.c=.o)
# OBJ_B = $(SRC_B:.c=.o)
CC = gcc
CFLAGS = -g #-Wall -Werror -Wextra
HEADER = so_long.h
MLX_INC = -LMLX -lMLX -IMLX -framework OpenGL -framework AppKit

%.o: %.c $(HEADER)
	# @$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	# $(CC) $(CFLAGS) $(MLX_INC) $(OBJ) -o $(NAME)
	$(CC) $(OBJ) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

# bonus: all
# 	$(CC) $(CFLAGS) -c $(SRC_B)
# 	ar rcs $(NAME) $(OBJ_B)

leak:
	@leaks -atExit -- ./so_long map.ber

MLX_LIB:
	@make -C ./MLX

norm:
	@norminette -R CheckForbiddenHeaderSource $(SRC)
	@norminette -R CheckDefine *.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
