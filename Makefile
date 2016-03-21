# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/03/21 18:40:31 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a
SRC = ft_printf.c
SRCO = $(SRC:.c=.o)
LIBSRCO = libft/*.o
FLAG = -Wall -Werror -Wextra

all: $(NAME)


$(NAME): $(SRCO)
	make -C libft
	cp $(LIB) $(addprefix ../,$(NAME))
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
