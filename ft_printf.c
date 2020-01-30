/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:34:45 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 16:13:29 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_flags_together(t_struct *s_flags, char *arg)
{
	char *width;
	char *precision;

	width = NULL;
	precision = NULL;
	if (s_flags->type == 's')
		ft_is_str(&arg, &width, s_flags);
	else if (s_flags->type == 'c')
		ft_is_char(&arg, &width, s_flags);
	else if (s_flags->type == 'u')
		ft_is_un(&arg, &width, s_flags, &precision);
	else if (s_flags->type == 'p')
		ft_is_pt(&arg, &width, s_flags, &precision);
	else if (s_flags->type == 'x' || s_flags->type == 'X')
		ft_is_x(&arg, &width, s_flags, &precision);
	else if (s_flags->type == 'd' || s_flags->type == 'i')
		ft_is_int(&arg, &width, s_flags, &precision);
	if (s_flags->minus == '-')
		return (ft_strjoin(arg, width, s_flags));
	return (ft_strjoin(width, arg, s_flags));
}

t_struct	*ft_get_flags(t_struct *s_flags, char *str, va_list list)
{
	int i;

	i = 0;
	s_flags->special_char = 0;
	s_flags->type = ft_type(str);
	s_flags->width = ft_width(str, list);
	s_flags->point = ft_point(str, list);
	s_flags->minus = ft_minus(str, s_flags);
	s_flags->zero = ft_zero(str, s_flags);
	s_flags->conversion = ft_conversion(str, list, s_flags);
	s_flags->special_char = ft_special_char(s_flags);
	if (s_flags->conversion == NULL)
		s_flags->conversion = ft_strdup("(null)");
	return (s_flags);
}

int			ft_while(char *str, va_list list, int compt,
t_struct *s_flags)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] != '%')
			compt = compt + ft_print_char(str[i++]);
		if (str[i] && str[i] == '%')
		{
			i++;
			s_flags = ft_get_flags(s_flags, str + i, list);
			compt = compt + ft_print_str(ft_flags_together(s_flags,
s_flags->conversion), s_flags);
		}
		while ((str[i] && ft_check(str[i]) > 0) || ft_check_conv(str[i]) == 1)
		{
			if (ft_check_conv(str[i]) == 1)
			{
				i++;
				break ;
			}
			i++;
		}
	}
	return (compt);
}

int			ft_printf(const char *str, ...)
{
	t_struct	*s_flags;
	va_list		list;
	int			compt;
	char		*s;

	compt = 0;
	s = (char*)str;
	if (!(s_flags = malloc(sizeof(t_struct))))
		return (0);
	va_start(list, str);
	compt = ft_while(s, list, compt, s_flags);
	va_end(list);
	free(s_flags);
	return (compt);
}
