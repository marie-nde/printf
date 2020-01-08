/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:29:32 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/08 15:34:06 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i] >= 0 && str[i] <= 9)
	{
		nb = nb + (str[i] + '0');
		nb = nb * 10;
		i++;
	}
	return (nb);
}

void	ft_fill(char c, int len)
{
	int compt;

	compt = 0;
	while (compt < len)
	{
		ft_print_char(c);
		compt++;
	}
}
