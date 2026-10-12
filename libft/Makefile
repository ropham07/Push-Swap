# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamenego <mamenego@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 13:11:20 by mgoguely          #+#    #+#              #
#    Updated: 2026/06/11 19:03:07 by mamenego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf


SRCS		= ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
		  ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
		  ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
		  ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c \
		  ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c \
		  ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c \
		  ft_strrchr.c ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
		  ft_isspace.c ft_strcmp.c \
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c \

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus