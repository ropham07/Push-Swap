# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/10 21:24:30 by robinpham         #+#    #+#              #
#    Updated: 2026/05/10 21:30:50 by robinpham        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs
RM				= rm -rf


SRCS			= ft_printf.c ft_putchar.c ft_puthex_long.c ft_puthex.c \
				ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunint.c \

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR)	$(NAME)	$(OBJS)

clean:
		$(RM)	$(OBJS)

fclean: clean
		$(RM)	$(NAME)

re: fclean all

.PHONY: all clean fclean re