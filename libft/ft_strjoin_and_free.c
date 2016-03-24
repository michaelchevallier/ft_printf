/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:46:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/22 17:46:26 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}
