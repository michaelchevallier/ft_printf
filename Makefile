# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/04/13 15:04:39 by mchevall         ###   ########.fr        #
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
	  specifier_funcs4.c\
	  specifier_funcs5.c\
	  wchar_manager.c\
	  funcs.c\
	  funcs2.c\
	  wstr_manager.c\
	  precision_manager.c\
	  flag_manager.c\
	  width_manager.c
SRCO = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra

all: $(NAME)


$(NAME): $(SRCO)
	make -C libft
	gcc $(FLAG) -c $(SRC)
	cp $(LIB) $(NAME)
	ar r $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
