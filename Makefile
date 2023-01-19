# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 00:20:18 by dcorenti          #+#    #+#              #
#    Updated: 2023/01/19 22:51:28 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = cub3D

SRCS = 	main.c \
		utils/create_map.c \
		utils/exit.c \
		utils/free_data.c \
		utils/ft_error.c \
		utils/init.c \
		utils/is_empty_line.c \
		utils/malloc_all.c \
		utils/trim_space.c \
		utils/file_exist.c \
		executor/charge_textures.c \
		executor/draw.c \
		executor/event.c \
		executor/exec.c \
		executor/minilibx_init.c \
		executor/move.c \
		executor/raycast.c \
		executor/run.c \
		executor/utils.c \
		executor/get_tex_pixl.c \
		executor/wall_tex.c \
		parsing/add_color_in_data.c \
		parsing/check_argument.c \
		parsing/check_dup_alloc.c \
		parsing/ft_split_cub.c \
		parsing/load_file_content.c \
		parsing/parse_path_and_colors.c \
		parsing/parsing.c \
		parsing/check_line_map.c \
		parsing/size_of_map.c \
		parsing/malloc_map.c \
		parsing/map_to_int.c \
		parsing/check_map.c \
		parsing/search_player_start.c \

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
