# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 21:38:14 by bsirikam          #+#    #+#              #
#    Updated: 2022/12/24 21:41:38 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c ft_strrchr.c ft_strncmp.c ft_strchr.c ft_printf.c \
ft_printf_util.c ft_printf_util2.c ft_gnl.c ft_get_line.c \
ft_create_map.c ft_check_line.c ft_check_ber.c ft_gnl_utils.c \
ft_check_frame.c ft_ha_p.c ft_so_long_utils.c ft_flood_fill.c \
ft_creat_real_map.c

# SRC_B =

OBJ = $(SRC:.c=.o)
# OBJ_B = $(SRC_B:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = so_long.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

# bonus: all
# 	$(CC) $(CFLAGS) -c $(SRC_B)
# 	ar rcs $(NAME) $(OBJ_B)

norm:
	@norminette -R CheckForbiddenHeaderSource $(SRC)
	@norminette -R CheckDefine *.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
