#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kberisha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 17:42:33 by kberisha          #+#    #+#              #
#    Updated: 2017/12/18 11:54:44 by kberisha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC_DIR = libft/libft.a

SRCS_LIST = fillit.c \
			main.c \
			init_struct.c \
			list.c \
			parse.c \
			resolve.c \
			tetrimino.c

LIB = ./libft/libft.a

CLIB = ./libft/

OBJS = $(SRCS_LIST:.c=.o)

all: $(NAME)

$(NAME): fillit.h Makefile $(OBJS)
	@make  -C $(CLIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(INC_DIR) -o $(NAME)

clean:
	make -C $(CLIB) clean
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
