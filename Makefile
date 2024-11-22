# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retahri <retahri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 02:05:13 by retahri           #+#    #+#              #
#    Updated: 2024/11/21 09:53:09 by retahri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c ft_utils.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rsc $(NAME) $(OBJECTS)

clean: 
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean