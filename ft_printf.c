/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:34:45 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/10 16:09:22 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_regular(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != '%')
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

t_struct	*ft_get_flags(t_struct *s_flags, const char *str, va_list list)
{
	int i;

	i = 0;
	s_flags->minus = ft_minus(str);
	s_flags->zero = ft_zero(str, list);
	s_flags->width = ft_width(str, list);
	s_flags->point = ft_point(str, list);
	s_flags->conversion = ft_conversion(str);
	return (s_flags);
}

int			ft_printf(const char *str, ...)
{
	va_list		list;
	int			compt;
	t_struct	*s_flags;

	compt = 0;
	if (!(s_flags = malloc(sizeof(t_struct))))
		return (0);
	va_start(list, str);
	compt = ft_print_regular(str) + 1;
	s_flags = ft_get_flags(s_flags, str + compt, list);
	printf("minus %c\n", s_flags->minus);
	printf("zero %c\n", s_flags->zero);
	printf("width %d\n", s_flags->width);
	printf("point %d\n", s_flags->point);
	printf("conv %c\n", s_flags->conversion);
	va_end(list);
	return (compt);
}
