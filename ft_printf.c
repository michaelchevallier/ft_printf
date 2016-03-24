/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:09:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/24 19:52:30 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		var_initializer(t_var *var)
{
	var->arg = NULL;
	var->counter = 0;
	var->tmp = NULL;
	if (var->format_specifier)
		free(var->format_specifier);
	var->format_specifier = (char *)ft_memalloc(sizeof(char));
	var->specifier = -1;
	if (var->modifier)
		free(var->modifier);
	var->modifier = (char *)ft_memalloc(sizeof(char));
	if (var->flags)
		free(var->flags);
	var->flags = (int *)ft_memalloc(sizeof(int) * NB_FLAGS + 1);
	var->flags[NB_FLAGS] = -1;
	var->width = -1;
	var->precision = -1;
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_var			*var;
	int				i;

	i = 0;
	var = (t_var *)ft_memalloc(sizeof(t_var));
	var->str = (char *)ft_memalloc(sizeof(char));
	var->error = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			var->tmp = var->str;
			var->str = ft_strjoin(var->str, ft_strsub(format, i, 1));
			free(var->tmp);
		}
		else
		{
			i = specifier_finder(format, var, i, ap);
			format_specifier_manager(var);
		}
		i++;
	}
	printf("\nspec:%c\n", SPECIFIER[var->specifier]);
	printf("arg:%d\n", (int)var->arg);
	printf("fspe:%s\n", var->format_specifier);
	printf("str:%s\n", var->str);
	printf("flags: #:%d 0:%d ' ':%d +:%d -:%d\n", var->flags[0],var->flags[1],var->flags[2],var->flags[3],var->flags[4]);
	printf("width: %d\n", var->width);
	printf("error: %d\n", var->error);
	printf("precision: %d\n", var->precision);
	printf("modifier: %s\n", var->modifier);
	va_end(ap);
	return (var->error);
}

int 		main(void)
{
	//printf("%d\n",ft_atoi(""));
	printf("%3.9zd\n", 42);
	ft_printf("Toto \n%0+-#3.9lhd tata", 42);
	return (0);
}
