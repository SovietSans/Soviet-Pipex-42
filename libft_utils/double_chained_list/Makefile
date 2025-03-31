# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttremel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 16:55:58 by soviet            #+#    #+#              #
#    Updated: 2025/03/03 14:19:34 by soviet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	double_chained_list.a
CC		=	cc
LIB		=	../libft.a

SRCS	=	ft_lstadd_back.c			\
			ft_lstadd_front.c			\
			ft_lstclear.c				\
			ft_lstdelone.c				\
			ft_lstiter.c				\
			ft_lstlast.c				\
			ft_lstmap.c					\
			ft_lstnew.c					\
			ft_lstsize.c

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
