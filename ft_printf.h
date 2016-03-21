/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:37:15 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/21 17:28:17 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# define SPECIFIER "sSpdDioOuUxXcC%"
# define SIZE 1000000
# define FLAGS "#0-+ "

typedef struct			s_var
{
	void	*arg;
	char	specifier;
	char	*str;
}						t_var;
int				ft_printf(const char *format, ...);

#endif
