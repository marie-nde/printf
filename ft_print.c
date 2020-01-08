/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:46:49 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/08 13:28:34 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
}

void	ft_print_nbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n > 9)
		ft_print_nbr(n / 10);
	ft_print_char((n % 10) + '0');
}

void	ft_print_unsigned(unsigned int nb)
{
	if (nb > 9)
		ft_print_unsigned(nb / 10);
	ft_print_char((nb % 10) + '0');
}
