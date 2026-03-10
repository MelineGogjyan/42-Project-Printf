# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: you                                           +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

AR      = ar rcs
RM      = rm -f

SRCS    = print_char.c \
		  print_string.c \
		  print_number.c \
		  print_hex.c \
		  print_pointer.c \
		  print_unsigned.c \
		  ft_printf.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
