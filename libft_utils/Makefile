# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttremel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 11:52:19 by soviet            #+#    #+#              #
#    Updated: 2025/03/03 14:18:51 by soviet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
GNL		=	./get_next_line
PRINTF	=	./printf
DCL 	=	./double_chained_list
CL 		=	./chained_list

SRCS		=	ft_atoi.c									\
				ft_atol.c									\
				ft_atoll.c									\
				ft_calloc.c									\
				ft_isalnum.c								\
				ft_isalpha.c								\
				ft_isascii.c								\
				ft_isdigit.c								\
				ft_isprint.c								\
				ft_memcpy.c									\
				ft_strdup.c									\
				ft_strlen.c									\
				ft_memmove.c								\
				ft_memset.c									\
				ft_bzero.c									\
				ft_strlcpy.c								\
				ft_strlcat.c								\
				ft_tolower.c								\
				ft_toupper.c								\
				ft_strchr.c									\
				ft_strrchr.c								\
				ft_strncmp.c								\
				ft_strnstr.c								\
				ft_memchr.c									\
				ft_memcmp.c									\
				ft_itoa.c									\
				ft_putchar_fd.c								\
				ft_putstr_fd.c								\
				ft_putendl_fd.c								\
				ft_putnbr_fd.c								\
				ft_strjoin.c								\
				ft_split.c									\
				ft_strtrim.c								\
				ft_strmapi.c								\
				ft_striteri.c								\
				ft_substr.c									\
				ft_join.c									\
				ft_strcat.c									\
				ft_strndup.c								\
				ft_memdup.c									\
				ft_abs.c									\
				ft_strcmp.c									\
				$(PRINTF)/ft_args.c							\
				$(PRINTF)/ft_printf.c						\
				$(PRINTF)/ft_num_count.c					\
				$(PRINTF)/ft_putaddress_fd.c				\
				$(PRINTF)/ft_putbaseuint_fd.c				\
				$(PRINTF)/ft_putuint_fd.c					\
				$(PRINTF)/ft_sizeaddress.c					\
				$(PRINTF)/ft_strlenf.c						\
				$(PRINTF)/ft_ubase_count.c					\
				$(PRINTF)/ft_uint_count.c					\
				$(GNL)/get_next_line.c						\
				$(GNL)/get_next_line_utils.c

ifeq ($(DEBUG), yes)
	CFLAGS	=	-Wall -Wextra -Werror -g -fPIE
else
	CFLAGS	=	-Wall -Wextra -Werror -g -fPIE
endif
OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))

all: $(NAME) gnl printf double_chained_list chained_list
	@(echo "All lib done !")

$(NAME): $(OBJS)
	@(ar -rc $(NAME) $(OBJS))
	@(echo "libft done !")
	
gnl:
	@(cd $(GNL) && $(MAKE))
	@(echo "get_next_line done !")

double_chained_list:
	@(cd $(DCL) && $(MAKE))
	@(echo "double_chained_list done !")

chained_list:
	@(cd $(CL) && $(MAKE))
	@(echo "chained_list done !")

printf:
	@(cd $(PRINTF) && $(MAKE))
	@(echo "printf done !")

clean:
	@(rm -f $(OBJS))
	@(cd $(PRINTF) && $(MAKE) clean)
	@(cd $(GNL) && $(MAKE) clean)
	@(echo "Object files successfuly removed !")

fclean: clean
	@(rm -f $(NAME))
	@(cd $(PRINTF) && $(MAKE) fclean)
	@(cd $(GNL) && $(MAKE) fclean)
	@(echo "Lib files successfuly removed!")

re: fclean all

.PHONY: gnl printf double_chained_list chained_list all bonus clean fclean re
