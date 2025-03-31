# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttremel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 13:35:36 by soviet            #+#    #+#              #
#    Updated: 2025/03/03 14:19:11 by soviet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a
CC		=	cc
LIB		=	../libft.a

SRCS	=	get_next_line.c			\
			get_next_line_utils.c

ifeq ($(DEBUG), yes)
	CFLAGS	=	-Wall -Wextra -Werror -g -fPIE
else
	CFLAGS	=	-Wall -Wextra -Werror -g -fPIE
endif
OBJS	=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
