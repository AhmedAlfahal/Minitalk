# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 00:43:15 by aalfahal          #+#    #+#              #
#    Updated: 2023/01/21 18:31:09 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME1	=	server
NAME2	=	client

SRC2	=	client.c
SRC1	=	server.c

SRCS2	=	$(SRC2:%.c=%.o)
SRCS1	=	$(SRC1:%.c=%.o)

all : $(NAME1) $(NAME2)

$(NAME1) $(NAME2) : $(SRCS1) $(SRCS2)
	@make -C ./ft_printf 
	@make all -C ./libft
	$(CC) $(CFLAGS) $(SRC1) -o $(NAME1) libft/libft.a ./ft_printf/*.a
	$(CC) $(CFLAGS) $(SRC2) -o $(NAME2) libft/libft.a ./ft_printf/*.a

clean:
	rm -fr $(SRCS1) $(SRCS2) ./libft/*.o ./ft_printf/*.o

fclean: clean
	rm -fr $(NAME1) $(NAME2) ./libft/*.a ./ft_printf/*.a

re: fclean all