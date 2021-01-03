# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 15:41:38 by user42            #+#    #+#              #
#    Updated: 2021/01/03 15:19:59 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = 		srcs/main.c \
			srcs/handlers.c \
			srcs/utils.c \
			srcs/colors.c \
			srcs/events.c \
			srcs/player.c \
			srcs/load.c \
			srcs/sprites.c \
			srcs/sprites2.c \
			srcs/walls.c \
			srcs/walls2.c \
			srcs/rotation.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/parse.c \
			srcs/bmp.c \
			srcs/parsing_utils.c \
			srcs/parse_textures.c \
			srcs/parse_sprites.c \
			srcs/parse_res.c \
			srcs/parse_colors.c \
			srcs/map_format.c \
			srcs/map_format_utils1.c \
			srcs/map_format_utils2.c \
			srcs/free.c \
			srcs/movement.c
OBJS = ${SRCS:.c=.o}

INC_PATH = includes
INC_NAME = cub3d.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CC = clang
CFLAGS = -Wall -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer
LFLAGS = -L libft/ft_printf -l ftprintf -L minilibx -l mlx -L /usr/lib -lXext -lX11 -lm -lbsd

all		: $(NAME)

$(NAME)	: $(OBJS) $(INC)
			make -C libft/ft_printf
			make -C minilibx
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS) -I $(INC_PATH)

%.o:%.c
			$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean	:
			rm -rf $(OBJS)
			make clean -C libft/ft_printf
			make clean -C minilibx

fclean	: clean
			rm -rf $(NAME)
			make fclean -C libft/ft_printf

re		: fclean all
