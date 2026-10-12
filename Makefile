# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 15:01:15 by mamenego          #+#    #+#              #
#    Updated: 2026/06/12 17:59:24 by robinpham        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I. -Ilibft -Ift_printf

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRCS		= main.c \
			  parsing/parseflag.c \
			  parsing/parsingarg.c \
			  strategies/choose.c \
			  strategies/compute_disorder.c \
			  operations/opp.c \
			  operations/rotate.c \
			  operations/rotate2.c \
			  utils/utils.c \
			  algo/sort_simple.c \
			  algo/sort_medium.c \
			  algo/sort_complex.c \
			  algo/sort_case.c 

TEST_SRCS	= main_test.c \
			  parsing/parseflag.c \
			  parsing/parsingarg.c \
			  strategies/choose.c \
			  strategies/compute_disorder.c \
			  operations/opp.c \
			  operations/rotate.c \
			  operations/rotate2.c \
			  utils/utils.c \
			  algo/sort_simple.c \
			  algo/sort_medium.c \
			  algo/sort_complex.c \
			  algo/sort_case.c 

OBJS		= $(SRCS:.c=.o)
TEST_OBJS	= $(TEST_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

test: $(LIBFT) $(PRINTF) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFT) $(PRINTF) -o test_push_swap
	./test_push_swap

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME) test_push_swap
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re test