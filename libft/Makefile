# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 14:56:41 by jrobin-h          #+#    #+#              #
#    Updated: 2019/09/18 22:00:05 by jrobin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS =	$(shell cat ./includes/libft.h | grep -Eo "ft_\w+")

SRCS = $(FUNCS:=.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = ./includes/

HEADS = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): %.o : %.c $(addprefix $(INCLUDES), $(HEADS))
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

obj: $(OBJS)
