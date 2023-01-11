# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 00:20:18 by dcorenti          #+#    #+#              #
#    Updated: 2023/01/11 16:33:12 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = cube3D

SRCS = 	main.c \
		init/init.c \
		init/create_map.c \
		executor/exec.c \
		executor/minilibx_init.c \
		executor/utils.c \
		executor/raycast.c \
		executor/draw.c \
		executor/event.c \
		executor/run.c \
		executor/move.c \

CC = gcc

FLAGS = -Wall -Wextra -Werror -l mlx -framework OpenGL -framework Appkit

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS)-o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
