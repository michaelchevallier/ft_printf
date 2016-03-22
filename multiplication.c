/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:13:35 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/15 17:26:14 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void	multiplication(int *resultat, ...)
{
	int		parametre;
	va_list 	ap;

	parametre = 1;
	*resultat = 1;
	va_start(ap, resultat);
	while (parametre)
	{
		*resultat *= parametre;
		parametre = va_arg(ap,int);
	}
	va_end(ap);
}

int main(void)
{
	int *toto;

	*toto = 0;
	multiplication(toto, 5, 5, 5);
	printf ("%d\n", *toto);

	return (0);
}
