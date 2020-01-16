/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:56:17 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/16 11:30:07 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_counter(unsigned long nb)
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

char	*ft_ultoa(unsigned long nb)
{
	int		i;
	char	*base;
	char	new[20];

	i = ft_counter(nb);
	base = "0123456789abcdef";
	new[i] = '\0';
	i--;
	while (nb > 0)
	{
		new[i] = base[nb % 16];
		i--;
		nb = nb / 16;
	}
	return (ft_strdup(new));
}

char	*ft_ptoa(unsigned long nb)
{
	char	new[3];

	new[2] = '\0';
	new[0] = '0';
	new[1] = 'x';
	return (ft_strjoin(ft_strdup(new), ft_ultoa(nb)));
}
