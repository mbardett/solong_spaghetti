# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 22:15:59 by mbardett          #+#    #+#              #
#    Updated: 2022/09/18 16:51:42 by mbardett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -framework OpenGL -framework AppKit -lmlx
LIB = ./include/lib.h
NAME = so_long

SRCS = ./src/coll.c \
		./src/enemy.c \
		./src/floor_n_walls.c \
		./src/door.c \
		./src/walls.c \
		./src/ft_itoa.c \
		./src/ft_utils.c \
		./src/gnl.c\
		./src/gnl_so_long.c \
		./src/inputs.c \
		./src/map_checks.c \
		./src/map_data.c \
		./src/movement.c \
		./src/player.c \
		./src/draw.c \
		./src/game_init.c \
		./src/enemy_movement.c \
		./src/list_management.c \
		./src/ft_enemy_utils.c \
		main.c

OBJS = $(SRCS:.c=.o)

%.o: %.c.
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@echo Good Hunt

all: $(NAME)
	@echo Game Start

play: all
		./$(NAME) ./map/map.ber

clean:
	$(RM) $(OBJS)
	@echo Objects destroyed.

fclean: clean
	$(RM) $(NAME)
	@echo So_long cleared.

re: fclean
	@make all

.PHONY: all clean fclean re
