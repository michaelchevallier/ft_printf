/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:20:28 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 14:01:18 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			specifier_finder(const char *format, t_var *var, int i, va_list ap)
{
	size_t				j;
	size_t				k;

	j = 0;
	k = 0;
	var_initializer(var);
	while ((format[i + j] != SPECIFIER[k]) && format[i])
	{
		var->arg = va_arg(ap, void *);
		while (format[i + j] != SPECIFIER[k] &&
				format[i] && var->specifier == -1)
		{
			k = 0;
			j++;
			while (format[i + j] != SPECIFIER[k] && SPECIFIER[k])
				k++;
			if (SPECIFIER[k] == format[i + j] && k < ft_strlen(SPECIFIER))
				var->specifier = k;
			if (k == ft_strlen(SPECIFIER))
				var->format_specifier = ft_strjoin_and_free
(var->format_specifier, ft_strsub(format, i + j, 1), 0);
		}
	}
	i = i + j;
	return (i);
}
