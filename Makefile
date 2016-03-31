# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/03/31 17:14:13 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a
SRC = ft_printf.c\
	  specifier_finder.c\
	  format_specifier_manager.c\
	  specifier_funcs.c\
	  specifier_funcs2.c\
	  specifier_funcs3.c\
	  wchar_manager.c\
	  funcs.c\
	  funcs2.c\
	  wstr_manager.c
SRCO = $(SRC:.c=.o)
##FLAG = -Wall -Werror -Wextra

all: $(NAME)


$(NAME): $(SRCO)
	make -C libft
	gcc $(FLAG) -c $(SRC)
	cp $(LIB) $(NAME)
	ar r $(NAME) $(SRCO)
	ranlib $(NAME)
	gcc $(SRC) $(NAME)
	./a.out

clean:
	make -C libft clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
