# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2020/02/11 20:45:27 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS = algo_/ft_bfs.c \
       	algo_/ft_fun_free.c\
	   	algo_/ft_get_best_g.c \
	   	algo_/get_group_.c\
	   	algo_/ft_index_path.c \
	   	algo_/ft_free.c\
		read_file/ft_adj_list.c \
		read_file/sort_rooms.c \
		read_file/check_data.c \
		read_file/parser.c \
		read_file/stock_func.c \
		print_/print_instructoin.c \
		print_/ft_get_nbr_path.c \
		print_/ft_mangement.c \
		main.c \

OBJCS = algo_/ft_bfs.o \
       	algo_/ft_fun_free.o\
	   	algo_/ft_get_best_g.o \
	   	algo_/get_group_.o\
	   	algo_/ft_index_path.o \
	   	algo_/ft_free.o\
		read_file/ft_adj_list.o \
		read_file/sort_rooms.o \
		read_file/check_data.o \
		read_file/parser.o \
		read_file/stock_func.o \
		print_/print_instructoin.o \
		print_/ft_get_nbr_path.o \
		print_/ft_mangement.o \
		main.o \

INCLUDES = ./include
LIBFT = libft/libft.a
CFLAGS = -g -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJCS) $(LIBFT) $(INCLUDES)/lem_in.h
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"
	@echo "\033[0;32m| >>>>>>>>>>>>>>>>>>>>>>>>>> Compiled Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
	@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(OBJCS)
	@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
	@echo "\033[1;33m| >>>>>>>>>>>>>>>>>>>>>>>>>>  Cleaned Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
	@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all


