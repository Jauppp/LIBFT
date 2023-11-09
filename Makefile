# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 10:23:52 by cdomet-d          #+#    #+#              #
#    Updated: 2023/11/08 17:32:26 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRCS := ft_isalpha.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_isprint.c \
		ft_memset.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_atoi.c
OBJS := $(SRCS:%.c=%.o)
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS) libft.h
	ar -rcs $(NAME) $(OBJS)

%.o:%.c 
	$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re : fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY : clean fclean all re so 