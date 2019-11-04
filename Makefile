# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin-h <jrobin-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 18:15:37 by jrobin-h          #+#    #+#              #
#    Updated: 2019/09/18 21:50:21 by jrobin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3

SRCS = args_cmp_files_first.c \
    args_comparisons.c \
    args_comparisons_reversed.c \
    comparisons.c \
    comparisons_reversed.c \
    del_memory.c \
    new_bbox.c \
	ft_error.c \
	ft_ls.c \
	ft_strdup_custom.c \
	get_files.c \
	get_path.c \
	main.c \
	output.c \
	parse.c \
	memory_funcs_print.c \
	print_in_columns.c \
	print_rows.c \
	process_args.c \
	send_files_to_output.c \
	fill_l_params1.c \
	fill_l_params2.c \
	fill_l_params3.c \
	ft_slice.c

OBJS = $(SRCS:.c=.o)

HEADS = ft_ls.h ft_ls_print.h

SRCS_DIR = ./srcs/
BUILD_DIR = ./build/
INCL_DIR = ./includes/

vpath %.c $(SRCS_DIR)
vpath %.o $(BUILD_DIR)

all: check_build_dir $(NAME)

.PHONY: check_build_dir
check_build_dir:
	@if [ ! -d $(BUILD_DIR) ] ; then \
	mkdir $(BUILD_DIR); \
	fi

$(NAME): ./libft/libft.a $(OBJS)
	$(CC) $(addprefix $(BUILD_DIR), $(OBJS)) -L./libft -lft -o $(NAME)

$(OBJS): %.o : %.c $(addprefix $(INCL_DIR), $(HEADS))
	$(CC) $(CFLAGS) -c -I$(INCL_DIR) -I./libft/includes $< -o $(BUILD_DIR)$@

.PHONY: build_lib
build_lib:
	make -C ./libft

./libft/libft.a: build_lib

clean:
	rm -rf $(addprefix $(BUILD_DIR), $(OBJS))
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
