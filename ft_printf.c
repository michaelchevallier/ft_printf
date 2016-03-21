/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:09:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/21 18:44:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

t_var		*var_initializer(t_var *var)
{
	var = (t_var *)ft_memalloc(sizeof(t_var));
	var->str = (char *)ft_memalloc(sizeof(char));
	var->specifier = 0;
	return (var);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_var			*var;
	int				i;
	int				j;
	int				k;

	var = NULL;
	i = 0;
	j = 0;
	k = 0;
	var = var_initializer(var);
	va_start(ap, format);
	while (format[i + k])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			i++;
			while((format[i] != SPECIFIER[j]) && format[i])
			{
					printf("i : %d, j : %d\n",i,j);
				j = 0;
				var->arg = va_arg(ap, void *);
				printf("var->specifier : \n%c\n", var->specifier);
				while (ft_strchr(&format[i], SPECIFIER[j]) == NULL && format[i])
					j++;
				if (format[i] == SPECIFIER[j])
					var->specifier = SPECIFIER[j];
				else
					var->str = ft_strjoin(var->str, ft_strsub(format, i, 1));
			i++;
			}
		}
		i++;
	}
	ft_putchar ('A');
	printf("%c\n", var->specifier);
	printf("%s\n", var->str);
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("Toto %#,34d", 42);
	return (0);
}
