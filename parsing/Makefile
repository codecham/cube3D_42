# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 00:20:18 by dcorenti          #+#    #+#              #
#    Updated: 2023/01/16 20:37:53 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ../libft/libft.a
LIBFT_DIR = ../libft

NAME =  parsing

SRCS = 	main.c \
		../utils/init.c \
		../utils/malloc_all.c \
		../utils/ft_error.c \
		../utils/exit.c \
		../utils/free_data.c \
		check_argument.c \
		check_map.c \
		parsing.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re : fclean all
