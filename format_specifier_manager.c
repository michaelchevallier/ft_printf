/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:49:49 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/24 19:52:14 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			remove_flags(t_var *var)
{
	if (ft_strchr("sSdDiuUcCnp", SPECIFIER[var->specifier]) != NULL)
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
	int			j;

	i = 0;
	j = 0;
	while (var->FS[counter + i] != '\0')
	{
		if (ft_strchr(MODIFIER, var->FS[counter + i]) != NULL)
			var->modifier = ft_strjoin_and_free
(var->modifier, ft_strsub(var->FS, counter + i, 1));
		else
			return (-1);
		i++;
	}
	if (ft_strlen(var->modifier) > 2)
		return (-1);
	if (ft_strlen(var->modifier) == 2)
	{
		if (var->modifier[0] != 'h' || var->modifier[0] != 'l')
			return (-1);
		if ((var->modifier[0] == 'h' && var->modifier[1] != 'h') ||
			(var->modifier[0] == 'l' && var->modifier[1] != 'l'))
			return (-1);
	}
	return (1);
}

void				format_specifier_manager(t_var *var)
{
	int			counter;
	int			i;

	counter = 0;
	i = 0;
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
	if (ft_strlen(&var->FS[counter]) > 0)
	{
		if (is_modifier(var, counter) == -1)
			var->error = -1;
	}
	remove_flags(var);
}
