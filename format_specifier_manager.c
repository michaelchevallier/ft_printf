/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:49:49 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 14:58:05 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			remove_flags(t_var *var)
{
	if (ft_strchr("sSdDiuUcC", SPECIFIER[var->specifier]) != NULL)
		var->flags[0] = 0;
	if (var->flags[4] == 1 && var->flags[1] == 1)
		var->flags[1] = 0;
	if (var->precision != -1 &&
			ft_strchr("dDiouUxX", SPECIFIER[var->specifier]) != NULL)
		var->flags[1] = 0;
	if (var->flags[2] == 1 && var->flags[3] == 1)
		var->flags[2] = 0;
	if (var->flags[2] == 1 &&
			ft_strchr("deEfgGi", SPECIFIER[var->specifier]) == NULL)
		var->flags[2] = 0;
	return (0);
}

static int			valid_flags(t_var *var)
{
	int		i;
	int		j;
	int		nb_flags;

	i = 0;
	j = 0;
	nb_flags = 0;
	while (var->format_specifier[j])
	{
		while (i < NB_FLAGS)
		{
			if (var->format_specifier[j] == FLAGS[i])
			{
				var->flags[i] = 1;
				i = -1;
				nb_flags++;
				j++;
			}
			i++;
		}
		j++;
	}
	return (nb_flags);
}

static int			is_modifier(t_var *var, int counter)
{
	int			i;

	i = 0;
	while (var->FS[counter + i] != '\0')
	{
		if (ft_strchr(MODIFIER, var->FS[counter + i]) != NULL)
			var->modifier = ft_strjoin_and_free
(var->modifier, ft_strsub(var->FS, counter + i, 1), 0);
		else
			return ((var->error = -6));
		i++;
	}
	if ((var->mod_len = ft_strlen(var->modifier)) > 2)
		return ((var->error = -7));
	if (var->mod_len == 2)
	{
		if (var->modifier[0] != 'h' && var->modifier[0] != 'l')
			return ((var->error = -8));
		if ((var->modifier[0] == 'h' && var->modifier[1] != 'h') ||
			(var->modifier[0] == 'l' && var->modifier[1] != 'l'))
			return ((var->error = -9));
	}
	return (1);
}

void				format_specifier_manager(t_var *var)
{
	int			counter;

	counter = 0;
	var->tmp = var->format_specifier;
	counter = valid_flags(var);
	var->width = ft_atoi(&var->FS[counter]);
	if (var->width > 0)
		counter += ft_strlen(ft_itoa(var->width));
	if (var->FS[counter] == '.')
	{
		var->precision = ft_atoi(&var->FS[counter + 1]);
		counter += 1 + ft_strlen(ft_itoa(var->precision));
	}
	is_modifier(var, counter);
	remove_flags(var);
}
