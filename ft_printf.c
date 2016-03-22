/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:09:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/22 18:38:29 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		var_initializer(t_var *var)
{
	var->arg = NULL;
	var->counter = 0;
	var->str = (char *)ft_memalloc(sizeof(char));
	var->specifier = -1;
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_var			*var;
	int				i;

	i = 0;
	var = (t_var *)ft_memalloc(sizeof(t_var));
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			var->counter += 1;
		}
		else
		{
			i = specifier_finder(format, var, i, ap);
		}
		i++;
	}
	printf("\nspec:%d\n", var->specifier);
	printf("arg:%d\n", (int)var->arg);
	printf("str:%s\n", var->str);
	va_end(ap);
	return (0);
}

int main(void)
{
	//printf("%00d\n", 42);
	ft_printf("Toto \n%d,345\n tata\nh%s", 42,32);
	return (0);
}


