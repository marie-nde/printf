/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:46:49 by mnaude            #+#    #+#             */
/*   Updated: 2020/01/17 14:46:32 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

int		ft_print_str(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}
