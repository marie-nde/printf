/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:52:04 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/31 15:54:02 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_hexa(unsigned nb)
{
	int compt;

	compt = 0;
	if ((nb > 0 && nb < 10) || nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		compt++;
	}
	return (compt);
}

char	*ft_base_caps(unsigned nb, int i)
{
	char *base;
	char str[30];

	base = "0123456789ABCDEF";
	str[i] = '\0';
	i--;
	if (nb == 0)
	{
		str[i] = '0';
		return (ft_strdup(str));
	}
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (ft_strdup(str));
}

char	*ft_base_low(unsigned nb, int i)
{
	char *base;
	char str[30];

	base = "0123456789abcdef";
	str[i] = '\0';
	i--;
	if (nb == 0)
	{
		str[i] = '0';
		return (ft_strdup(str));
	}
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (ft_strdup(str));
}

char	*ft_xtoa(unsigned int n, char x)
{
	int	i;

	i = ft_count_hexa(n);
	if (x == 'x')
		return (ft_base_low(n, i));
	return (ft_base_caps(n, i));
}
