/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:59:02 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/10 16:12:14 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_minus(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] && ft_check(str[i]) == 1 && ft_checkpoint(str) == 0)
	{
		if (str[i] && str[i] == '-')
			return (45);
		i++;
	}
	return (0);
}

int		ft_zero(const char *str, va_list list)
{
	int i;

	i = 0;
	while (str && str[i] && ft_check(str[i]) == 1)
	{
		if (str[i] && str[i] == '0' && (str[i - 1] < '0' ||
		str[i - 1] > '9') && ft_minus(str) == 0 && ft_checkpoint(str) == 0)
			return (48);
		i++;
	}
	return (0);
}

int		ft_width(const char *str, va_list list)
{
	int i;

	i = 0;
	while (str && str[i] && (str[i] == '0' || str[i] == '-'))
		i++;
	if (str[i] == '*')
		return (ft_get_int(list));
	return (ft_atoi(str + i));
}

int		ft_point(const char *str, va_list list)
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

int		ft_conversion(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] && (ft_check(str[i]) == 1 || ft_check(str[i]) == 2))
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		return (100);
	else if (str[i] == 's')
		return (115);
	else if (str[i] == 'c')
		return (99);
	else if (str[i] == 'u')
		return (117);
	else if (str[i] == 'p')
		return (112);
	else if (str[i] == 'x')
		return (120);
	else if (str[i] == 'X')
		return (88);
	else if (str[i] == '%')
		return (37);
	return (0);
}
