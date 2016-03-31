/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:37:15 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 18:20:13 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# define NB_FLAGS 5
# define FS format_specifier
# define FLAGS "#0 +-"
# define MODIFIER "hljz"
# define SPECIFIER "sSpdDioOuUxXcC"
//% [drapeaux] [largeur] [.precision] [modificateur] type
typedef struct			s_var
{
	void			*arg;
	unsigned char	*str;
	char			*format_specifier;
	char			*modifier;
	char			*tmp;
	int				*flags;
	int				counter;
	int				specifier;
	int				width;
	int				error;
	int				precision;
	int				mod_len;
	int				spec_len;
}						t_var;

typedef struct			s_wchar
{
	size_t	nbchar;
	char	*bin;
	int		binlen;
	int		index;
	int		*wchar;
	int		tmpresult;
}						t_wchar;

int		ft_printf(const char *format, ...);
int		specifier_finder(const char *format, t_var *var, int i, va_list ap);
void	format_specifier_manager(t_var *var);
void	var_initializer(t_var *var);
int		spec_s(t_var *var);
int		spec_ls(t_var *var);
int		spec_p(t_var *var);
int		spec_d(t_var *var);
int		spec_ld(t_var *var);
int		spec_i(t_var *var);
int		spec_o(t_var *var);
int		spec_lo(t_var *var);
int		spec_u(t_var *var);
int		spec_lu(t_var *var);
int		spec_x(t_var *var);
int		spec_lx(t_var *var);
int		spec_c(t_var *var);
int		spec_lc(t_var *var);
void	ft_putwchar(int *wchar);
t_wchar	*wchar_manager(t_var *var);
t_wchar	*wstr_manager(wchar_t str);
char	*chartostring(int c);
char	*wchartostring(t_wchar *wchar);
#endif
