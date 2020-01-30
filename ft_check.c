/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:07:24 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/30 14:42:55 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check(char c)
{
	if (c == '0' || c == '-' || c == '.' || c == '*')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

int		ft_checkpoint(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && (ft_check(str[i]) == 1 || ft_check(str[i]) == 2))
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_conv(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'
	|| c == 'p' || c == 'c' || c == '%')
		return (1);
	return (0);
}
