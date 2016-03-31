/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 09:55:03 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 18:16:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_s(t_var *var)
{
	if (var->mod_len == 0)
	{
		var->arg = (char *)var->arg;
		var->spec_len = ft_strlen(var->arg);
	}
	else if (var->mod_len == 1 && var->modifier[0] == 'l')
	{
		var->mod_len = 0;
		spec_ls(var);
	}
	else
		return ((var->error = -1));
	return (0);
}

int		spec_ls(t_var *var)
{
	t_wchar				*wchar;
	wchar_t				*str;
	unsigned char		*str2;
	int					i;

	str = NULL;
	str2 = (unsigned char *)ft_memalloc(sizeof(unsigned char));
	i = 0;
	if (var->mod_len != 0)
		return ((var->error = -1));
	else
	{
		str = (wchar_t *)var->arg;
		while (i < ft_wcharlen(str))
		{
			wchar = (t_wchar *)ft_memalloc(sizeof(t_wchar));
			wchar = wstr_manager(str[i]);
			str2 = ft_ustrjoin_and_free(str2, wchartostring(wchar), 2);
			free(wchar);
			i++;
		}
		var->arg = str2;
		var->spec_len = ft_wcharlen(str);
	}
	return (0);
}

int		spec_p(t_var *var)
{
	if (var->mod_len != 0)
		return ((var->error = -1));
	{
		var->arg = ft_strjoin("0x", ft_itoa_baseuint((uintmax_t)var->arg, 16));
		var->spec_len = ft_strlen(var->arg);
	}
	return (0);
}

int		spec_d(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa((signed char)var->arg);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa((long long int)var->arg);
		else
			return ((var->error = -2));
	}
	else if (var->mod_len == 1)
	{
		if (var->modifier[0] == 'h')
			var->arg = ft_itoa((short int)var->arg);
		else if (var->modifier[0] == 'l')
			var->arg = ft_itoa_base((long int)var->arg, 10);
		else if (var->modifier[0] == 'j')
			var->arg = ft_itoa_base((intmax_t)var->arg, 10);
		else if (var->modifier[0] == 'z')
			var->arg = ft_itoa_baseuint((size_t)var->arg, 10);
		else
			return ((var->error = -3));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa((int)var->arg);
	return ((var->spec_len = ft_strlen(var->arg)));
}

int		spec_ld(t_var *var)
{
	if (var->mod_len != 0)
		return ((var->error = -1));
	else
	{
		var->arg = ft_itoa_base((long int)var->arg, 10);
		var->spec_len = ft_strlen(var->arg);
	}
	return (0);
}
