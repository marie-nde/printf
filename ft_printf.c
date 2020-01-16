/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:34:45 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/16 15:02:45 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_flags_together(t_struct *s_flags, char *arg)
{
	int i;
	char *str;
	char *str2;

	i = 0;
	if (s_flags->width > 0 && s_flags->point == 0)
		str = ft_strwidth(arg, s_flags);
	if (s_flags->point > s_flags->width && ft_atoi(arg) >= 0)
		str = ft_strpoint(arg, s_flags);
	if (s_flags->point > s_flags->width && ft_atoi(arg) < 0)
		str = ft_strpoint_minus(arg, s_flags);
	if (s_flags->point > 0 && s_flags->width > s_flags->point)
	{
		if (s_flags->point < 0)
			str = ft_strpoint_minus(arg, s_flags);
		if (s_flags->point >= 0)
			str = ft_strpoint(arg, s_flags);
		s_flags->width = s_flags->width - s_flags->point + 1;
		str2 = ft_strwidth(arg, s_flags);
		str = ft_strjoin(str, arg);
		return (ft_strjoin(str, str2));
	}
	if (s_flags->minus == 45)
		return (ft_strjoin(arg, str));
	return (ft_strjoin(str, arg));
}

t_struct	*ft_get_flags(t_struct *s_flags, const char *str, va_list list)
{
	int i;

	i = 0;
	s_flags->minus = ft_minus(str);
	s_flags->zero = ft_zero(str);
	s_flags->width = ft_width(str, list);
	s_flags->point = ft_point(str, list);
	s_flags->conversion = ft_conversion(str, list);
	return (s_flags);
}

int			ft_printf(const char *str, ...)
{
	va_list		list;
	int			compt;
	t_struct	*s_flags;
	int			i = 0;

	compt = 0;
	i = 0;
	if (!(s_flags = malloc(sizeof(t_struct))))
		return (0);
	va_start(list, str);
	while (str && str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_print_char(str[i]);
			i++;
			compt++;
		}
		if (str[i] && str[i] == '%')
		{
			i++;
			s_flags = ft_get_flags(s_flags, str + i, list);
			ft_print_str(ft_flags_together(s_flags, s_flags->conversion));
			/*compt = compt + ft_strlen(ft_*/
		}
		while (str[i] && ft_check(str[i]) > 0)
		{
			i++;
				if (ft_check_conv(str[i]) == 1)
			{
				i++;
				break ;
			}
		}
	}
	va_end(list);
	return (compt + 1);
}
