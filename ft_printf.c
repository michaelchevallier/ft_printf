/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:09:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 18:17:06 by mchevall         ###   ########.fr       */
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
	var->mod_len = 0;
	var->spec_len = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_var			*var;
	int				i;

	i = 0;
	var = (t_var *)ft_memalloc(sizeof(t_var));
	var->str = (unsigned char *)ft_memalloc(sizeof(unsigned char));
	var->error = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			var->str = ft_ustrjoin_and_free(var->str, ft_strsub(format, i, 1), 0);
		else
		{
			if (format[i + 1] == '%')
			{
				var->str = ft_ustrjoin_and_free(var->str, ft_strsub(format, i + 1, 1), 2);
				i += 2;
			}
			else
			{
				i = specifier_finder(format, var, i, ap);
				format_specifier_manager(var);
				if (var->specifier == 0)
					spec_s(var);
				if (var->specifier == 1)
					spec_ls(var);
				if (var->specifier == 2)
					spec_p(var);
				if (var->specifier == 3)
					spec_d(var);
				if (var->specifier == 4)
					spec_ld(var);
				if (var->specifier == 5)
					spec_i(var);
				if (var->specifier == 6)
					spec_o(var);
				if (var->specifier == 7)
					spec_lo(var);
				if (var->specifier == 8)
					spec_u(var);
				if (var->specifier == 9)
					spec_lu(var);
				if (var->specifier == 10)
					spec_x(var);
				if (var->specifier == 11)
					spec_lx(var);
				if (var->specifier == 12)
					spec_c(var);
				if (var->specifier == 13)
					spec_lc(var);
				if (var->specifier == -1)
					var->error = -1;
				if (var->error == 0)
						var->str = ft_ustrjoin_and_free(var->str, var->arg, 1);
			}
		}
		i++;
	}
	int j = 0;
	printf("\nsc:%c\n", SPECIFIER[var->specifier]);
	printf("\nsc:%d\n", var->specifier);
	printf("arg:%S\n", (wchar_t *)var->arg);
	printf("fspe:%s\n", var->format_specifier);
	printf("pre str:%s\n", var->str);
	printf("flags: #:%d 0:%d ' ':%d +:%d -:%d\n", var->flags[0],var->flags[1],var->flags[2],var->flags[3],var->flags[4]);
	printf("width: %d\n", var->width);
	printf("error: %d\n", var->error);
	printf("precision: %d\n", var->precision);
	printf("modifier: %s\n", var->modifier);
	printf("mod_len: %d\n", var->mod_len);
	printf("spec_len: %d\n", var->spec_len);
	ft_putstr("\nreal str :");
	if (var->error == 0)
		while (var->str[j])
		{
			ft_putchar(var->str[j]);
			j++;
		}
	va_end(ap);
	return (var->error);
}

int 		main(void)
{
//	wchar_t bob = L'α';
//	wchar_t joe = L'Ω';

	setlocale(LC_CTYPE, "");
//	if (joe == 1)
//		return(0);
	//printf("Original\n s: %s hello p: %p d: %d D: %D i:%i o:%o\n O:%O\n u:%u U: %U x:%x X:%X c:%c C:%C\n", "bob", "Johnny", 42, 16, 255, 16, 17, 233, 245, 255, 255, 0, 'B');
	//ft_printf("\ns: %s S: %S hello p: %p d: %d D: %D i:%i o:%o O:%O u:%u U: %U x:%x X:%X c:%c C:%C\ni %% %d", "bob", "JOEY", "Johnny", 42, 16, 255, 16, 17, 233, 245, 255, 255, 96, 'B', 42);
	wprintf(L"real printf:hello: %ls\n", L"αΩ");
	ft_printf(" Toto %ls\n\n", L"αΩ");
	return (0);
}
