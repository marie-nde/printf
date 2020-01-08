/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:55:24 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/08 14:10:24 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_base_low(long n)
{
	char *base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_base_low(n / 16);
	ft_print_char(base[n % 16]);
}

void	ft_base_caps(long n)
{
	char *base;

	base = "0123456789ABCDEF";
	if (n > 15)
		ft_base_caps(n / 16);
	ft_print_char(base[n % 16]);
}

void	ft_print_hexa(int nb, char x)
{
	long n;

	n = nb;
	if (n < 0)
		n = (unsigned)n;
	if (x == 'x')
		ft_base_low(n);
	else if (x == 'X')
		ft_base_caps(n);
}

void	ft_print_address(unsigned long ad)
{
	ft_print_str("0x7ffe");
	ft_print_hexa(ad, 'x');
}
