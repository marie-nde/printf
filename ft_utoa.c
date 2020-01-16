/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:37:44 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/16 11:44:10 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_unsigned(unsigned int nb)
{
	int compt;

	compt = 0;
	if (nb > 0 && nb < 10)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		compt++;
	}
	return (compt);
}

char	*ft_utoa(unsigned int nb)
{
	int		i;
	char	new[20];

	i = ft_count_unsigned(nb);
	new[i] = '\0';
	i--;
	while (nb > 0)
	{
		new[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (ft_strdup(new));
}
