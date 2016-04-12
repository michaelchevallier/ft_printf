/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:58:30 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/11 15:49:00 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_i(t_var *var)
{
	spec_d(var);
	return (0);
}

int		spec_o(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_baseuint((unsigned char)var->arg, 8);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_baseuint((unsigned long long int)var->arg, 8);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (var->modifier[0] == 'h')
			var->arg = ft_itoa_baseuint((unsigned short int)var->arg, 8);
		else if (var->modifier[0] == 'l')
			var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 8);
		else if (var->modifier[0] == 'j')
			var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 8);
		else if (var->modifier[0] == 'z')
			var->arg = ft_itoa_baseuint((size_t)var->arg, 8);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 8);
	return ((var->spec_len = ft_strlen(var->arg)));
}

int		spec_lo(t_var *var)
{
	var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 8);
	var->spec_len = ft_strlen(var->arg);
	return (0);
}

int		spec_u(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_baseuint((unsigned char)var->arg, 10);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_baseuint((unsigned long long int)var->arg, 10);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (var->modifier[0] == 'h')
			var->arg = ft_itoa_baseuint((unsigned short int)var->arg, 10);
		else if (var->modifier[0] == 'l')
			var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 10);
		else if (var->modifier[0] == 'j')
			var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 10);
		else if (var->modifier[0] == 'z')
			var->arg = ft_itoa_baseuint((size_t)var->arg, 10);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 10);
	return ((var->spec_len = ft_strlen(var->arg)));
}

int		spec_lu(t_var *var)
{
	var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 10);
	var->spec_len = ft_strlen(var->arg);
	return (0);
}
