/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:37:15 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/24 19:55:45 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# define NB_FLAGS 5
# define FS format_specifier
# define FLAGS "#0 +-"
# define MODIFIER "hljz"
# define SPECIFIER "sSpdDioOuUxXcC%"
//% [drapeaux] [largeur] [.precision] [modificateur] type
typedef struct			s_var
{
	void	*arg;
	char	*str;
	char	*format_specifier;
	char	*modifier;
	char	*tmp;
	int		*flags;
	int		counter;
	int		specifier;
	int		width;
	int		error;
	int		precision;
}						t_var;

int		ft_printf(const char *format, ...);
int		specifier_finder(const char *format, t_var *var, int i, va_list ap);
void	format_specifier_manager(t_var *var);
void	var_initializer(t_var *var);

#endif
