/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:08:00 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 18:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				spec_x(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_baseuint((unsigned char)var->arg, 16);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_baseuint((unsigned long long int)var->arg, 16);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (var->modifier[0] == 'h')
			var->arg = ft_itoa_baseuint((unsigned short int)var->arg, 16);
		else if (var->modifier[0] == 'l')
			var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 16);
		else if (var->modifier[0] == 'j')
			var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 16);
		else if (var->modifier[0] == 'z')
			var->arg = ft_itoa_baseuint((size_t)var->arg, 16);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 16);
	return ((var->spec_len = ft_strlen(var->arg)));
}

int				spec_lx(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_baseuint((unsigned char)var->arg, 16);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_baseuint((unsigned long long int)var->arg, 16);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (var->modifier[0] == 'h')
			var->arg = ft_itoa_baseuint((unsigned short int)var->arg, 16);
		else if (var->modifier[0] == 'l')
			var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 16);
		else if (var->modifier[0] == 'j')
			var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 16);
		else if (var->modifier[0] == 'z')
			var->arg = ft_itoa_baseuint((size_t)var->arg, 16);
	}
	else if (var->mod_len == 0 && var->error != -1)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 16);
	var->arg = ft_stringupper(var->arg);
	return ((var->spec_len = ft_strlen(var->arg)));
}

int				spec_c(t_var *var)
{
	t_wchar		*wchar;

	wchar = NULL;
	if (var->mod_len == 0)
		var->arg = (char *)chartostring((int)var->arg);
	else if (var->mod_len == 1 && var->modifier[0] == 'l')
	{
		wchar = wchar_manager(var);
		var->arg = wchartostring(wchar);
	}
	else
		return ((var->error = -1));
	var->spec_len = 1;
	return (0);
}

int				spec_lc(t_var *var)
{
	t_wchar		*wchar;

	wchar = NULL;
	if (var->mod_len != 0)
		return ((var->error = -1));
	else
	{
		wchar = wchar_manager(var);
		var->arg = wchartostring(wchar);
		var->spec_len = 1;
	}
	return (0);
}
