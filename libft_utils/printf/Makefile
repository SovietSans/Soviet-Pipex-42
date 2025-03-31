# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttremel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 09:59:39 by soviet            #+#    #+#              #
#    Updated: 2024/12/17 12:25:41 by soviet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
LIB		=	../libft.a

SRCS	=	ft_printf.c			\
			ft_strlenf.c		\
			ft_num_count.c		\
			ft_args.c			\
			ft_putuint_fd.c		\
			ft_uint_count.c		\
			ft_putbaseuint_fd.c	\
			ft_ubase_count.c	\
			ft_sizeaddress.c	\
			ft_putaddress_fd.c	

ifeq ($(DEBUG), yes)
	CFLAGS	=	-Wall -Wextra -Werror -g
else
	CFLAGS	=	-Wall -Wextra -Werror -g
endif
OBJS	=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS) $(LIB)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
