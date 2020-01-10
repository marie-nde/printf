/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:52:04 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/10 11:35:54 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_hexa(long nb)
{
	int compt;

	compt = 0;
	if (nb > 0 && nb < 10)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		compt++;
	}
	return (compt);
}

char	*ft_base_caps(long nb, char *str, int i)
{
	char *base;

	base = "0123456789ABCDEF";
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (str);
}

char	*ft_base_low(long nb, char *str, int i)
{
	char*base;

	base = "0123456789abcdef";
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (str);
}

char	*ft_xtoa(int n, char x)
{
	long	nb;
	char	*str;
	int		i;

	nb = n;
	if (nb < 0)
		nb = (unsigned)nb;
	i = ft_count_hexa(nb);
	if (x == 'x')
		str = ft_base_low(nb, str, i);
	if (x == 'X')
		str = ft_base_caps(nb, str, i);
	return (ft_strdup(str));
}
