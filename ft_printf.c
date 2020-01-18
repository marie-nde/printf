/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:34:45 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/17 15:49:50 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_flags_together(t_struct *s_flags, char *arg)
{
	char *str;
	char *str2;

	str = NULL;
	str2 = NULL;
	if (s_flags->width > 0 && s_flags->point == 0)
		str = ft_width_only(s_flags, arg, str);
	else if ((s_flags->point > 0 && s_flags->width == 0) || (s_flags->point > 0 && s_flags->width > 0 && s_flags->point >= s_flags->width))
	{
		str = ft_point_regular(s_flags, arg, str);
		if (s_flags->type == 'p')
			arg = ft_ptrcut(arg);
		else
			arg = ft_strcut(arg);
	}
	else if (s_flags->point > 0 && s_flags->width > 0 && s_flags->width > s_flags->point)
	{
		str = ft_more_width(s_flags, arg, str, str2);
		if (s_flags->minus == '-')
			return (ft_strjoin(str, str2));
		return (ft_strjoin(str2, str));
	}
	if (s_flags->minus == '-')
		return (ft_strjoin(arg, str));
	return (ft_strjoin(str, arg));
}

t_struct	*ft_get_flags(t_struct *s_flags, const char *str, va_list list)
{
	int i;

	i = 0;
	s_flags->width = ft_width(str, list);
	s_flags->point = ft_point(str, list);
	s_flags->minus = ft_minus(str, s_flags);
	s_flags->zero = ft_zero(str, s_flags);
	s_flags->conversion = ft_conversion(str, list);
	s_flags->type = ft_type(str);
	if (s_flags->conversion == NULL)
		s_flags->conversion = ft_strdup("(null)");
	return (s_flags);
}

int			ft_printf(const char *str, ...)
{
	t_struct	*s_flags;
	va_list		list;
	int			compt;
	int			i;

	compt = 0;
	i = 0;
	if (!(s_flags = malloc(sizeof(t_struct))))
		return (0);
	va_start(list, str);
	while (str && str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_print_char(str[i++]);
			compt++;
		}
		if (str[i] && str[i] == '%')
		{
			i++;
			s_flags = ft_get_flags(s_flags, str + i, list);
			compt = compt + ft_print_str(ft_flags_together(s_flags, s_flags->conversion));
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
	va_end(list);
	return (compt);
}
