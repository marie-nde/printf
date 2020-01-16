/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:52:04 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/16 11:51:48 by mnaude           ###   ########.fr       */
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

char	*ft_base_caps(long nb, int i)
{
	char *base;
	char str[30];

	base = "0123456789ABCDEF";
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (ft_strdup(str));
}

char	*ft_base_low(long nb, int i)
{
	char *base;
	char str[30];

	base = "0123456789abcdef";
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (ft_strdup(str));
}

char	*ft_xtoa(int n, char x)
{
	long	nb;
	int		i;

	nb = n;
	if (nb < 0)
		nb = (unsigned)nb;
	i = ft_count_hexa(nb);
	if (x == 'x')
		return (ft_base_low(nb, i));
	return (ft_base_caps(nb, i));
}
