/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:59:02 by mnaude            #+#    #+#             */
/*   Updated: 2020/02/01 12:09:42 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_minus(char *str, t_struct *s_flags)
{
	int i;

	i = 0;
	while (str && str[i] && ft_check(str[i]) == 1)
	{
		if (str[i] && str[i] == '-' && s_flags->width >= s_flags->point)
			return (45);
		if (str[i] && str[i] == '-' && s_flags->type == 'c')
			return (45);
		if (str[i] && str[i] == '-')
			return (45);
		if (s_flags->width < 0)
			return (45);
		i++;
	}
	return (0);
}

int		ft_zero(char *str, t_struct *s_flags)
{
	int i;

	i = 0;
	while (str && str[i] && ft_check(str[i]) == 1)
	{
		if (str[i] && str[i] == '0' && (str[i - 1] < '0' ||
		str[i - 1] > '9') && ft_minus(str, s_flags) == 0 &&
		ft_checkpoint(str) == 0)
			return (48);
		if (str[i] && str[i] == '0' && (str[i - 1] < '0' ||
		str[i - 1] > '9') && ft_minus(str, s_flags) == 0 &&
		(s_flags->point < 0 && ft_checkpoint(str) == 1))
			return (48);
		i++;
	}
	return (32);
}

int		ft_width(char *str, va_list list)
{
	int i;

	i = 0;
	while (str && str[i] && (str[i] == '0' || str[i] == '-'))
		i++;
	if (str[i] == '*')
		return (ft_get_int(list));
	return (ft_atoi(str + i));
}

int		ft_point(char *str, va_list list)
{
	int i;

	i = 0;
	while (str && str[i] && (ft_check(str[i]) == 1 || ft_check(str[i]) == 2))
	{
		if (str[i] && str[i] == '.')
		{
			i++;
			if (str[i] == '*')
				return (ft_get_int(list));
			return (ft_atoi(str + i));
		}
		i++;
	}
	return (0);
}

char	*ft_conversion(char *str, va_list list, t_struct *s_flags)
{
	int i;

	i = 0;
	while (str && str[i] && (ft_check(str[i]) == 1 || ft_check(str[i]) == 2))
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_itoa(ft_get_int(list)));
	else if (str[i] == 's')
		return (ft_strdup(ft_get_str(list)));
	else if (str[i] == 'c')
		return (ft_ctoa(ft_get_char(list)));
	else if (str[i] == 'u')
		return (ft_utoa(ft_get_unsigned(list)));
	else if (str[i] == 'p')
		return (ft_ptoa(ft_get_pointer(list), s_flags));
	else if (str[i] == 'x')
		return (ft_xtoa(ft_get_unsigned(list), 'x'));
	else if (str[i] == 'X')
		return (ft_xtoa(ft_get_unsigned(list), 'X'));
	else if (str[i] == '%')
		return (ft_strdup("%"));
	return (0);
}
