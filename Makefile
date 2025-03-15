# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttremel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 16:08:13 by ttremel           #+#    #+#              #
#    Updated: 2025/03/06 16:01:28 by ttremel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CC				=	cc
LIBFT			=	./libft_utils
export DEBUG	=	yes

SRCS	=	./parsing.c			\
			./free.c			\
			./ft_exec.c			\
			./error.c			\
			./ft_wait.c			\
			./process.c

MANDATORY_SRCS	=	./mandatory/main.c

BONUS_SRCS		=	./bonus/main_bonus.c

ifeq ($(DEBUG), yes)
	CFLAGS	=	-Wall -Wextra -Werror -g
else
	CFLAGS	=	-Wall -Wextra -Werror
endif

OBJS			=	$(SRCS:.c=.o)
MANDATORY_OBJS	=	$(MANDATORY_SRCS:.c=.o)
BONUS_OBJS		=	$(BONUS_SRCS:.c=.o)

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))

all:	$(NAME)

bonus:	$(OBJS) $(BONUS_OBJS) libft
	@($(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BONUS_OBJS) ./libft_utils/libft.a)
	@(echo "Bonus Executable $(NAME) done !")

libft:
	@(cd $(LIBFT) && $(MAKE))

$(NAME):	$(OBJS) $(MANDATORY_OBJS) libft
	@($(CC) $(CFLAGS) -o $@ $(OBJS) $(MANDATORY_OBJS) ./libft_utils/libft.a)
	@(echo "Executable $(NAME) done !")

clean:
	@(rm -f $(OBJS))
	@(cd $(LIBFT) && $(MAKE) clean)

fclean:	clean
	@(rm -f $(NAME))
	@(cd $(LIBFT) && $(MAKE) fclean)

re:	fclean all

.PHONY: all bonus clean fclean re